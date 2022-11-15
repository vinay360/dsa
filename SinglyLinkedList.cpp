#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int value;
    node *next;
    node() {}
    node(int value) {
        this->value = value;
        this->next = NULL;
    }
};

void display(node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
}

void insertAtHead(node* &head, int data) {
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int data) {
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtIndex(node *&head, int pos, int data) {
    node *temp = head;
    int count = 1;
    while (count < pos - 1) {
        temp = temp->next;
        count++;
    }
    node *toInsert = new node(data);
    toInsert->next = temp->next;
    temp->next = toInsert;
}

void deleteIndex(node *&head, int index) {
    node *temp = head;
    int cnt = 1;
    while (cnt < index - 1)
    {
        temp = temp->next;
        cnt++;
    }
    temp->next = temp->next->next;
}

int main() {
    node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtIndex(head, 1, 3);
    display(head);
}