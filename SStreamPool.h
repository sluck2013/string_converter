#ifndef SSTREAMPOOL_H
#define SSTREAMPOOL_H

#include <sstream>
#include <vector>
#include <new>
#include <pthread.h>

/*class SStream {
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
*/

class SStream;
class SStreamPool {
    public:

        static SStreamPool& getInstanceWithPoolSize(const int poolSize);
        SStream* getSStream();
        void putSStream(SStream *&sstream);
        ~SStreamPool();
        static pthread_mutex_t idleStreamsMutex_;
    private:
        SStreamPool(const int poolSize);
        SStreamPool() {}

        std::vector<SStream*> idleStreams_;
        static SStreamPool *this_;
};

#endif
