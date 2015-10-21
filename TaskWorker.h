#ifndef TASK_WORKER_H
#define TASK_WORKER_H

#include "Task.h"
#include <iostream>
using namespace std;
class TaskWorker:public Task
{
public:
    TaskWorker(int id);
    ~TaskWorker();
    void run();
};
#endif