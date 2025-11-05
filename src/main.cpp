#include <iostream>
#include "Task.hpp"
#include "TaskManager.hpp"

int main(){
    Task t1(1, "Homework");
    Task t2(2, "Cook");
    Task t3(3, "Draw");
    TaskManager tm;

    tm.addTask(t1);
    tm.addTask(t2);
    tm.addTask(t3);

    TaskManager tmCopy = tm;

    std::cout << "Original TaskManager (after completing task 2):\n";
    tm.completeTask(2);

    tm.printTasks();

    std::cout << "Copy of TaskManager (should be unchanged):\n";
    tmCopy.printTasks();

    TaskManager tmMoved = std::move(tm);

    std::cout << "Moved TaskManager (tmMoved):\n";
    tmMoved.printTasks();

    std::cout << "Original TaskManager after move (should be empty):\n";
    tm.printTasks();
}