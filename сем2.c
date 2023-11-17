#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

class LinkedList {
    public:
        bool add_element(int data);
        int delete_element(int data);
        bool find_element(int data);
        bool insert(int data, int position);

        LinkedList(int data);
        LinkedList();
        ~LinkedList();
    private:
        Node* first;
        Node* last;
};

LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
}

LinkedList::LinkedList(int data) {
    Node* nd = new Node{ data };
    first = nd;
    last = nd;
    last->next = nullptr;
}

bool LinkedList::add_element(int data) {
    Node* nd = new Node{ data, nullptr };
    if (last == nullptr) {
        first = nd;
        last = nd;
        return true;
    }
    last->next = nd;
    last = nd;
    return true;
}

bool LinkedList::find_element(int data) {
    if(last != nullptr) {
        Node* current = first;

        while (current != nullptr) {
            if (current->data == data) return true;
            current = current->next;
        }
    }
    return false;
}

bool LinkedList::insert(int data, int position) {
    if (last != nullptr) {
        Node* current = first;
        size_t i = 0;

        while (current != nullptr) {

            if (i == position - 1) {

                Node* nd = new Node{ data, current->next};
                current->next = nd;

                return true;
            }
            current = current->next;
            i += 1;
        }
    }

    return false;
}

LinkedList::~LinkedList() {
    if (last != nullptr) {
        Node* current = first;

        while (current != nullptr) {
            Node* nd = new Node{ 0, current->next };
            delete current;

            current = nd;
        }
    }
}

int main() {
    LinkedList lst;

    Node nd;
    Node* nd1 = new Node;

    nd.data;
    nd1->data;

    return 0;
}
