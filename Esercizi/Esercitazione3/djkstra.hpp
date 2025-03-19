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
int num_cicli = 0;
int num_indietro = 0;
int num_avanti = 0;
int num_albero = 0;
int num_trasversale = 0;
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
    bool ex = false;
    color col;
    node<T,S>* predecessor;
+
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
        bool gex(){return ex;}

        void spredecessor(node<T,S>*& p){predecessor = p;}
        void sd(int d){distance = d;}
        void append(node<T,S>*& child){adj.push_back(child);}
        void sc(color c){col = c;}
        void ss(int s){START = s;}
        void se(int e){END = e;}
        void sex(){ex = true;}
};


TEMPLATE
class Compare
{
    public:
        bool operator()(node<T,S>*& x,node<T,S>*& y)
        {
            return (x->gd() > y->gd());
        }
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

    void adduedge(T& key1,S& value1,T& key2,S& value2,int w)
    {
        node<T,S>* x =  findv(key1,value1);
        node<T,S>* y =  findv(key2,value2);

        x->append(y);
        y->append(x);
        edge<T,S>* ed = new edge<T,S>();
        ed->e.first = x;
        ed->e.second = y;
        ed->weight = w;

        E.push_back(ed);
    }

    void popola()
    {
        ifstream in("Esercizi/read.txt");

        T key,key2;
        S value,value2;
        char appoggio;
        int w;

        while(in>>appoggio>>key>>appoggio>>value>>appoggio>>key2>>appoggio>>value2>>w)
        {
            value.erase(value.size()-1,1);
            value2.erase(value2.size()-1,1);
            adduedge(key,value,key2,value2,w);
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


    void dfs_visit(node<T,S>*& u,int& TIME,fstream& out)
    {
        u->sc(color::GRAY);
        TIME++;
        u->ss(TIME);

        for(auto& v : V)
        {
            if(v->gc() == color::WHITE)
            {
                v->sc(color::GRAY);
                v->spredecessor(u);
                dfs_visit(v,TIME,out);

                num_albero++;

            }else if(v->gc() == color::GRAY)
            {
                num_cicli++;
            }else if(v->gc() == color::BLACK)
            {
                if(u->gs() >= v -> gs())
                {
                    num_trasversale++;
                }else
                {
                    num_avanti++;
                }
            }
        }

        u->sc(color::BLACK);
        TIME++;
        u->se(TIME);

        out<<"nodo = "<<u->gkey()<<" START: "<<u->gs()<<" END: "<<u->ge()<<endl;

    }


    void DFS()
    {
        fstream out;
        out.open("Esercizi/out.txt",ios::out|ios::app);

        out<<endl<<endl<<" DFS: "<<endl;

        for(auto& v : V)
        {
            v->sc(color::WHITE);
            node<T,S>* p = nullptr;
            v->spredecessor(p);
            v->ss(0);
            v->se(0);
        }
        int TIME = 0;

        for(auto& u : V)
        {
            if(u->gc() == color::WHITE)
            {
                dfs_visit(u,TIME,out);
            }
        }

        out<<"Albero: "<<num_albero<<" Avanti: "<<num_avanti<<" Indietro: "<<num_cicli<<" Tresversale: "<<num_trasversale<<endl;
        out.close();

    }



    edge<T,S>* finduedge(node<T,S>*& u,node<T,S>*& v)
    {
        for(auto& x : E)
        {
            if(x->e.first == u && x->e.second == v)
            {
                return x;
            }else if(x->e.first == v && x->e.second == u)
            {
                return x;
            }
        }

        return nullptr;
    }

    void prim(int key)
    {
        S value;
        node<T,S>* s = findv(key,value);
        fstream out;
        out.open("Esercizi/out.txt",ios::out|ios::app);

        priority_queue<node<T,S>*,vector<node<T,S>*>,Compare<T,S>> Q;

        out<<" PRIM: "<<endl;

        for(auto& x : V)
        {
            if(x != s)
            {
               x->sd(INT_MAX);
                node<T,S>* m = nullptr;
                x->spredecessor(m);
                Q.push(x);
            }
        }

        s->sd(0);
        node<T,S>* m = nullptr;
        s->spredecessor(m);
        Q.push(s);



        while(!Q.empty())
        {
            node<T,S>* u = Q.top();
            u->sex();

            if(u->gp())
            {
                T key = u->gp()->gkey();
                T key2 = u->gkey();
                S value;
                node<T,S>* f = findv(u->gp()->gkey(),value);
                int W = finduedge(f,u)->weight;
                out<<" u: "<<key<<" v: "<<key2<<" W: "<<W<<endl;
            }

            for(auto& v : u->gadj())
            {
                edge<T,S>* px = finduedge(u,v);

                int w = px->weight;
                if(!v->gex() && w < v->gd())
                {
                    v->sd(w);
                    v->spredecessor(u);
                }
            }
            Q.pop();
        }
        out.close();

    }

    void relax(node<T,S>*& u,node<T,S>*& v)
    {
        edge<T,S>* ed = finduedge(u,v);
        int w = ed->weight;

        if(w + u->gd() < v->gd())
        {
            v->sd(w + u->gd());
            v->spredecessor(u);
        }
    }
    void djkstra(int key)
    {
        fstream out;
        S value;
        node<T,S>* s = findv(key,value);
        out.open("Esercizi/out.txt",ios::out|ios::app);
        priority_queue<node<T,S>*,vector<node<T,S>*>,Compare<T,S>> Q;

        out<<endl<<endl<<" DJKSTRA: "<<endl<<endl;

        for(auto& v : V)
        {
            if(v != s)
            {
               v->sd(INT_MAX);
               node<T,S>* m = nullptr;
               v->spredecessor(m);
               Q.push(v);
            }
        }

        s->sd(0);
        node<T,S>* m = nullptr;
        s->spredecessor(m);
        Q.push(s);

        while(!Q.empty())
        {
            node<T,S>* u = Q.top();
            if(u->gp())
            {
               out<<" u: "<<u->gkey()<<" distance: "<<u->gd()<<endl;
            }
            Q.pop();

            for(auto& v : u->gadj())
            {
                relax(u,v);
            }
        }

        out.close();



    }

    void bellmanFord(int key)
    {
       fstream out;
       S value;
       node<T,S>* s = findv(key,value);
       out.open("Esercizi/out.txt",ios::out|ios::app);
       out<<" BELLMAN FORD: "<<endl;

       for(auto& v : V)
       {
           if(v != s)
           {
               v->sd(INT_MAX);
               node<T,S>* m = nullptr;
               v->spredecessor(m);
           }
       }

       s->sd(0);
       node<T,S>* m = nullptr;
       s->spredecessor(m);

       for(int i = 0; i < V.size()-2;i++)
       {
           for(auto& uv : E)
           {
               node<T,S>* u = uv->e.first;
               node<T,S>* v = uv->e.second;
               relax(u,v);
           }
       }

       for(auto& uv : E)
       {
            node<T,S>* u = uv->e.first;
            node<T,S>* v = uv->e.second;
               if(u->gd() + uv->weight < v->gd())
               {
                   out<<"Il ciclo è di peso negativo "<<endl;
                   return;
               }
      }

      for(auto& v : V)
       {
          out<<" node: "<<v->gkey()<<" distance: "<<v->gd()<<endl;
       }


        out.close();
    }



};

