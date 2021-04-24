#include<stdafx.h>
using namespace std;

mutex ioLock;//线程io锁 慢一点
CRITICAL_SECTION csIOLock;//cs的io锁 快一点

void TreadPrintf(const char* content)
{
    //ioLock.lock();
    EnterCriticalSection(&csIOLock);
    cout<<content<<endl;
    cout.clear();
    LeaveCriticalSection(&csIOLock);
    //ioLock.unlock();
}

