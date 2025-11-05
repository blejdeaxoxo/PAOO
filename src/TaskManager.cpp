#include "TaskManager.hpp"

TaskManager::TaskManager(): pendingTasks(nullptr), doneTasks(nullptr), pendingCount(0), doneCount(0){}

TaskManager::~TaskManager(){
    delete[] pendingTasks;
    delete[] doneTasks;
}

TaskManager::TaskManager(const TaskManager& original) : pendingCount(original.pendingCount), doneCount(original.doneCount){
    pendingTasks = new Task[pendingCount];
    for (size_t i = 0; i < pendingCount; i++)
        pendingTasks[i] = original.pendingTasks[i];

    doneTasks = new Task[doneCount];
    for (size_t i = 0; i < doneCount; i++)
        doneTasks[i] = original.doneTasks[i];
}

TaskManager::TaskManager(TaskManager&& original) noexcept
    : pendingTasks(original.pendingTasks),
      pendingCount(original.pendingCount),
      doneTasks(original.doneTasks),
      doneCount(original.doneCount)
{
    original.pendingTasks = nullptr;
    original.pendingCount = 0;
    original.doneTasks = nullptr;
    original.doneCount = 0;
}

void TaskManager::addTask(const Task& task){
    Task* newPending = new Task[pendingCount + 1];
    for (size_t i = 0; i < pendingCount; ++i)
        newPending[i] = std::move(pendingTasks[i]);
    newPending[pendingCount] = task;
    delete[] pendingTasks;
    pendingTasks = newPending;
    ++pendingCount;
}

void TaskManager::completeTask(int id){
    for (size_t i = 0; i < pendingCount; i++){
        if (pendingTasks[i].getId() == id){
            Task* newDone = new Task[doneCount + 1];
            for (size_t j = 0; j < doneCount; ++j)
                newDone[j] = std::move(doneTasks[j]);
            newDone[doneCount] = std::move(pendingTasks[i]);
            delete[] doneTasks;
            doneTasks = newDone;
            ++doneCount;

            Task* newPending = new Task[pendingCount - 1];
            for (size_t j = 0, k = 0; j < pendingCount; ++j)
            {
                if (j != i)
                    newPending[k++] = std::move(pendingTasks[j]);
            }
            delete[] pendingTasks;
            pendingTasks = newPending;
            --pendingCount;
            return;
        }
    }
}

void TaskManager::printTasks() const{
    std::cout << "Pending Tasks (" << pendingCount << "):\n";
    for (size_t i = 0; i < pendingCount; ++i)
    {
        std::cout << "  [" << pendingTasks[i].getId() << "] "
                  << pendingTasks[i].getTitle() << "\n";
    }

    std::cout << "\nDone Tasks (" << doneCount << "):\n";
    for (size_t i = 0; i < doneCount; ++i)
    {
        std::cout << "  [" << doneTasks[i].getId() << "] "
                  << doneTasks[i].getTitle() << "\n";
    }
    std::cout << std::endl;
}

size_t TaskManager::getPendingCount() const { return pendingCount; }
size_t TaskManager::getDoneCount() const { return doneCount; }
const Task* TaskManager::getPendingTasks() const { return pendingTasks; }
const Task* TaskManager::getDoneTasks() const { return doneTasks; }