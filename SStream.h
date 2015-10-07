#ifndef SSTREAM_H
#define SSTREAM_H

#include <sstream>
#include <pthread.h>
#include "SStreamPool.h"

class SStreamPool;

class SStream {
    public:
        SStream() {
            int r = pthread_mutex_init(&SStreamPool::idleStreamsMutex_, NULL);
            if (r != 0) {
                //error
            }
        }
        std::stringstream stream;
        pthread_mutex_t streamLock;
};

#endif
