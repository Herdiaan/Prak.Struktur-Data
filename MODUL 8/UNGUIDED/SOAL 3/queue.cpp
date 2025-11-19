#include "queue.h"
#include <iomanip> 

void CreateQueue(Queue &Q) { 
    Q.head = -1; 
    Q.tail = -1; 
}

bool isEmptyQueue(Queue Q) { 
    return (Q.head == -1 && Q.tail == -1); 
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX_SIZE == Q.head);
}

void printInfo(Queue Q) {
    std::cout << std::setw(4) << Q.head;
    std::cout << std::setw(4) << Q.tail;
    std::cout << " : ";
    
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
        int i = Q.head;
        do {
            std::cout << Q.A[i];
            if (i != Q.tail) {
                std::cout << " ";
            }
            
            i = (i + 1) % MAX_SIZE;
        } while (i != (Q.tail + 1) % MAX_SIZE);
        
        std::cout << std::endl;
    }
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) return;
    
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX_SIZE;
    }
    Q.A[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return 0;
    
    infotype removed_value = Q.A[Q.head];
    
    if (Q.head == Q.tail) {
        CreateQueue(Q);
    } else {
        Q.head = (Q.head + 1) % MAX_SIZE;
    }
    return removed_value;
}