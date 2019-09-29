#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int dq[MAX];
int front = -1;
int rear = 0;

bool isFull()
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        return true;
    }

    return false;
}

bool isEmpty()
{
    if (front == -1) {
        return true;
    }

    return false;
}

int getFront()
{
    if (isEmpty() == true) {
        return -1;
    }

    return dq[front];
}

int getRear()
{
    if (isEmpty() == true) {
        return -1;
    }

    return dq[rear];
}

void insertFront(int key)
{
    if (isFull() == true) {
        cout<<"Overflow"<<endl;
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX-1;
    } else {
        front -= 1;
    }

    dq[front] = key;
}

void insertRear(int key)
{
    if (isFull() == true) {
        cout<<"Overflow"<<endl;
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == MAX-1) {
        rear = 0;
    } else {
        rear += 1;
    }

    dq[rear] = key;
}

void deleteFront()
{
    if (isEmpty() == true) {
        cout<<"Underflow"<<endl;
        return;
    }

    if (front == rear) {
        rear = -1;
        front = -1;
    } else if (front == MAX-1) {
        front = 0;
    } else {
        front += 1;
    }
}

void deleteRear()
{
    if (isEmpty() == true) {
        cout<<"Underflow"<<endl;
        return;
    }

    if (front == rear) {
        rear = -1;
        front = -1;
    } else if (rear == 0) {
        rear = MAX-1;
    } else {
        rear -= 1;
    }
}

int main()
{
    insertRear(5);
    insertRear(10);
    cout<<getRear()<<endl;

    deleteRear();
    cout<<getRear()<<endl;

    insertFront(15);
    insertFront(20);


    cout<<getFront()<<endl;

    deleteFront();
    cout<<getFront()<<endl;

    return 0;
}
