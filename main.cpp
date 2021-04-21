#include<iostream>
#include<LuaTest.hpp>
#include<Windows.h>
#include<timer_w.h>
using namespace std;
void Timer_test_cd(Timer_s timer)
{
    static int count = 1;
    cout<<"Timer_test_cd doing! "<<(count++)<<endl;
}
void Timer_test_cd2(Timer_s timer)
{
    cout<<"Timer_test_cd2 doing! "<<endl;
}
void main()
{
    Timer_w TimerManager;
    
    Timer_s t1;
    TimerManager.Timer_init(t1,1);
    TimerManager.Timer_start(t1,0,10,1000,Timer_test_cd);

    Timer_s t2;
    TimerManager.Timer_init(t2,2);
    TimerManager.Timer_start(t2,2000,2,2000,Timer_test_cd2);

    //主循环
    while(true)
    {
        TimerManager.Timer_run();
    }
    cout<<"main end!"<<endl;
    getchar();
}