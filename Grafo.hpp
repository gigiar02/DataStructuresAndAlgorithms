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
    Edge(node<T>*& x,node<T>*& y)
    {
        this->x = x;
        this->y = y;
        //Aggiugiamo un nuovo nodo ad x
        x->addChild(y);
    }

    node<T>* getX(){return x;}
    node<T>* getY(){return y;}
};


//Classe grafo: vertici + archi
TEMPLATE
class Grafo{
    //Vertici del grafo. Da notare che l ID del nodo permette di accedere
    //ad un vertice nello specifico
    std::vector<node<T>*> vertex;
    //Archi del grafo
    std::vector<Edge<T>*> edges;
    //Contatore ID
    int ID;


    public:

        Grafo(){ID = 0;}

        //Aggiunge un nuovo vertice al grafo
        int addVertex(T& data);

        //Aggiunge un arco al grafo
        int addEdge(int ID1,int ID2);

        //Metodi per stampare un singolo vertice o tutti i vertici del grafo
        void printData();
        void print(int ID);

        //Esegue la BFS partendo da un vertice x. Restituisce i cammini minimi di ogni vertice dalla sorgente
        std::vector<int> BFS(int ID,AB<T>& tree);

        //Esegue la dfs visit prendendo in input un nodo da cui partire e i tempi di fine e di inizio
        void DFS_VISIT(node<T>*& v,std::vector<int>& I,std::vector<int>& F,int &TIME);
        //Esegue la DFS e restituisce i tempi di inizio e di fine
        void DFS(std::vector<int>& I, std::vector<int>& F);


};


#include "./Grafo/Grafo.tpp"
