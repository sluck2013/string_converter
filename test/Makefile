CC = g++
WLEVEL = -Wall
OBJ_DIR = ../obj

all:SingleThread

SingleThread: catch.hpp string_concat.cpp SingleThread.cpp ../string_concat.h $(OBJ_DIR)/SStreamPool.o $(OBJ_DIR)/MutexLock.o
	$(CC) -o $@ string_concat.cpp SingleThread.cpp $(OBJ_DIR)/*.o

$(OBJ_DIR)/SStreamPool.o: ../SStreamPool.cpp ../SStreamPool.h
	$(CC) $(WLEVEL) -c -o $@ $<

$(OBJ_DIR)/MutexLock.o: ../MutexLock.cpp ../MutexLock.h
	$(CC) $(WLEVEL) -c -o $@ $<

clean:
	@rm -f SingleThread $(OBJ_DIR)/*.o
