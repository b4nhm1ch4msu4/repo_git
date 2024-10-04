#ifndef TASK_H
#define TASK_H

#include <string>
#endif // TASK_H

class Task{
public:
    Task();
    void addTask();
    void removeTask();
    Task viewTask(int);
    Task* listTask();
private:
    std::string content;
    int id;
    int counter;
};
