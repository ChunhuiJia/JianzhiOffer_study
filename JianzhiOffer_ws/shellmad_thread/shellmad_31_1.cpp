//自己封装线程同步锁，构造函数进行初始化锁，析构函数删除锁，防止忘记删除锁
class CMyMutex
{
public:
    CMyMutex()
    {
        //使用前，需要对该对象进行初始化
        InitializeCriticalSection(&m_cs);
    }

    ~CMyMutex()
    {
        //当不在使用该锁时，需要将锁删除
        DeleteCriticalSection(&m_cs);
    }

    void lock()
    {
        //进去上锁
        EnterCriticalSection(&m_cs);
    }

    void unlock()
    {
        //出去解锁
        LeaveCriticalSection(&m_cs);
    }

private:
    CRITICAL_SECTION m_cs; //CRITICAL_SECTION windows里创建锁对象的api
};

class CMyLockGuard
{
public:
    CMyLockGuard(CMyMutex &mtx)
        : m_Mutex(mtx)
    {
        m_Mutex.lock();
    }

    ~CMyLockGuard()
    {
        m_Mutex.unlock();
    }

private:
    CMyMutex &m_Mutex; //一定要用引用对象，如果CMyMutex m_Mutex，则会创建多个CMyMutex锁对象
}