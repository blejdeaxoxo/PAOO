#pragma once
#include<cstring>

class Task{
    private:
        int id;
        char* title;

    public:
        Task();
        Task(int _id, const char* _title);

        ~Task();

        Task(const Task& original);
        Task(Task&& original) noexcept;

        Task& operator=(const Task& other);
        Task& operator=(Task&& other) noexcept;

        int getId() const;
        const char* getTitle() const;
};