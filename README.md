# To-Do List (C++)

A simple and user-friendly console-based To-Do List application written in C++. It allows you to manage your tasks efficiently by adding, viewing, completing, filtering, and deleting them. All tasks are saved to and loaded from `tasks.txt` to keep your data persistent.

## Features

* Add tasks with name, category (Studying / Working / Other), deadline, and status
* View all tasks with details
* Mark tasks as completed
* Filter tasks by category
* Delete tasks
* Console menu for easy navigation
* Automatic saving and loading of tasks

## Project Structure

```
main.cpp
Task.h
Task.cpp
TaskManager.h
TaskManager.cpp
CMakeLists.txt
```

## Build & Run

1. Open terminal and navigate to the project folder
2. Create build folder: `mkdir build && cd build`
3. Generate build files: `cmake ..`
4. Build the project: `cmake --build .`
5. Run the program: `./todo` (macOS/Linux) or `todo.exe` (Windows)

## Notes

* Task data is stored in `tasks.txt` in the same directory as the executable
* Make sure to enter correct dates (`year month day hour minute`)
* The program preserves task status between sessions


