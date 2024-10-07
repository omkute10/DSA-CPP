#include <iostream>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    
    DoublyNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyNode* head;
    
    DoublyLinkedList() {
        head = nullptr;
    }
    
    // Insert at the beginning
    void insertAtHead(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }
    
    // Insert at the end
    void insertAtTail(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DoublyNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    // Delete a node
    void deleteNode(int val) {
        if (!head) return;
        DoublyNode* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;
        }
        if (!temp) return;
        
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        
        if (temp == head) head = temp->next;
        delete temp;
    }
    
    // Print the list
    void display() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtTail(30);
    dll.insertAtHead(10);
    dll.insertAtTail(50);
    dll.display();
    dll.deleteNode(30);
    dll.display();
    return 0;
}
