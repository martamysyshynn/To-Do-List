#include "Task.h"
#include <ctime>

using namespace std;

    Task::Task() {}
    Task::Task(string taskName, string category, chrono::system_clock::time_point deadline, bool isCompleted) : taskName(taskName), category(category), deadline(deadline), isCompleted(isCompleted) {} 

    string Task::getTaskName() {return taskName;}
    string Task::getCategory() {return category;}
    chrono::system_clock::time_point Task::getDeadline() {return deadline;}
    bool Task::getIsCompleted() {return isCompleted;}

    void Task::setIsCompleted(bool status) {isCompleted = status;}


    void Task::PrintData() {
        time_t t = chrono::system_clock::to_time_t(deadline);
        cout << "Task Name: " << taskName << endl;
        cout << "Category: " << category << endl;
        cout << "Deadline: " << ctime(&t) << endl;
        cout << "Status: " << (isCompleted ? "✔ Done" : "✗ In progress") << endl;

    }

    void Task::WriteDataToFile(ostream& filename) {
        time_t t = chrono::system_clock::to_time_t(deadline);

        filename << taskName << endl;
        filename << category << endl;
        filename << t << endl;
        filename << isCompleted << endl;

    }

    Task::~Task() {}