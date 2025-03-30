#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
using namespace std;

#define TEMPLATE template<typename T>


enum class Color
{
    WHITE,
    GRAY,
    BLACK,
};


TEMPLATE
class Node
{
    //Data
    T payLoad;
    vector<Node<T>*> adj;
    Node<T>* p;

public:

    //Constructor
    Node(T data) : payLoad(data) { p = nullptr;}

    //Getter
    Color             getColor()       {return payLoad.color;}
    vector<Node<T>*>  getChildren()    {return adj;}
    Node<T>*          getParent()      {return p;}
    int               getKey()         {return payLoad.key;}
    int               getDistance()    {return payLoad.distance;}

    //Setters
    void              setColor(Color color)         {payLoad.color = color;}
    void              setParent(Node<T>*& parent)   {p = parent;}
    void              resetParent()                 {p = nullptr;}
    void              setKey(int key)               {payLoad.key = key;}
    void              setDistance(int d)            {payLoad.distance = d;}
    void              addChild(Node<T>*& child)     {adj.push_back(child);}
};


TEMPLATE
class Edge
{
public:

    pair<Node<T>*,Node<T>*> edge;
    int W;

    Edge(Node<T>*& x, Node<T>*& y, int W)
    {
        x->addChild(y);
        edge.first  =  x;
        edge.second =  y;
        this->W = W;

    }
};

TEMPLATE
class Grafo
{
    vector<Node<T>*> V;
    vector<Edge<T>*> E;

public:

    Node<T>* addNode(int key)
    {
        T data;
        data.key = key;
        V.push_back(new Node<T>(data));

        cout<<"[+] Aggiunta avvenuta con successo: "<<V[V.size()-1]->getKey()<<endl;
        return V[V.size()-1];
    }


    Node<T>* findNode(int key)
    {
        for(auto &x : V)
        {
            if(x->getKey() == key)
            {
                return x;
            }
        }

        return nullptr;
    }


    void addEdge(int key1,int key2,int w)
    {
        Node<T>* x = findNode(key1);
        Node<T>* y = findNode(key2);

        if(!x) x = addNode(key1);
        if(!y) y = addNode(key2);

        x->addChild(y);
        Edge<T>* e = new Edge<T>(x,y,w);
        E.push_back(e);

        cout<<"x = "<<x->getKey()<<" y = "<<y->getKey()<<endl;
    }

    void popola()
    {
        ifstream file("Esercizi/Componenti_Connesse/pop.txt");
        if(!file)
        {
            perror("Errore durante l'apertura del file: ");
            return;
        }

        int key1,key2,W;
        while(file>>key1>>key2>>W)
        {
            this->addEdge(key1,key2,W);
        }

    }


    void printGrafo()
    {
        for(auto& x : E)
        {
            pair<Node<T>*,Node<T>*> ed = x->edge;
            cout<<" x: "<<ed.first->getKey()<<" y: "<<ed.second->getKey()<<endl;
        }
    }

    Grafo calcolaTrasposta()
    {
        Grafo trasp;
        for(auto &x : E)
        {
            pair<Node<T>*,Node<T>*> ed = x->edge;
            trasp.addEdge(ed.second->getKey(),ed.first->getKey(),x->W);
        }
        return trasp;
    }

    dfsVisit(Node<T>*& v,stack<Node<T>*>& s,int &TIME)
    {
        TIME += 1;
        v->setColor(Color::GRAY);


        for(auto & x : v->getChildren())
        {
            if(x->getColor() == Color::WHITE)
            {
                x->setParent(v);
                dfsVisit(x,s,TIME);
            }
        }

        v->setColor(Color::BLACK);
        TIME += 1;
        s.push(v);
    }


    stack<Node<T>*> dfs()
    {
        for(auto &x : V)
        {
            x->setColor(Color::WHITE);
            x->resetParent();
        }

        stack<Node<T>*> s;
        int TIME = 0;
        for(auto &v : V)
        {
            if(v->getColor() == Color::WHITE)
            {
                dfsVisit(v,s,TIME);
            }
        }
        return s;
    }

    void resettaVar()
    {
        for(auto &x : V)
        {
            x->setColor(Color::WHITE);
            x->resetParent();
        }
    }

    void dfs_visit2(Node<T>*& x,ofstream& out)
    {
        x->setColor(Color::GRAY);

        for(auto y: x->getChildren())
        {
            if(y->getColor() == Color::WHITE)
            {
                y->setColor(Color::GRAY);
                y->setParent(x);
                out<<"Componente: "<<y->getKey()<<endl;
                dfs_visit2(y,out);
            }
        }

        x->setColor(Color::BLACK);


    }
    void calcolaComponentiConnesse()
    {
        resettaVar();
        stack<Node<T>*> s = dfs();
        Grafo trasposta = calcolaTrasposta();
        ofstream out("Esercizi/Componenti_connesse/out.txt");

        while(!s.empty())
        {
            Node<T>* u = trasposta.findNode(s.top()->getKey());
            if(u->getColor() == Color::WHITE)
            {
                out<<"Radice: "<<u->getKey()<<endl<<endl;
            }
            s.pop();

            for(auto &x : u->getChildren())
            {
                if(x->getColor() == Color::WHITE)
                {
                    dfs_visit2(x,out);
                }
            }
        }
        out.close();
    }


};
