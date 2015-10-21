#ifndef TASK_H
#define TASK_H
class Task
{
public:
	Task(int id){
		this->task_id=id;
	}
	~Task();
	virtual void run()=0;
	int getId(){
		return this->task_id;
	}
private:
	int task_id;
};


#endif