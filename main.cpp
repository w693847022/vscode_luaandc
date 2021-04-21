#include<iostream>
#include<LuaTest.hpp>
#include<Windows.h>
#include<timer_w.h>
using namespace std;
void Timer_test_cd()
{
    cout<<"Timer_test_cd doing!"<<endl;
}
void main()
{
    Timer_w TimerManager;
    
    Timer_s t1;
    TimerManager.Timer_init(t1,1);
    TimerManager.Timer_start(t1,0,10,1000,Timer_test_cd);
    //主循环
    while(true)
    {
        TimerManager.Timer_run();
    }
    cout<<"main end!"<<endl;
    getchar();
}