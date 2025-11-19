#include "Worker.hpp"
#include <iostream>

Worker::Worker(int _id, bool _available, Task& _task)
    : id(_id), available(_available), task(_task) {}

int Worker::getId() const { return id; }

bool Worker::isAvailable() const { return available; }

Task& Worker::getTask() const { return task; }

bool Worker::receiveTask(Task& newTask) {
    if (!available) {
        std::cout << "Worker " << id << " is busy, cannot receive task.\n";
        return false;
    }

    task = newTask;
    available = false;
    return true;
}

void Worker::finishTask() {
    available = true;
}
