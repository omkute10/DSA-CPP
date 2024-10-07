#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert a node after a specific node
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == nullptr) {
            cout << "Previous node cannot be NULL" << endl;
            return;
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    // Function to delete a node by key
    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If head node itself holds the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in the list
        if (temp == nullptr) {
            cout << "Key not found in the list" << endl;
            return;
        }

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp;
    }

    // Function to search for a node
    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Linked List: ";
    list.display();

    cout << "After deleting node with data 20" << endl;
    list.deleteNode(20);
    list.display();

    cout << "After deleting node with data 50 (non-existent)" << endl;
    list.deleteNode(50);
    list.display();

    cout << "Searching for node with data 30: " << (list.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching for node with data 50: " << (list.search(50) ? "Found" : "Not Found") << endl;

    return 0;
}
