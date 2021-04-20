#include<iostream>
#include<LuaTest.hpp>
#include<Windows.h>
using namespace std;
static uint64_t frequency;
void main()
{
    //使用滴答数进行计时
    LARGE_INTEGER counter;
    QueryPerformanceFrequency(&counter);//每秒滴答数
    frequency = counter.QuadPart;
    cout<<"frequency:"<<counter.QuadPart<<endl;//10000000 微妙级
    SYSTEMTIME systime;
    int i = 10000000;
    //主循环
    while(true)
    {
        GetLocalTime(&systime);
        QueryPerformanceCounter(&counter);
        double scaled_freq = (double)frequency/1000;//转成毫秒级
        uint64_t count = (double)(counter.QuadPart/scaled_freq);//当前滴答数/每秒滴答数
        cout<<systime.wSecond<<" "<<count<<endl;//和当前时间一致
        i--;
    }
    getchar();
}