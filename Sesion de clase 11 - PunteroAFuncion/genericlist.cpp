#include "genericlist.h"

using namespace std;

Node* createNode(void* data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = nullptr;
    
    return newNode;
}

Node* appendNode(Node* head, void* data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->link != nullptr) {
        current = current->link;
    }
    current->link = newNode;
    return head;
}

void printList(Node* head, void (*print)(Node*)) {
    Node* current = head;
    while (current != nullptr) {
        print(current);
        current = current->link;
    }
}

struct Employee* createEmployee(
    int id, 
    const char* name, 
    const char* title, 
    int salary
) {
    struct Employee *employee = new Employee;
    employee->id = id;
    employee->name = new char[strlen(name) + 1];
    strcpy(employee->name, name);
    employee->title = new char[strlen(title) + 1];
    strcpy(employee->title, title);
    employee->salary = salary;
    
    return employee;
}

void printEmployee(Node* node) {
    struct Employee* emp = (struct Employee*)node->data;
    cout << "Código: " << right << setw(3) << setfill('0') << emp->id;
    cout << ", Nombre: " << left << emp->name;
    cout << ", Puesto: " << left << emp->title;
    cout << ", Salario: S/" << left << fixed << setprecision(2) << emp->salary;
    cout << endl;
}

void printInteger(Node* node) {
    int a = *(int*)node->data;
    cout << a << " ";
}