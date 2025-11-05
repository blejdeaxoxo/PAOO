#pragma once
#include<cstring>

class Task{
    private:
        int id;
        char* title;

    public:
        Task(int _id, const char* _title);

        ~Task();

        Task(const Task& original);

        Task(Task&& original) noexcept;

        int getId() const;

        const char* getTitle() const;
};