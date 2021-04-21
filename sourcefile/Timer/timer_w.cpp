#include"timer_w.h"


Timer_w::Timer_w(){
    LARGE_INTEGER counter;
    QueryPerformanceFrequency(&counter);//每秒滴答数
    frequency = counter.QuadPart;
}
Timer_w::~Timer_w(){
    frequency = 0;
    timerList.clear();
}
//初始化计时器
const Timer_s& Timer_w::Timer_init(Timer_s &timer,int timer_id){
    timer.timer_id = timer_id;
    timer.cb = NULL;
    timer.interval = 0;
    timer.repeat = 0;
    timer.timeout = 0;
    timer.state = TimerState::stop;
    //cout<<"timer id:"<<timer_id<<" init"<<endl;
    return timer;
}
//获取当前的时间
UINT64 Timer_w::GetCurTime(unsigned int scale){
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    double scaled_freq = (double)frequency/scale;
    uint64_t count = (double)(counter.QuadPart/scaled_freq);//当前滴答数/每秒滴答数
    return count;
}

//添加计时器
void Timer_w::Timer_start(Timer_s &timer,UINT64 timerout,int repeat,UINT64 interval,timer_cb cb){
    if(!timer.timer_id || timer.timer_id == 0)
    {
        cout<<"timer not init"<<endl;
        return;
    }
    timer.cb = cb;
    timer.interval = interval;
    timer.repeat = repeat;
    timer.timeout = timerout+GetCurTime(1000);
    timer.state = TimerState::work;
    timerList.push_back(timer);
    //cout<<"timer id:"<<timer.timer_id<<" start"<<endl;
}

//停止计时器
void Timer_w::Timer_stop(Timer_s& timer){
    if(Timer_exists(timer.timer_id))
    {
        timer.state = TimerState::stop;
        //cout<<"timer id:"<<timer.timer_id<<" stop"<<endl;
    }
}

//重启定时器
void Timer_w::Timer_again(Timer_s &timer,UINT64 timerout,int repeat,UINT64 interval,timer_cb cb){
    if(Timer_exists(timer.timer_id))
    {
        timer.cb = cb;
        timer.interval = interval;
        timer.repeat = repeat;
        timer.timeout = timerout+GetCurTime(1000);
        timer.state = TimerState::work;
        //cout<<"timer id:"<<timer.timer_id<<" again"<<endl;
    }
}

//是否存在计时器 存在返回
const Timer_s* const Timer_w::Timer_exists(int timer_id){
    std::vector<Timer_s>::iterator it;
    it = timerList.begin();
    for(;it!=timerList.end();it++)
    {
        if(it._Ptr->timer_id == timer_id)
        {
            return it._Ptr;
        }
    }
    return NULL;
}

//计时器更新
void Timer_w::Timer_update(Timer_s& timer){
    UINT64 time = GetCurTime(1000);
    if(timer.timeout > time || timer.state == TimerState::stop)
    {
        return;
    }
    Timer_stop(timer);
    timer.repeat--;
    if(timer.repeat>0)
    {
        Timer_again(timer,timer.interval,timer.repeat,timer.interval,timer.cb);
    }
    timer.cb(timer);
}

//计时器主循环
void Timer_w::Timer_run(){
    if(timerList.size()<=0)
    {
        return;
    }
    std::vector<Timer_s>::iterator it;
    it = timerList.begin();
    for(;it!=timerList.end();it++)
    {
        Timer_update(*it._Ptr);
    }
    Timer_clear();
}

void Timer_w::Timer_clear(){
    if(timerList.size()<=0)
    {
        return;
    }
    std::vector<Timer_s>::iterator it;
    it = timerList.begin();
    for(;it!=timerList.end();it++)
    {
        if(it._Ptr->state == TimerState::stop)
        {
            timerList.erase(it);
            it--;
        }
    }
}