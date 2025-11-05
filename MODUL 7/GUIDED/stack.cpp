#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool isEmpty(Node *top)
{
    return top == nullptr;
}

void push(Node *&top, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    cout << data << " pushed to stack\n";
}

int pop(Node *&top)
{
    if (isEmpty(top))
    {
        cout << "Stack kosong, tidak bisa pop\n";
        return 0; 
    }
    Node *temp = top;
    int poppedData = top->data;
    top = top->next;

    delete temp;
    return poppedData;
}

void show(Node *top)
{
    if (isEmpty(top))
    {
        cout << "Stack kosong\n";
        return;
    }
    cout << "Elemen teratas adalah " << top->data << endl;
    Node *temp = top;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *stack = nullptr;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
  
    cout << "menampilkan isi stack : " << endl;
    show(stack);

    cout << "Pop : " << pop(stack) << endl;
    cout << "menampilkan isi stack setelah pop: " << endl;
    show(stack);

    return 0;
}