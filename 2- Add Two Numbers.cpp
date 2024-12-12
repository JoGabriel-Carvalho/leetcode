#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node* next;

    Node(const int number) : num(number), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int listLength = 0;

public:
    LinkedList() : head(nullptr) {}

    void append(const int number) {
        Node* newNode = new Node(number);

        if (head == nullptr) {
            head = newNode;

        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        listLength++;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->num << " -> ";
            temp = temp->next;
        }

        cout << "null" << endl;
    }

    Node* getHead() {
        return this->head;
    }

    int getListLength() {
        return this->listLength;
    }
};

LinkedList* sum(LinkedList list_1, LinkedList list_2) {
    LinkedList* sumList = new LinkedList();
    int carry = 0;

    Node* temp_1 = list_1.getHead();
    Node* temp_2 = list_2.getHead();

    while (temp_1 != nullptr || temp_2 != nullptr || carry != 0) {
        int value_1 = (temp_1 != nullptr) ? temp_1->num : 0;
        int value_2 = (temp_2 != nullptr) ? temp_2->num : 0;

        int sum = value_1 + value_2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        sumList->append(digit);

        if (temp_1 != nullptr) temp_1 = temp_1->next;
        if (temp_2 != nullptr) temp_2 = temp_2->next;
    }

    return sumList;
}

int main() {
    LinkedList list_1;
    LinkedList list_2;

    list_1.append(2);
    list_1.append(4);
    list_1.append(3);

    list_2.append(5);
    list_2.append(6);
    list_2.append(4);

    list_1.display();
    list_2.display();

    LinkedList* sumList = sum(list_1, list_2);

    sumList->display();

    return 0;
}
