#include "graph.h" 
#include "graph.cpp"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A'); 
    adrNode B = InsertNode(G, 'B'); 
    adrNode C = InsertNode(G, 'C'); 
    adrNode D = InsertNode(G, 'D'); 
    adrNode E = InsertNode(G, 'E'); 
    ConnectNode(A, B);
    ConnectNode(A, C); 
    ConnectNode(B, D); 
    ConnectNode(C, D); 
    ConnectNode(D, E);

    cout << "=== GRAPH ===" << endl; 
    PrintInfoGraph(G);

    cout << "\nDFS mulai dari A: ";
    ResetVisited(G); 
    PrintDFS(G, A);

    cout << "\n\nBFS mulai dari A: "; 
    ResetVisited(G);
    PrintBFS(G, A);

    cout << endl; 
    return 0;
}
