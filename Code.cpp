#include <iostream>
#include <string>

using namespace std;


struct Task {
    int taskID;              
    string description;      
    int priority;            
    Task* next;              
};

Task* createTask(int id, string desc, int priority) {
    Task* newTask = new Task();      
    newTask->taskID = id;            
    newTask->description = desc;     
    newTask->priority = priority;    
    newTask->next = nullptr;         
    return newTask;                  
void addTask(Task*& head, int id, string desc, int priority) {
    Task* newTask = createTask(id, desc, priority);  

    if (head == nullptr || head->priority < priority) {
        newTask->next = head;  
        head = newTask;
    } else {
    
        Task* temp = head;
        while (temp->next != nullptr && temp->next->priority >= priority) {
            temp = temp->next; 
        }
    
        newTask->next = temp->next;
        temp->next = newTask;
    }
    cout << "Task added successfully.\n";
}

void viewTasks(Task* head) {
    if (head == nullptr) {   
        cout << "No tasks available.\n";
        return;
    }

    Task* temp = head;
    while (temp != nullptr) {
        cout << "Task ID: " << temp->taskID << "\nDescription: " << temp->description
             << "\nPriority: " << temp->priority << "\n\n";
        temp = temp->next;  
    }
}

void removeHighestPriorityTask(Task*& head) {
    if (head == nullptr) {  
        cout << "No tasks to remove.\n";
        return;
    }

    
    Task* temp = head;
    head = head->next;  
    cout << "Task with ID " << temp->taskID << " removed.\n";
    delete temp; 
}

void removeTaskByID(Task*& head, int id) {
    if (head == nullptr) {  
        cout << "No tasks to remove.\n";
        return;
    }
    if (head->taskID == id) {
        Task* temp = head;
        head = head->next;  
        delete temp;  
        cout << "Task with ID " << id << " removed.\n";
        return;
    }
    Task* temp = head;
    while (temp->next != nullptr && temp->next->taskID != id) {
        temp = temp->next;  
    }

    if (temp->next != nullptr) {
        Task* taskToRemove = temp->next;
        temp->next = taskToRemove->next;
        delete taskToRemove;  
        cout << "Task with ID " << id << " removed.\n";
    } else {
        cout << "Task with ID " << id << " not found.\n";
    }
}

int main() {
    Task* head = nullptr; 
    int choice, id, priority;
    string description;

    do {
        cout << "\nTask Management System\n";
        cout << "1. Add New Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Remove Highest Priority Task\n";
        cout << "4. Remove Task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task ID: ";
                cin >> id;
                cin.ignore();  
                cout << "Enter task description: ";
                getline(cin, description);  
                cout << "Enter task priority: ";
                cin >> priority;
                addTask(head, id, description, priority);
                break;

            case 2:
                viewTasks(head);
                break;

            case 3:
                removeHighestPriorityTask(head);
                break;

            case 4:
                cout << "Enter task ID to remove: ";
                cin >> id;
                removeTaskByID(head, id);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);  

    return 0;
}
