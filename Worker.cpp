#include "Worker.hpp"

Worker::Worker()
    : id(0), available(true), task() {}

Worker::Worker(int _id, bool _available, const Task& _task)
    : id(_id), available(_available), task(_task) {}

Worker::Worker(const Worker& original)
    : id(original.id),
      available(original.available),
      task(original.task) {}

Worker::Worker(Worker&& original) noexcept
    : id(original.id),
      available(original.available),
      task(std::move(original.task))
{
    original.id = 0;
    original.available = true;
}

Worker& Worker::operator=(const Worker& other) {
    if (this == &other)
        return *this;

    id = other.id;
    available = other.available;
    task = other.task;

    return *this;
}

Worker& Worker::operator=(Worker&& other) noexcept {
    if (this == &other)
        return *this;

    id = other.id;
    available = other.available;
    task = std::move(other.task);

    other.id = 0;
    other.available = true;

    return *this;
}

int Worker::getId() const {
    return id;
}

bool Worker::isAvailable() const {
    return available;
}

const Task& Worker::getTask() const {
    return task;
}

bool Worker::receiveTask(const Task& newTask) {
    if (!available)
        return false;

    task = newTask;
    available = false;
    return true;
}

void Worker::finishTask() {
    available = true;
}
