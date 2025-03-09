#include <iostream>
#include <vector>
#define TEMPLATE template <typename T>
#include "Albero.hpp"


//Classe che rappresenta un arco ordinato del tipo (x,y);
TEMPLATE
class Edge
{
    node<T>* x;
    node<T>* y;
    int weight = 0;
    public:

    //Al costruttore passiamo il nodo x e il nodo y. Si farà puntare il nodo x al nodo y
    Edge(node<T>*& x,node<T>*& y,int W)
    {
        this->x = x;
        this->y = y;
        this->weight = W;
        //Aggiugiamo un nuovo nodo ad x
        x->addChild(y);
    }

    node<T>* getX(){return x;}
    node<T>* getY(){return y;}
};


//Classe grafo: vertici + archi
TEMPLATE
class Grafo{

    //Vertici del grafo.
    std::vector<node<T>*> vertex;
    //Archi del grafo
    std::vector<Edge<T>*> edges;

    public:

        Grafo(){}

        //Aggiunge un nuovo vertice al grafo
        node<T>* addVertex(node<T>*& newNode);
        node<T>* addVertex(T& data);
        std::vector<node<T>*> getVertex(){ return vertex;}
        //Aggiunge un arco al grafo
        void addEdge(node<T>*& one,node<T>*& two,int W);
        void addEdge(int key1,int key2,int W);

        //Metodi per stampare un singolo vertice o tutti i vertici del grafo
        void printDistance();
        void printTime();

        //Esegue la BFS partendo da un vertice x. Restituisce i cammini minimi di ogni vertice dalla sorgente
        void BFS(node<T>*& sorgente);

        //Esegue la dfs visit prendendo in input un nodo da cui partire e i tempi di fine e di inizio
        void DFS_VISIT(node<T>*& v,int &TIME);

        //Esegue la DFS e restituisce i tempi di inizio e di fine
        void DFS();


};


#include "./Grafo/Grafo.tpp"
