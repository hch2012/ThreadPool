
#include <iostream>
#include "Thread.h"
#include "TaskWorker.h"


int main(int argc, const char * argv[]) {
    Task* task1=new TaskWorker(1);
    Task* task2=new TaskWorker(2);
    ThreadPool* pool=new ThreadPool(5);
    ThreadPool::addTask(task1);
    ThreadPool::addTask(task2);
    return 0;

}
