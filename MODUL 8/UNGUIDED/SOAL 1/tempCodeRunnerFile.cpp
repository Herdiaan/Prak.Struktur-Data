#include "queue.h"
#include "queue.cpp" 

void run_test() {
    std::cout << "Hello World" << std::endl;
    std::cout << "H \t T \t : Queue Info" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    
    Queue Q;
    CreateQueue(Q);

    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    enqueue(Q, 2); printInfo(Q); 
    enqueue(Q, 7); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q);
    
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 
    dequeue(Q); printInfo(Q); 
    
    printInfo(Q); 
}

int main() {
    run_test();
    return 0;
}