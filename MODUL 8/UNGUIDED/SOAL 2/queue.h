#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib> 

typedef int infotype;
#define MAX_SIZE 5

typedef struct {
    infotype A[MAX_SIZE];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
void printInfo(Queue Q);

bool isFullQueue(Queue Q); 
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);

#endif