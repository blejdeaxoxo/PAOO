#pragma once
#include "Task.hpp"

class Worker {
private:
    int id;
    bool available;
    Task task;

public:
    Worker();
    Worker(int _id, bool _available, const Task& _task);

    ~Worker() = default;

    Worker(const Worker& original);
    Worker(Worker&& original) noexcept;

    Worker& operator=(const Worker& other);
    Worker& operator=(Worker&& other) noexcept;

    int getId() const;
    bool isAvailable() const;
    const Task& getTask() const;

    bool receiveTask(const Task& newTask);

    void finishTask();
};
