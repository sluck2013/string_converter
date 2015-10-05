#ifndef SSTREAMPOOL_H
#define SSTREAMPOOL_H

#include <sstream>
#include <vector>
#include <new>
#include <pthread.h>

class SStreamPool {
    public:
        static SStreamPool& getInstanceWithPoolSize(const int poolSize);
        std::stringstream* getSStream();
        void putSStream(std::stringstream *&sstream);
        ~SStreamPool();
    private:
        class SStream {
            public:
                std::stringstream *stream;
                pthread_mutex_t streamLock;
        }

        SStreamPool(const int poolSize);
        SStreamPool() {}

        std::vector<SStream> idleStreams_;
        pthread_mutex_t idleStreamsMutex_;
        static SStreamPool *this_;
};

#endif
