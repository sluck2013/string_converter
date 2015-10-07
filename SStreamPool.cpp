#include "SStreamPool.h"
#include "SStream.h"
#include "MutexLock.h"
#include <iostream>
#include <vector>

SStreamPool* SStreamPool::this_ = NULL;

SStreamPool& SStreamPool::getInstanceWithPoolSize(const int poolSize) {
    if (!this_) {
        this_ = new SStreamPool(poolSize);
    }
    
    return *this_;
};

SStream* SStreamPool::getSStream() {
    std::vector<SStream*>::iterator it = idleStreams_.begin();
    for (; it != idleStreams_.end(); ++it) {
        if (pthread_mutex_trylock(&((*it)->streamLock)) == 0) {
            return *it;
        }
    }

    MutexLock idleStreamsLock(&idleStreamsMutex_);
    SStream *sstream = new SStream();
    idleStreams_.push_back(sstream);
    return sstream;
}

void SStreamPool::putSStream(SStream *&sstream) {
    pthread_mutex_unlock(&sstream->streamLock);
    sstream = NULL;
}

SStreamPool::~SStreamPool() {
    std::vector<SStream*>::iterator streamIt = idleStreams_.begin();
    for ( ; streamIt != idleStreams_.end(); ++streamIt) {
        delete *streamIt;
    }
}

SStreamPool::SStreamPool(const int poolSize) {
    for (int i = 0; i < poolSize; ++i) {
        SStream *sstream = new SStream();
        idleStreams_.push_back(sstream);
    }

    int r = pthread_mutex_init(&idleStreamsMutex_, NULL);
    if (r != 0) {
        //error
    }
}


