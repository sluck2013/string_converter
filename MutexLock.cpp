#include "MutexLock.h"

MutexLock::MutexLock(pthread_mutex_t* mutex) : mutex_(mutex) {
    if (!mutex) {
        //error
    }

    pthread_mutex_lock(mutex_);
};

MutexLock::~MutexLock() {
    pthread_mutex_unlock(mutex_);
}
