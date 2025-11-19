#include "PriorityTask.hpp"

PriorityTask::PriorityTask() : Task(), priority(0) {}

PriorityTask::PriorityTask(int _id, const char* _title, int _priority)
    : Task(_id, _title), priority(_priority) {}

PriorityTask::PriorityTask(const PriorityTask& original)
    : Task(original), priority(original.priority) {}

PriorityTask::PriorityTask(PriorityTask&& original) noexcept
    : Task(std::move(original)), priority(original.priority)
{
    original.priority = 0;
}

PriorityTask& PriorityTask::operator=(const PriorityTask& other){
    if (this == &other)
        return *this;

    Task::operator=(other);
    priority = other.priority;

    return *this;
}

PriorityTask& PriorityTask::operator=(PriorityTask&& other) noexcept{
    if (this == &other)
        return *this;

    Task::operator=(std::move(other));
    priority = other.priority;

    other.priority = 0;

    return *this;
}

int PriorityTask::getPriority() const {
    return priority;
}
