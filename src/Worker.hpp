#pragma once
#include "Task.hpp"

class Worker {
private:
    int id;
    bool available;
    Task& task;

public:
    Worker(int _id, bool _available, Task& _task);

    Worker(const Worker&) = delete;
    Worker(Worker&&) = delete;
    Worker& operator=(const Worker&) = delete;
    Worker& operator=(Worker&&) = delete;

    int getId() const;
    bool isAvailable() const;
    Task& getTask() const;

    bool receiveTask(Task& newTask);

    void finishTask();
};
