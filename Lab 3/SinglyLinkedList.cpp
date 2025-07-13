/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab: 3*/

// ==== SINGLY LINKED LIST ====
#include <iostream>
#include <string>
using namespace std;

class SNode {
public:
    string name;
    SNode* next;

    SNode(string name, SNode* next = nullptr) {
        this->name = name;
        this->next = next;
    }
};

class SinglyLinkedList {
public:
    SNode* head;
    SNode* tail;

    SinglyLinkedList(SNode* node) {
        head = tail = node;
    }

    // Add node to the end of the list
    void add_node(SNode* node) {
        tail->next = node;
        tail = node;
    }

    // Display the list
    void display_list() {
        SNode* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Delete node by value
    void delete_by_value(string val) {
        SNode* current = head;
        SNode* prev = nullptr;

        while (current != nullptr) {
            if (current->name == val) {
                if (prev == nullptr) {
                    // Deleting head
                    head = current->next;
                } else {
                    prev->next = current->next;
                }

                if (current == tail) {
                    // Update tail if deleting last node
                    tail = prev;
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Value not found: " << val << endl;
    }
};

int main() {
    cout << "=== Singly Linked List ===" << endl;

    // Create nodes
    SNode* s1 = new SNode("Ali");
    SNode* s2 = new SNode("Ahmed");
    SNode* s3 = new SNode("Alee");
    SNode* s4 = new SNode("Bayan");

    // Build list
    SinglyLinkedList sll(s1);
    sll.add_node(s2);
    sll.add_node(s3);
    sll.add_node(s4);

    // Display list
    sll.display_list();  // Output: Ali -> Ahmed -> Alee -> Bayan -> NULL

    // Delete a node
    sll.delete_by_value("Alee");
    sll.display_list();  // Output: Ali -> Ahmed -> Bayan -> NULL

    return 0;
}
