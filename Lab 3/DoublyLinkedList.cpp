/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab: 3*/

#include <iostream>
#include <string>
using namespace std;

/* ==== DOUBLY LINKED LIST NODE ==== */
class DNode {
public:
    string name;
    DNode* next;
    DNode* prev;

    DNode(string name, DNode* next = nullptr, DNode* prev = nullptr) {
        this->name = name;
        this->next = next;
        this->prev = prev;
    }
};

// === DOUBLY LINKED LIST ===
class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;

    DoublyLinkedList(DNode* node) {
        head = tail = node;
    }

    // Add node to end
    void add_node(DNode* node) {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    // Display from head to tail
    void display_forward() {
        DNode* current = head;
        cout << "List (forward): ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Display from tail to head
    void display_backward() {
        DNode* current = tail;
        cout << "List (backward): ";
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }

    // Delete node by value
    void delete_by_value(string val) {
        DNode* current = head;

        while (current != nullptr) {
            if (current->name == val) {
                if (current == head) {
                    head = current->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }

        cout << "Value not found: " << val << endl;
    }
};

// === MAIN ===
int main() {
    cout << "=== Doubly Linked List ===" << endl;

    // Create nodes
    DNode* d1 = new DNode("Ali");
    DNode* d2 = new DNode("Ahmed");
    DNode* d3 = new DNode("Alee");
    DNode* d4 = new DNode("Bayan");

    // Build list
    DoublyLinkedList dll(d1);
    dll.add_node(d2);
    dll.add_node(d3);
    dll.add_node(d4);

    // Display
    dll.display_forward();    // Ali <-> Ahmed <-> Alee <-> Bayan <-> NULL
    dll.display_backward();   // Bayan <-> Alee <-> Ahmed <-> Ali <-> NULL

    // Delete a node
    dll.delete_by_value("Alee");
    dll.display_forward();    // Ali <-> Ahmed <-> Bayan <-> NULL

    return 0;
}
