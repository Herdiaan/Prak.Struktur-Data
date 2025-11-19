#include "queue.h"
#include "queue.cpp"
#include <iomanip>

void run_test_alt3() {
    std::cout << "Hello world!" << std::endl;
    std::cout << "H    T    : Queue Info" << std::endl; 
    std::cout << "------------------------------------------" << std::endl;
    
    Queue Q;
    CreateQueue(Q);
    
    printInfo(Q); 

    for (int i = 1; i < MAX_SIZE; i++) {
        enqueue(Q, i * 10);
        printInfo(Q);
    } 

    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 

    enqueue(Q, 99);
    printInfo(Q);
    enqueue(Q, 88); 
    printInfo(Q); 

    enqueue(Q, 77); 
    printInfo(Q); 
}

int main() {
    run_test_alt3();
    return 0;
}