#include "TaskWorker.h"
TaskWorker::TaskWorker(int id):Task(id){
    
}
void TaskWorker::run(){
    cout<<"my task id is "<<getId()<<endl;
}