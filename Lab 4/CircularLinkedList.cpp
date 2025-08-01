/* Name: Lez Evabelle Kennedy
Student ID: 22010920
Lab:4*/

// ==== CIRCULAR LINKED LIST ====
#include <iostream>
#include <string>
using namespace std;

class CNode {
public:
    string name;
    CNode* next;

    CNode(string name, CNode* next = nullptr) {
        this->name = name;
        this->next = next;
    }
};

class CircularLinkedList {
public:
    CNode* head;
    CNode* tail;

    CircularLinkedList(CNode* node) {
        head = tail = node;
        tail->next = head;
    }

    void add_node(CNode* node) {
        tail->next = node;
        tail = node;
        tail->next = head;
    }

    CNode* current = head;
    void display_list() {
        CNode* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != head);
        cout << head->name << endl;
    }

    void delete_by_value(string val) {
        CNode* current = head;
        CNode* prev = nullptr;

        while (current) {
            if (current->name == val) {
                if (!prev) head = current->next;
                else prev->next = current->next;
                if (current == tail) tail = prev;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

int main() {
    cout << "=== Circular Linked List ===" << endl;
    CNode* c1 = new CNode("Ali");
    CNode* c2 = new CNode("Ahmed");
    CNode* c3 = new CNode("Alee");
    CNode* c4 = new CNode("Bayan");

    CircularLinkedList sll(c1);
    sll.add_node(c2);
    sll.add_node(c3);
    sll.add_node(c4);
    sll.display_list();

    
    return 0;
}
