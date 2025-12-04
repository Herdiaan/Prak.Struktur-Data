#include <iostream>
#include "bstree.h"
#include "bstree.cpp"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

     InOrder(root);
    cout << endl;

    int kedalaman = hitungKedalaman(root) + 2;
    cout << "kedalaman : " << kedalaman << endl;

    int jumlahNode = hitungJumlahNode(root);
    cout << "jumlah node : " << jumlahNode << endl;

    int totalInfo = hitungTotalInfo(root);
    cout << "total : " << totalInfo << endl;
    
    cout << "pre-order : ";
    PreOrder(root);
    cout << endl;

    cout << "post-order : ";
    PostOrder(root);
    cout << endl;

    return 0;
}