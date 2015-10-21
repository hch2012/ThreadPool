#include "Thread.h"

void* run(void* arg) {
    Thread * this_thread = static_cast<Thread*>(arg);
    while(!this_thread->isShutdown()){
        ThreadPool::lock();
        if(ThreadPool::taskQueue.empty()){
            ThreadPool::wait();
        }
        Task* task=ThreadPool::taskQueue.front();
        
        ThreadPool::taskQueue.pop();
        ThreadPool::unlock();
        task->run();
    }
    return NULL;
}

Thread::Thread(){
    shutdown=false;
	int e=pthread_create(&(this->pid), NULL,run,this);
}

Thread::~Thread(){

}
pthread_t* Thread::getPid(){
	return &pid;
}

bool Thread::isShutdown(){
	return shutdown;
}