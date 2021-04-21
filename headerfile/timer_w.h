#include<Windows.h>
#include<vector>
#include<iostream>
using namespace std;
struct Timer_s;
typedef void (*timer_cb)(Timer_s);//计时器回调的函数指针
enum TimerState{
    work,
    stop,
};
struct Timer_s{
    int timer_id;//计时器id 唯一
    UINT64 timeout;//从加入的第多少毫秒开始
    int repeat;//重复次数
    UINT64 interval;//间隔
    timer_cb cb;//void 回调函数 (Timer_s)
    TimerState state;
};

class Timer_w{
public:
    Timer_w();
    ~Timer_w();
public:
    //获取当前的时间
    UINT64 GetCurTime(unsigned int scale);
    //初始化计时器
    const Timer_s& Timer_init(Timer_s &timer,int timer_id);
    //添加计时器
    void Timer_start(Timer_s &timer,UINT64 timerout,int repeat,UINT64 interval,timer_cb cb);
    //停止计时器
    void Timer_stop(Timer_s &timer);
    //是否存在计时器 存在返回
    const Timer_s* const Timer_exists(int timer_id);
    //计时器主循环
    void Timer_run();
private:
    //清理无用的计时器
    void Timer_clear();
    //计时器更新
    void Timer_update(Timer_s& timer);
    //重启定时器
    void Timer_again(Timer_s &timer,UINT64 timerout,int repeat,UINT64 interval,timer_cb cb);
private:
    vector<Timer_s> timerList;//计时器列表
    UINT64 frequency;
};