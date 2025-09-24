#pragma once
#include <vector>
#include "Task.h"

using namespace std;

class TaskManager {
    private:
        vector<Task> task;

    public:
    TaskManager();
    TaskManager(vector<Task> newTask);


    void SaveToFile();
    void ReadFromFile();
    void AddTask();
    void ShowAllTasks();
    void MarkAsCompleted();
    void FilterByCategory();
    void DeleteTask();
    void Menu();


    ~TaskManager();
};