#include "SStreamPool.h"
#include "MutexLock.h"
#include <iostream>
#include <vector>

//std::list<std::stringstream*> SStreamPool::idleStreams_ = std::list<std::stringstream*>();
//pthread_mutex_t SStreamPool::idleStreamsMutex_ = pthread_mutex_t();
SStreamPool* SStreamPool::this_ = NULL;

SStreamPool& SStreamPool::getInstanceWithPoolSize(const int poolSize) {
    if (!this_) {
        this_ = new SStreamPool(poolSize);
    }
    
    return *this_;
};

std::stringstream* SStreamPool::getSStream() {
    MutexLock idleStreamsLock(&idleStreamsMutex_);

    if (idleStreams_.empty()) {
        std::stringstream *sstream = new std::stringstream();
        return sstream;
    } else {
        std::stringstream *sstream = idleStreams_.back();
        idleStreams_.pop_back();
        return sstream;
    }

    std::vector<std::stringstream>::iterator it = idleStreams_.begin();
    for (; it != idleStreams_.end(); ++it) {
        if (pthread_mutex_trylock(&idleStreamsMutex_) == 0) {
            
        }
    }
}

void SStreamPool::putSStream(std::stringstream *&sstream) {
    MutexLock idleStreamsLock(&idleStreamsMutex_);
    idleStreams_.push_back(sstream);
    sstream = NULL;
}

SStreamPool::~SStreamPool() {
    std::list<std::stringstream*>::iterator streamIt = idleStreams_.begin();
    for ( ; streamIt != idleStreams_.end(); ++streamIt) {
        delete *streamIt;
    }
}

SStreamPool::SStreamPool(const int poolSize) {
    for (int i = 0; i < poolSize; ++i) {
        std::stringstream *sstream = new std::stringstream();
        idleStreams_.push_back(sstream);
    }
    int r = pthread_mutex_init(&idleStreamsMutex_, NULL);
    if (r != 0) {
        //error
    }
}


