#include "Grafo.hpp"

int main()
{
    std::vector<int> vt = {1,100,200,300};
    Grafo<int> graph;

    for(auto h : vt)
    {
        graph.addVertex(h);
    }

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);

    std::cout<<" Inizio stampa"<<std::endl;

    graph.printData();
    std::vector<int> I;

    AB<int> tree;
    I = graph.BFS(0,tree);
    for(auto inizio : I)
    {
        std::cout<<"I: "<<inizio<<std::endl;
    }
    tree.printChildren(2);





    return 0;
}
