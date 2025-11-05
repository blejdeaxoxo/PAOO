#pragma once
#include <cstddef>
#include <iostream>
#include"Task.hpp"

class TaskManager{
    private:
        Task* pendingTasks;
        Task* doneTasks;
        size_t pendingCount;
        size_t doneCount;

    public:
        TaskManager();

        ~TaskManager();

        TaskManager(const TaskManager& original);

        TaskManager(TaskManager&& original) noexcept;

        void addTask(const Task& task);

        void completeTask(int id);

        void printTasks() const;

        TaskManager& operator=(const TaskManager&) = delete;
        TaskManager& operator=(TaskManager&&) = delete;

        size_t getPendingCount() const;
        size_t getDoneCount() const;
        const Task* getPendingTasks() const;
        const Task* getDoneTasks() const;
};