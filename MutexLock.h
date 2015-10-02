#ifndef MUTEXLOCK_H
#define MUTEXLOCK_H

#include <pthread.h>

class MutexLock {
    public:
        explicit MutexLock(pthread_mutex_t* mutex);
        ~MutexLock();
    private:
        pthread_mutex_t *mutex_;

};

#endif
