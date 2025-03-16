#include <iostream>
#include <vector>
#include "../Albero.hpp"
#include <queue>
#include <climits>
#include <unordered_map>
#include <fstream>

TEMPLATE
class Compare
{
   public:
    bool operator()(const node<T>* a, const node<T>* b)
    {
        return a->getConstData().distance > b->getConstData().distance;
    }
};


//Classe grafo: vertici + archi
struct PairHash {
    template <typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ (std::hash<T2>()(pair.second) << 1);
    }
};

TEMPLATE
class Grafo{

    //Vertici del grafo.
    std::vector<node<T>*> vertex;

    //Archi del grafo
    std::unordered_map<std::pair<node<T>*,node<T>*>, int,PairHash> edges;

    public:

        Grafo(){}

        //Aggiunge un nuovo vertice al grafo
        node<T>* addVertex(node<T>*& newNode);
        node<T>* addVertex(T& data);
        std::vector<node<T>*> getVertex(){ return vertex;}
        //Aggiunge un arco al grafo
        void addEdge(node<T>*& one,node<T>*& two,int W);
        void addEdge(int key1,int key2,int W);
        void addUnorientedEdge(node<T>*& one,node<T>*& two,int W);
        void addUnorientedEdge(int key1,int key2,int W);
        void addUnorientedEdge(T& data1,T& data2,int W);

        //Metodi per stampare un singolo vertice o tutti i vertici del grafo
        void printDistance();
        void printTime();

        //Esegue la BFS partendo da un vertice x. Restituisce i cammini minimi di ogni vertice dalla sorgente
        void BFS(node<T>*& sorgente);

        //Esegue la dfs visit prendendo in input un nodo da cui partire e i tempi di fine e di inizio
        void DFS_VISIT(node<T>*& v,int &TIME);

        //Esegue la DFS e restituisce i tempi di inizio e di fine
        void DFS();

        //Esegue prim
        void Prim(node<T>*& s);


};

TEMPLATE
bool isBinaryTree(std::unordered_map<std::pair<node<T>*,node<T>*>,int>& map);


#include "Grafo.tpp"

