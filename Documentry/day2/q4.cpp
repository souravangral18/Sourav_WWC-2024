#include <iostream>
#include <memory>
using namespace std;

struct Task {
    int taskID;
    int priority;
    int executionTime;
    shared_ptr<Task> next;
    Task(int id, int pr, int execTime) : taskID(id), priority(pr), executionTime(execTime), next(nullptr) {}
};

class TaskScheduler {
    shared_ptr<Task> head;

public:
    TaskScheduler() : head(nullptr) {}

    // Insert task in priority order (higher priority first)
    void insertTask(int taskID, int priority, int executionTime) {
        shared_ptr<Task> newTask = make_shared<Task>(taskID, priority, executionTime);
        
        if (!head || head->priority < priority) {
            newTask->next = head;
            head = newTask;
        } else {
            shared_ptr<Task> temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }

    // Remove task after completion
    void removeTask(int taskID) {
        if (!head) return;
        if (head->taskID == taskID) {
            head = head->next;
            return;
        }
        shared_ptr<Task> temp = head;
        while (temp->next && temp->next->taskID != taskID) {
            temp = temp->next;
        }
        if (temp->next) {
            temp->next = temp->next->next;
        }
    }

    // Simulate task execution and periodic task handling
    void executeTasks() {
        shared_ptr<Task> temp = head;
        while (temp) {
            cout << "Executing Task ID: " << temp->taskID << ", Priority: " << temp->priority << ", Time: " << temp->executionTime << endl;
            removeTask(temp->taskID);
            temp = temp->next;
        }
    }

    // Display current state of tasks
    void displayTasks() {
        shared_ptr<Task> temp = head;
        while (temp) {
            cout << "Task ID: " << temp->taskID << ", Priority: " << temp->priority << ", Execution Time: " << temp->executionTime << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    // Insert tasks
    scheduler.insertTask(1, 3, 10); // Task 1, Priority 3
    scheduler.insertTask(2, 1, 5);  // Task 2, Priority 1
    scheduler.insertTask(3, 2, 7);  // Task 3, Priority 2

    cout << "Current Tasks:" << endl;
    scheduler.displayTasks();

    // Execute tasks
    cout << "\nExecuting Tasks..." << endl;
    scheduler.executeTasks();

    return 0;
}