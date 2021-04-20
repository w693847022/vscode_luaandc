#include<iostream>
#include<LuaTest.hpp>
#include<Windows.h>
using namespace std;
static uint64_t frequency;
void main()
{
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);
    frequency = counter.QuadPart;
    SYSTEMTIME systime;
    // LuaTest test;
    // test.Test_1();
    int i = 10000000;
    while(true)
    {
        GetLocalTime(&systime);

        // if(!(i%100))
        // {
            QueryPerformanceCounter(&counter);
            double scaled_freq = (double)frequency/100000;
            uint64_t count = (double)(counter.QuadPart/scaled_freq);
            // if((count%10)==0)
            // {
            //     cout<<count<<" time:"<<systime.wSecond<<endl;
            //     //cout<<systime.wSecond<<":"<<" test QueryPerformanceCounter:"<< (double)(counter.QuadPart/scaled_freq)<<endl;
            // }
        //}
        i--;
    }
    getchar();
}