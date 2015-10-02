#ifndef SSTREAMPOOL_H
#define SSTREAMPOOL_H

#include <sstream>
#include <list>
#include <new>

class SStreamPool {
    public:
        static SStreamPool& getInstanceWithPoolSize(const int poolSize);
        std::stringstream* getSStream();
        void putSStream(std::stringstream *&sstream);
        ~SStreamPool();
    private:
        SStreamPool(const int poolSize);
        SStreamPool() {}

        static std::list<std::stringstream*> idleStreams_;
        static pthread_mutex_t idleStreamsMutex_;
        static SStreamPool *this_;
};

#endif
