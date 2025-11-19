#pragma once
#include "Task.hpp"

class PriorityTask : public Task {
    private:
        int priority;

    public:
        PriorityTask();
        PriorityTask(int _id, const char* _title, int _priority);

        ~PriorityTask() = default;

        PriorityTask(const PriorityTask& original);
        PriorityTask(PriorityTask&& original) noexcept;

        PriorityTask& operator=(const PriorityTask& other);
        PriorityTask& operator=(PriorityTask&& other) noexcept;

        int getPriority() const;
};
