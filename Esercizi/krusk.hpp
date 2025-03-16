/*
    Dato un grafo pesato applicare kruscal per trovare un mst e restituire tutti gli archi che ne fanno parte
*/
#include <iostream>
#include <queue>
#include <string>
#define TEMPLATE template<typename T>
#include <map>
#include <fstream>
using namespace std;

TEMPLATE
class Node
{
    public:

        T data;
        int key;
        int rank;
        Node<T>* predecessor;
        vector<Node<T>*> adj;

};


TEMPLATE
class Edge
{
    public:
    pair<Node<T>*,Node<T>*> uv;
    int W;
};


TEMPLATE
class AB
{
    public:
        Node<T>* root;

};

TEMPLATE
class Compare
{
   public:
   bool operator()(Edge<T>* x,Edge<T>* y)
   {
      return x->W > y->W;
   }

};


TEMPLATE
class Graph
{
     public:
     vector<Node<T>*> V;
     vector<Edge<T>*> E;

     Node<T>* findNode(int key)
     {
         for(auto x : V)
         {
             if(x->key == key)
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

         if(!x)
         {
             x = new Node<T>();
             x->key = key1;
             V.push_back(x);
         }
         if(!y)
         {
             y = new Node<T>();
             y->key = key2;
             V.push_back(y);
         }

         x->adj.push_back(y);
         y->adj.push_back(x);

         Edge<T>* e = new Edge<T>();
         e->uv.first = x;
         e->uv.second =y;
         e->W = w;

         E.push_back(e);
     }



     void  PopolaGrafo()
     {

        ifstream in("Esercizi/read.txt");
        ofstream out("Esercizi/out.txt");

        int key1,value1,key2,value2;
        int W;

        out<<"Input: "<<endl;
        while(in>>key1>>value1>>key2>>value2>>W)
        {
            addEdge(key1,key2,W);
            out<<" Nodo s: "<<key1<<" Nodo d: "<<key2<<" W: "<<W<<endl;
        }

        in.close();
        out.close();



     }


    AB<T>* makeSet(Node<T>* x)
    {
        AB<T>* tree = new AB<T>();
        //Node<T>* y = new Node<T>();
        //y->key = x->key;
        x->predecessor = x;
        x->rank = 0;
        tree->root = x;
        return tree;
    }

    Node<T>* findSet(Node<T>* x)
    {
        Node<T>* y = x;
        while(y != y->predecessor)
        {
           y = y->predecessor;
        }

        return y;
    }

    AB<T>* Union(Node<T>* x,Node<T>* y)
    {
        Node<T>* rx = findSet(x);
        Node<T>* ry = findSet(y);

        AB<T>* n = new AB<T>();

        if(rx->rank > ry->rank)
        {
            ry->predecessor = rx;
            n->root = rx;
        }else
        {
            rx->predecessor = ry;
            n->root = ry;
            if(rx->rank == ry->rank)
            {
                ry->rank++;
            }
        }

        return n;

    }


     void Kruscal()
     {
         vector<AB<T>*> tree;
         priority_queue<Edge<T>*,vector<Edge<T>*>,Compare<T>> ord_edge;
         fstream out;
         out.open("Esercizi/out.txt",ios::out|ios::app);
         out<<"Helloooo"<<endl;


         for(auto& x : V)
         {
             AB<T>* t = makeSet(x);
             tree.push_back(t);
         }

          for(auto &x : E)
          {
            ord_edge.push(x);
          }

         out<<endl<<" Output "<<endl;
         while(!ord_edge.empty())
         {
             //cout<<" el: "<<ord_edge.top()->W<<endl;
             Node<T>* u = ord_edge.top()->uv.first;
             Node<T>* v = ord_edge.top()->uv.second;
             if(findSet(u) != findSet(v))
             {
                 Union(u,v);
                 out<<" u: "<<u->key<<" v: "<<v->key<<endl;
             }
             ord_edge.pop();

         }

         out.close();




     }
};



