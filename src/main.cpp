#include <iostream>
#include "PriorityTask.hpp"
#include "Worker.hpp"

int main() {
    PriorityTask t1(1, "Clean database", 5);
    PriorityTask t2(2, "Backup server", 8);
    PriorityTask t3(3, "Deploy update", 10);
    
    std::cout << "Assigning tasks to workers...\n";

    Worker w1(101, true, t1);
    Worker w2(102, true, t2);
    Worker w3(103, true, t3);

    std::cout << "Worker 1 task: " << w1.getTask().getTitle() << "\n";
    std::cout << "Worker 2 task: " << w2.getTask().getTitle() << "\n";
    std::cout << "Worker 3 task: " << w3.getTask().getTitle() << "\n\n";

    std::cout << "Chained assignment: t1 = t2 = t3\n";

    t1=t2=t3;

    std::cout << "After t1 = t2 = t3:\n";
    std::cout << "t1: " << t1.getTitle() << ", priority " << t1.getPriority() << "\n";
    std::cout << "t2: " << t2.getTitle() << ", priority " << t2.getPriority() << "\n";
    std::cout << "t3: " << t3.getTitle() << ", priority " << t3.getPriority() << "\n\n";

    std::cout << "Worker 1 task: " << w1.getTask().getTitle() << "\n";
    std::cout << "Worker 2 task: " << w2.getTask().getTitle() << "\n";
    std::cout << "Worker 3 task: " << w3.getTask().getTitle() << "\n";

    w1.finishTask();
    w2.finishTask();
    w3.finishTask();

    std::cout << "\nReassigning tasks to worker 1...\n";
    w1.receiveTask(t1); w1.finishTask();
    w1.receiveTask(t2); w1.finishTask();
    w1.receiveTask(t3); w1.finishTask();

    return 0;
}
