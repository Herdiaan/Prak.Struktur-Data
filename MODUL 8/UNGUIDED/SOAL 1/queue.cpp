#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX_SIZE - 1);
}

void printInfo(Queue Q) {
    std::cout << Q.head << " \t " << Q.tail << " \t : ";
    
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
       
        for (int i = Q.head; i <= Q.tail; i++) {
             std::cout << Q.A[i];
             if (i < Q.tail) {
                 std::cout << " "; 
             }
        }
        std::cout << std::endl;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        return; 
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.A[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        return 0;
    }
    infotype removed_value = Q.A[Q.head];
    if (Q.head == Q.tail) {
        CreateQueue(Q);
    } else {
        for (int i = Q.head; i < Q.tail; i++) {
            Q.A[i] = Q.A[i + 1];
        }
        Q.tail--;
    }
    return removed_value;
}