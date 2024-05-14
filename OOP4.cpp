#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void attach(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void detach() {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot detach." << std::endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            delete head;
            head = nullptr;
        } else {
            prev->next = nullptr;
            delete temp;
        }
    }

    void traverse() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.attach(1);
    list.attach(2);
    list.attach(3);
    list.traverse(); // Output: 1 2 3

    list.detach();
    list.traverse(); // Output: 1 2

    list.detach();
    list.traverse(); // Output: 1

    list.detach();
    list.traverse(); // Output: List is empty.

    list.detach(); // Output: List is empty. Cannot detach.

    return 0;
}
