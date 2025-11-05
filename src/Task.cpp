#include "Task.hpp"

Task::Task() : id(0), title(nullptr) {}

Task::Task(int _id, const char* _title) : id(_id){
    title = new char[strlen(_title) + 1];
    strcpy(title, _title);
}

Task::~Task(){
    delete[] title;
}

Task::Task(const Task& original) : id(original.id){
    title = new char[strlen(original.title) + 1];
    strcpy(title, original.title);
}

Task::Task(Task&& original) noexcept : id(original.id), title(original.title){
    original.title = nullptr;
}

Task& Task::operator=(const Task& other){
    if (this == &other)
        return *this;

    delete[] title;

    id = other.id;
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    return *this;
}

Task& Task::operator=(Task&& other) noexcept{
    if (this == &other)
        return *this;

    delete[] title;

    title = other.title;
    id = other.id;

    other.title = nullptr;
    other.id = 0;

    return *this;
}

int Task::getId() const { return id; }
const char* Task::getTitle() const { return title; }