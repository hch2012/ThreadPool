#ifndef THREAD_H
#define THREAD_H
#include "ThreadPool.h"
class Thread
{
public:
	Thread();
	~Thread();

	pthread_t* getPid();
	bool isShutdown();
private:
	pthread_t pid;
	bool shutdown;
    //friend void * run(void * arg);
};


#endif