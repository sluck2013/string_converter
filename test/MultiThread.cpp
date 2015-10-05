#include "../string_concat.h"
#include <pthread.h>

#include "catch.hpp"
#include <vector>
#include <cstdio>

using namespace std;

pthread_barrier_t barrier;

void *testSingleConcat(void* threadId) {
    long tid = (long) threadId;
    int randNum = rand();
    string s = "test_thread";
    char buffer[100];
    snprintf(buffer, 100, "test_thread%d%ld", randNum, tid);
    string expected(buffer);

    pthread_barrier_wait(&barrier);
    REQUIRE(((s + randNum) + tid) == expected);
    return 0;
}

TEST_CASE("concurrency test", "[concurrency]") {
    srand(time(NULL));
    const int threadNum = 500;
    pthread_t threads[threadNum];
    pthread_barrier_init(&barrier, NULL, threadNum);

    for (int i = 0; i < threadNum; ++i) {
        int rc = pthread_create(&threads[i], NULL, testSingleConcat, (void*)i);
        if (rc) {
            FAIL("thread creation failed!");
        }
    }

    for (int i = 0; i < threadNum; ++i) {
        pthread_join(threads[i], NULL);
    }
}


