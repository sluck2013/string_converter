CC = g++
OBJ_DIR = obj
WLEVEL = -Wall

all: driver 

driver: driver.cpp $(OBJ_DIR)/MutexLock.o $(OBJ_DIR)/SStreamPool.o
	$(CC) $(WLEVEL) -o driver driver.cpp $(OBJ_DIR)/*.o

libsconv.a: string_concat.h $(OBJ_DIR)/MutexLock.o $(OBJ_DIR)/SStreamPool.o
	ar rcs $@ $^

$(OBJ_DIR)/MutexLock.o: MutexLock.cpp MutexLock.h
	$(CC) $(WLEVEL) -c -o $@ $<

$(OBJ_DIR)/SStreamPool.o: SStreamPool.cpp SStreamPool.h
	$(CC) $(WLEVEL) -c -o $@ $<

clean:
	@rm -f $(OBJ_DIR)/* libsconv.a driver
