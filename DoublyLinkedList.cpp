#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node() {}

    Node(int data)
    {
        this->data = data;
        next = 0;
        prev = 0;
    }
};

void display(Node *head) {
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtTail(Node *head, int data) {
    while (head->next)
    {
        head = head->next;
    }
    Node* temp = new Node(data);
    temp->prev = head;
    head->next = temp;
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtPosition(Node* &head, int pos, int data) {
    if(pos == 1)
    {
        insertAtHead(head,data);
        return;
    }

    int cnt = 1;
    Node* pre = head;
    while(cnt < pos - 1)
    {
        pre = pre->next;
        cnt++;
    }
    if(pre->next == 0)
    {
        insertAtTail(head,data);
        return;
    }
    Node* curr = pre->next;
    Node* temp = new Node(data);
    temp->prev = pre;
    pre->next = temp;
    temp->next = curr;
    curr->prev = temp;
}

void deleteAtIndex(Node*& head,int ind) {
    if(ind == 1)
    {
        head->next->prev = NULL;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int cnt = 1;
    Node* pre = head;
    while(cnt < ind-1)
    {
        pre = pre->next;
        cnt++;
    }

    Node* temp = pre->next;
    if(temp->next == NULL)
    {
        pre->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    pre->next = temp->next;
    temp->next->prev = pre;
    delete temp;
}
int main()
{
    Node *head = new Node(55);

    insertAtTail(head, 65);
    insertAtTail(head, 88);
    insertAtPosition(head,4,5);
    display(head);
    deleteAtIndex(head,4);
    display(head);

    return 0;
}