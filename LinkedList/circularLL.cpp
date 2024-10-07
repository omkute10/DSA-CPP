#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    CNode* head;
    
    CircularLinkedList() {
        head = nullptr;
    }
    
    // Insert at the end
    void insertAtTail(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    // Insert at the beginning
    void insertAtHead(int val) {
        CNode* newNode = new CNode(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    
    // Delete a node
    void deleteNode(int val) {
        if (!head) return;
        if (head->data == val) {
            CNode* temp = head;
            CNode* last = head;
            while (last->next != head) last = last->next;
            if (head == head->next) head = nullptr;
            else {
                head = head->next;
                last->next = head;
            }
            delete temp;
            return;
        }
        CNode* temp = head;
        while (temp->next != head && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next->data == val) {
            CNode* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
    
    // Print the list
    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtTail(10);
    cll.insertAtHead(5);
    cll.insertAtTail(15);
    cll.display();
    cll.deleteNode(10);
    cll.display();
    return 0;
}
