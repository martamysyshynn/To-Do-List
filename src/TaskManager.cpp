#include "TaskManager.h"
#include <fstream>
#include <iostream>

using namespace std;


TaskManager::TaskManager() {}
TaskManager::TaskManager(vector<Task> newTask) : task(newTask) {}


void TaskManager::SaveToFile() {
    ofstream file("tasks.txt");
    if(file.is_open()) {
        for(auto tasks: task) {
            tasks.WriteDataToFile(file);
            file << endl;
        }
        file.close();
    } else {
        cout << "Can't open the file!";
    }
}

void TaskManager::ReadFromFile() {
    ifstream file("tasks.txt");
    if (!file.is_open()) {
        cout << "Can't open the file!" << endl;
        return;
    }

    task.clear(); 

    string name, cat;
    time_t t;
    bool status;

    while (getline(file, name)) {
        getline(file, cat);
        file >> t;
        file >> status;
        file.ignore(); 

        chrono::system_clock::time_point deadline = chrono::system_clock::from_time_t(t);
        Task loadedTask(name, cat, deadline, status);
        task.push_back(loadedTask);

        file.ignore(); 
    }

    file.close();
}


void TaskManager::AddTask() {
    int amount_of_tasks;
    cout << "How many cards do you want to add? " << endl;
    cin >> amount_of_tasks;

    for (int i = 0; i < amount_of_tasks; i++) {
        string name, cat;
        int year, month, day, hour, minute;
        bool status;

        cin.ignore();

        cout << "Enter task name: " << endl;
        getline(cin, name);

        cout << "Enter category: (Studying / Working / Other) " << endl;
        getline(cin, cat);

        cout << "Enter date: (year, month, day, hour, minute) " << endl;
        cin >> year >> month >> day >> hour >> minute;

        cout << "Enter status: (done: 1, in progres: 0) " << endl;
        cin >> status;

        tm timeinfo = {};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        timeinfo.tm_hour = hour;
        timeinfo.tm_min = minute;
        timeinfo.tm_sec = 0;

        time_t time_tt = mktime(&timeinfo);
        chrono::system_clock::time_point deadline = chrono::system_clock::from_time_t(time_tt);

        Task newTask(name, cat, deadline, status);
        task.push_back(newTask);
        SaveToFile();
    }
}

void TaskManager::ShowAllTasks() {
    if(task.empty()) {
        cout << "There are no tasks!" << endl;
        return;
    }

    for (int i = 0; i < task.size(); i++) {
        task[i].PrintData();
    }
}

void TaskManager::MarkAsCompleted() {
    if(task.empty()) {
        cout << "There are no tasks to change status!" << endl;
        return;
    }

    cout << "Select task number to change status: " << endl;
    for (int i = 0; i < task.size(); i++) {
        cout << i + 1 << ". " << task[i].getTaskName() << " - " << (task[i].getIsCompleted() ? "✔ Done" : "✗ In progress") << endl; 
    }

    int number;
    cin >> number;

    if (number < 1 || number > task.size()) {
        cout << "Invalid task number" << endl;
        return;
    } 

    task[number - 1].setIsCompleted(true);
    cout << "Task marked as completed!\n";
    SaveToFile();
}

void TaskManager::FilterByCategory() {
    if(task.empty()) {
        cout << "There are no tasks!" << endl;
        return;
    }

    string cat;
    cout << "Enter by which category should tasks be filtered: " << endl;
    cin >> cat;

    bool categoryIsFound = false;

    for (int i = 0; i < task.size(); i++) {
        if(task[i].getCategory() == cat) {
            task[i].PrintData();
            categoryIsFound = true;
        } 
    }

    if (!categoryIsFound) {
        cout << "Category is invalid!" << endl;
    }
}

void TaskManager::DeleteTask() {
    if(task.empty()) {
        cout << "There are no tasks to delete!" << endl;
        return;
    }

    cout << "Select task number to delete: " << endl;
    for (int i = 0; i < task.size(); i++) {
        cout << i + 1 << ". " << task[i].getTaskName() << endl;
    }

    int number;
    cin >> number;

    if (number < 1 || number > task.size()) {
        cout << "Invalid task number" << endl;
        return;
    } 

    task.erase(task.begin() + number - 1);
    cout << "Task deleted succesfully!" << endl;
    SaveToFile();
}


void TaskManager::Menu() {

    int option;
    do {
        cout << "=======================TO-DO LIST=======================\n";

        cout << "Menu:\n"
                << "1. Add task\n"
                << "2. View all tasks\n"
                << "3. Mark task as completed\n"
                << "4. Filter by category\n"
                << "5. Delete task\n" 
                << "6. Exit\n" << endl;
            
        cout << "Chose an option: " << endl;
        cin >> option;

        switch (option)
        {
            case 1:
                AddTask();
                break;
            case 2:
                ShowAllTasks();
                break;
            case 3:
                MarkAsCompleted();
                break;
            case 4:
                FilterByCategory();
                break;
            case 5:
                DeleteTask();
                break;

            default:
                break;
        }
    } while (option != 6);
    
    if (cin.fail()  ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid option!" << endl;
    } 
    
}


TaskManager::~TaskManager() {}
