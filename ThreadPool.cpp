#include "ThreadPool.h"

pthread_mutex_t ThreadPool::mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t ThreadPool::cond=PTHREAD_COND_INITIALIZER;
queue<Task*> ThreadPool::taskQueue;
vector<Thread*> ThreadPool::threadVector;
ThreadPool::ThreadPool(int num_of_threads){
	this->num_of_threads=num_of_threads;
	for(int i=0;i<num_of_threads;i++){
		threadVector.push_back(new Thread());
	}
}
ThreadPool::ThreadPool(){
	this->num_of_threads=5;
	for(int i=0;i<num_of_threads;i++){
		threadVector.push_back(new Thread());
	}
}
ThreadPool::~ThreadPool(){

}
void ThreadPool::lock(){
	pthread_mutex_lock(&ThreadPool::mutex);
}
void ThreadPool::unlock(){
	pthread_mutex_unlock(&ThreadPool::mutex);

}
void ThreadPool::wait(){
	pthread_cond_wait(&ThreadPool::cond,&ThreadPool::mutex);
}
void ThreadPool::signal(){
	pthread_cond_signal(&ThreadPool::cond);
}
void ThreadPool::addTask(Task* task){
    ThreadPool::lock();
	ThreadPool::taskQueue.push(task);
	ThreadPool::signal();
    ThreadPool::unlock();
}