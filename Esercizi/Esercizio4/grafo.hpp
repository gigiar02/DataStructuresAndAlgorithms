/*
    Implementare un grafo utilizzando le hashtable con concatenamento. Implementare le operazioni di inserimento ricerca e cancellazione.
*/
#include <iostream>
#include <string>
#include <queue>
#define TEMPLATE template<typename T,typename S>
#include <fstream>
using namespace std;

TEMPLATE
class Node
{
    T key;
    S value;
    vector<Node<T,S>*> adj;

public:

    Node(){}
    Node(T key,S value) : key(key), value(value) {}

    T getKey(){return key;}
    S getValue(){return value;}
    vector<Node<T,S>*> getAdj(){return adj;}

    static Node<T,S>* crea(T key, S value)
    {
        Node<T,S>* nuovo = new Node<T,S>(key,value);
        return nuovo;
    }

    void add(T key, S value)
    {
        Node<T,S>* nuovo = crea(key,value);
        adj.push_back(nuovo);
    }

};


TEMPLATE
class Edge
{
public:

    pair<Node<T,S>*,Node<T,S>*> edge;
    T edgeKey;
    int w;
};



TEMPLATE
class GrafoHash
{
    vector<vector<Node<T,S>*>> V;
    int V_size;
    vector<vector<Edge<T,S>*>> E;
    int E_size;


public:

    GrafoHash(int m)
    {
        V_size = m;
        E_size = m-1;

        //V.resize(V_size);
        //E.resize(E_size);

        for(int i = 0; i < V_size;i++)
        {
            vector<Node<T,S>*> nuovo;
            V.push_back(nuovo);
        }

        for(int i = 0; i < E_size;i++)
        {
            vector<Edge<T,S>*> nuovo;
            E.push_back(nuovo);
        }

    }

    int hashV(T key)
    {
        return key % V_size;
    }

    //Completamente inventato come tutto il resto :)
    int hashE(T edgeKey)
    {
        return (edgeKey) % E_size;
    }

    Node<T,S>* find_vertex(int key)
    {
        int j = hashV(key);
        if(key > V_size) return nullptr;

        for(auto& v : V[j])
        {
            if(v->getKey() == key)
            {
                return v;
            }
        }

        return nullptr;

    }

    Node<T,S>* add_vertex(T key,S value)
    {
        int j = hashV(key);
        Node<T,S>* x = Node<T,S>::crea(key,value);
        V[j].push_back(x);
        return x;
    }

    void add_edge(T key,S value,T key2,S value2,int w,T edgeKey)
    {
        Node<T,S>* x = find_vertex(key);
        Node<T,S>* y = find_vertex(key2);

        if(!x) x = add_vertex(key,value);
        if(!y) y = add_vertex(key2,value2);

        x->add(key2,value2);

        Edge<T,S>* e = new Edge<T,S>();
        e->edge.first = x;
        e->edge.second = y;
        e->w = w;
        e->edgeKey = edgeKey;

        int j = hashE(edgeKey);

        E[j].push_back(e);

    }


    void popola()
    {
        ifstream in("Esercizi/read.txt");
        T key,key2,key_edge;
        S value,value2;
        int w;


        while(in>>key>>value>>key2>>value2>>w>>key_edge)
        {
            this->add_edge(key,value,key2,value2,w,key_edge);
        }

        in.close();
    }


    void print()
    {
        for(auto &x: V)
        {
            for(auto &y:x)
            {
                cout<<"v = "<<y->getKey()<<" value: "<<y->getValue()<<endl;
            }
        }
    }
};




