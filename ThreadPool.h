#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <pthread.h>
#include <queue>
#include <vector>
#include "Task.h"
#include "Thread.h"
class Thread;
using namespace std;
class ThreadPool
{
public:
	ThreadPool(int num_of_threads);
	ThreadPool();
	~ThreadPool();
	static queue<Task*> taskQueue;
	static vector<Thread*> threadVector;
	static void addTask(Task* task);
	static void lock();
	static void unlock();
	static void wait();
	static void signal();

private:
	static pthread_mutex_t mutex;
	static pthread_cond_t cond;
	int num_of_threads;
};



#endif