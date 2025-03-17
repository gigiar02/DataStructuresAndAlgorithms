#include <iostream>
#include <string>
#define TEMPLATE template<typename T>
#include <fstream>
#include <vector>

using namespace std;

TEMPLATE
class Node
{
    public:
        T data;
        int key;
        int value;

        Node(){}
        Node(int key,int value) : key(key), value(value){}
};
TEMPLATE
class hashTable
{
    public:
        vector<Node<T>*> table;
        int m;

        hashTable(int m) {table.resize(m,nullptr);}

        int hash(int key,int i)
        {
            return (key + i) % m;
        }

        void insert(Node<T>*& nodo)
        {
            int i = 0;
            int j = hash(nodo->key,i);

            while(i < m)
            {
                if(table[j] == nullptr)
                {
                    table[j] = nodo;
                    return;
                }
                i++;
                j = hash(nodo->key,i);
            }
        }

        Node<T>* find(int key)
        {
            int i = 0;
            int j = hash(key,i);

            while(i < m)
            {
                if(table[j]->key == key)
                {
                    return table[j];
                }

                i++;
                j = hash(key,i);
            }

            return nullptr;
        }


        void Delete(int key)
        {
            int i = 0;
            int j = hash(key,i);

            while(i < m)
            {
                if(table[j]->key == key)
                {
                    delete table[j];
                    table[j] = nullptr;
                    return;
                }

                i++;
                j = hash(key,i);
            }


        }

        void Popola()
        {
            ifstream in("Esercizi/read.txt");

            int key,value;

            while(in>>key>>value)
            {
                Node<T>* nodo = new Node<T>(key,value);
                insert(nodo);
            }

            ofstream out("Esercizi/out.txt");

            for(auto& x : table)
            {
                if(x != nullptr)
                {
                    out<<x->key<<" "<<x->value<<endl;
                }
            }
            out.close();
        }


};
