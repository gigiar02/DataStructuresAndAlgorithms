//#include "HashTable/hash.hpp"
#include "Esercizi/Esercitazione3/djkstra.hpp"





class P
{

};


int main()
{

    grafo<int,string> g;
    g.popola();
    g.BFS(1);
    g.DFS();
    g.prim(1);
    g.djkstra(1);
    g.bellmanFord(1);



    return 0;
}
