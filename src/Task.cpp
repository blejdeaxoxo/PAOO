#include "Task.hpp"

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

int Task::getId() const { return id; }
const char* Task::getTitle() const { return title; }