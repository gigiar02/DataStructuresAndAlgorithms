/*
    Implementare Bfs,dfs,prim,djkstra,bellman ford. Nella dfs classificare tutti gli archi e restituire il numero di cicli presenti.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
#define TEMPLATE template<typename T,typename S>

enum class color
{
    WHITE,
    GRAY,
    BLACK
};

TEMPLATE
class node
{
    T key;
    S value;
    vector<node<T,S>*> adj;
    int distance;
    int START;
    int END;
    color col;
    node<T,S>* predecessor;

public:
        node<T,S>(T& key,S& value) : key(key), value(value){}
        node<T,S>(){}

        vector<node<T,S>*> gadj(){return adj;}
        T gkey(){return key;}
        S gvalue(){return value;}
        int gd(){return distance;}
        int gs(){return START;}
        int ge(){return END;}
        color gc(){return col;}
        node<T,S>* gp(){return predecessor;}

        void spredecessor(node<T,S>*& p){predecessor = p;}
        void sd(int d){distance = d;}
        void append(node<T,S>*& child){adj.push_back(child);}
        void sc(color c){col = c;}


};

TEMPLATE
node<T,S>* crea(T& key,S& value)
        {
            node<T,S>* nuovo = new node<T,S>(key,value);
            return nuovo;
        }

 TEMPLATE
node<T,S>* crea()
{
            node<T,S>* nuovo = new node<T,S>();
            return nuovo;
}

TEMPLATE
class edge
{
public:
        pair<node<T,S>*,node<T,S>*> e;
        int weight;
};


TEMPLATE
class grafo
{
    vector<node<T,S>*> V;
    vector<edge<T,S>*> E;

public:
    node<T,S>* findv(T key,S value)
    {
       for(auto &x : V)
       {
           if(x->gkey() == key)
           {
               return x;
           }
       }

       node<T,S>* creato = crea(key,value);
       V.push_back(creato);
       return creato;
    }

    void adduedge(T& key1,S& value1,T& key2,S& value2)
    {
        node<T,S>* x =  findv(key1,value1);
        node<T,S>* y =  findv(key2,value2);

        x->append(y);
        y->append(x);
    }

    void popola()
    {
        ifstream in("Esercizi/read.txt");

        T key,key2;
        S value,value2;
        char appoggio;

        while(in>>appoggio>>key>>appoggio>>value>>appoggio>>key2>>appoggio>>value2)
        {
            value.erase(value.size()-1,1);
            value2.erase(value2.size()-1,1);
            adduedge(key,value,key2,value2);
        }

        ofstream out("Esercizi/out.txt");

        for(auto& x : V)
        {
            T key = x->gkey();
            S value = x->gvalue();
            out<<" Key: "<<key<<" Value "<<value<<endl;
        }

        out.close();
    }

    void BFS(T y)
    {
        queue<node<T,S>*> Q;
        fstream out;
        out.open("Esercizi/out.txt",ios::out|ios::app);
        out<<endl;
        for(auto& x : V)
        {
            x->sc(color::WHITE);
            node<T,S>* m = nullptr;
            x->spredecessor(m);
            x->sd(INT_MAX);
        }

        S value;
        node<T,S>* s = findv(y,value);
        s->sc(color::GRAY);
        node<T,S>* m = nullptr;
        s->spredecessor(m);
        s->sd(0);
        Q.push(s);


        while(!Q.empty())
        {
            node<T,S>* u = Q.front();
            if(u->gp())
            {
                T key,key2;
                key = u->gp()->gkey();
                key2 = u->gkey();
                out<<" s: "<<key<<" d: "<<key2<<" distanza da nodo partenza: "<<u->gd()<<endl;
            }

            Q.pop();

            for(auto &v : u->gadj())
            {
                if(v->gc() == color::WHITE)
                {
                    v->sc(color::GRAY);
                    v->sd(u->gd() + 1);
                    v->spredecessor(u);
                    Q.push(v);
                }
            }

            u->sc(color::BLACK);
        }


        out.close();

    }



};

