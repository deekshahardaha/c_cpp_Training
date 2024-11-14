#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;       
    Node* next;    

    // Constructor to initialize a node
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head; // Pointer to the head of the list

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    // Function to insert a new node at the end
    void insert(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = newNode; // If the list is empty, set head to the new node
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }
    }

    // Function to delete a node by value
    void remove(T value) {
        if (!head) return; 

        // If the head needs to be removed
        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next; 
            delete temp;      
            return;
        }

        // Traverse the list to find the node to delete
        Node<T>* current = head;
        Node<T>* previous = nullptr;
        while (current && current->data != value) {
            previous = current;
            current = current->next;
        }

        // If the value was found, unlink the node
        if (current) {
            previous->next = current->next; 
            delete current;
        }
    }

    // Function to display the linked list
    void display() const {
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
            remove(head->data); // Remove nodes one by one(for each node the remove function will be called for the data of that node.)
        }
    }
};

int main() {
    LinkedList<int> intList; // Create a linked list for integers
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    cout << "Integer Linked List: ";
    intList.display();

    intList.remove(20);
    cout << "After removing 20: ";
    intList.display();

    LinkedList<string> stringList; // Create a linked list for strings
    stringList.insert("Hello");
    stringList.insert("World");
    cout << "String Linked List: ";
    stringList.display();

    stringList.remove("Hello");
    cout << "After removing 'Hello': ";
    stringList.display();

    return 0;
}