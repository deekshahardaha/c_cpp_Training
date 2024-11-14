#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;        
    Node* next;    
    Node* prev;    

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head; 
    Node<T>* tail; 

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        clear();
    }

    // Function to insert a new node at the front
    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode; 
        } else {
            newNode->next = head;  
            head->prev = newNode;  
            head = newNode;        
        }
    }

    // Function to insert a new node at the back
    void insertBack(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode; 
        } else {
            newNode->prev = tail;  
            tail->next = newNode;  
            tail = newNode;        
        }
    }

    // Function to delete a node by value
    void remove(T value) {
        Node<T>* current = head;
        while (current) {
            if (current->data == value) {
                // If the node to be deleted is the head
                if (current == head) {
                    head = head->next;
                    if (head) {
                        head->prev = nullptr; // Update the new head's prev pointer
                    } else {
                        tail = nullptr; // If the list is now empty, update tail
                    }
                }
                // If the node to be deleted is the tail
                else if (current == tail) { 
                    tail = tail->prev; 
                    tail->next = nullptr;
                } 
                // If the node is in the middle
                else { 
                    current->prev->next = current->next; 
                    current->next->prev = current->prev; 
                }
                delete current; 
                return;
            }
            current = current->next; 
        }
    }

    // Function to display the linked list in forward direction
    void displayForward() const {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }


    // Function to clear the linked list
    void clear() {
        while (head) {
            remove(head->data); // Remove nodes one by one
        }
    }
};

int main() {
    DoublyLinkedList<int> intList; // Create a doubly linked list for integers
    intList.insertBack(10);
    intList.insertBack(20);
    intList.insertBack(30);
    cout << "Doubly Linked List : ";
    intList.displayForward();

    intList.insertFront(5);
    cout << "After inserting 5 at the front: ";
    intList.displayForward();

    intList.remove(20);
    cout << "After removing 20: ";
    intList.displayForward();

    DoublyLinkedList<string> stringList; // Create a doubly linked list for strings
    stringList.insertBack("Hello");
    stringList.insertBack("World");
    cout << "String Doubly Linked List : ";
    stringList.displayForward();

    stringList.insertFront("Greetings");
    cout << "After inserting 'Greetings' at the front: ";
    stringList.displayForward();

    stringList.remove("Hello");
    cout << "After removing 'Hello': ";
    stringList.displayForward();

    return 0;
}