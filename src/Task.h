#pragma once
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

class Task {
    private:
    string taskName;
    string category;
    chrono::system_clock::time_point deadline;
    bool isCompleted;

    public:
    Task();
    Task(string taskName, string category, chrono::system_clock::time_point deadline, bool isCompleted);

    string getTaskName();
    string getCategory();
    chrono::system_clock::time_point getDeadline();
    bool getIsCompleted();

    void setIsCompleted(bool status);


    void PrintData();

    void WriteDataToFile(ostream& filename);

    ~Task();
};
