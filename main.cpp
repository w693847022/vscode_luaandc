#include<iostream>
#include<LuaTest.hpp>
#include<Windows.h>
#include<timer_w.h>
#include<thread>
#include<mutex>
using namespace std;
mutex ioLock;//线程io锁 慢一点
CRITICAL_SECTION csIOLock;//cs的io锁 快一点
int count1 = 1;

void TreadPrintf(const char* content)
{
    //ioLock.lock();
    EnterCriticalSection(&csIOLock);
    cout<<content<<endl;
    cout.clear();
    LeaveCriticalSection(&csIOLock);
    //ioLock.unlock();
}
void Timer_test_cb(Timer_s timer)
{
    char msg[50] = "";
    sprintf_s(msg,"Timer_test_cd doing! %d",(count1++));
    msg[strlen(msg)] = '\0';
    TreadPrintf(msg);
}
void Timer_test_cb2(Timer_s timer)
{
    TreadPrintf("Timer_test_cd2 doing! ");
}
void Timer_test_cb3(Timer_s timer)
{
    TreadPrintf("Timer_test_cd3 doing!");
}
void TimerTest1()
{
    Timer_w TimerManager;
    
    Timer_s t1;
    TimerManager.Timer_init(t1,1);
    TimerManager.Timer_start(t1,0,10,1000,Timer_test_cb);

    Timer_s t2;
    TimerManager.Timer_init(t2,2);
    TimerManager.Timer_start(t2,2000,2,2000,Timer_test_cb2);

    //主循环
    while(true)
    {
        TimerManager.Timer_run();
    }
    TreadPrintf("main 1 end!");
}
void TimerTest2()
{

    Timer_w TimerManager;
    Timer_s t1;
    TimerManager.Timer_init(t1,1);
    TimerManager.Timer_start(t1,1000,10,1000,Timer_test_cb3);
    //主循环
    while(true)
    {
        TimerManager.Timer_run();
    }
    TreadPrintf("main 2 end!");
}
void main()
{
    //初始化 csIO 互斥锁
    InitializeCriticalSection(&csIOLock);
    thread th1(TimerTest1);
    thread th2(TimerTest2);
    th1.join();
    th2.join();


    getchar();
}