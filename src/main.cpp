#include "TaskManager.h"

int main() {
    TaskManager tasks;
    tasks.ReadFromFile();
    tasks.Menu();

    return 0;
}