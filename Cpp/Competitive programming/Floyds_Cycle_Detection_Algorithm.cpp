#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&HEAD, Node *&TAIL, int data)
{
    Node *temp = new Node(data);

    if (HEAD == NULL)
        HEAD = temp;
    else
        TAIL->next = temp;
    TAIL = temp;
}

Node *floydDetectionLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return fast;
        }
    } while (slow != fast && fast != NULL && fast->next != NULL);

    return NULL;
}

Node *getStart(Node *head, Node *fast)
{
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    Node *meetLocation = floydDetectionLoop(head);
    if (meetLocation)
    {
        Node *start = getStart(head, meetLocation);
        Node *temp = start;
        while (temp->next != start)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
    return head;
}

void print(Node *HEAD)
{
    Node *temp = HEAD;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *HEAD = NULL;
    Node *TAIL = NULL;

    insertAtTail(HEAD, TAIL, 1); // 1
    insertAtTail(HEAD, TAIL, 2); // 1 2
    insertAtTail(HEAD, TAIL, 3); // 1 2 3
    insertAtTail(HEAD, TAIL, 4); // 1 2 3 4
    insertAtTail(HEAD, TAIL, 5); // 1 2 3 4 5
    insertAtTail(HEAD, TAIL, 6); // 1 2 3 4 5 6

    TAIL->next = HEAD->next; // 1 2 3 4 5 6 2

    // print(HEAD); // infinite loop because of cycle

    Node *isCircular = floydDetectionLoop(HEAD);

    if (isCircular)
    {
        cout << "Cycle is Present" << endl;

        HEAD = removeLoop(HEAD);
        cout << "After removing cycle: ";
        print(HEAD);
    }
    else
    {
        cout << "Cycle not Present" << endl;
    }

    return 0;
}