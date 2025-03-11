#include "../File/file.hpp"
#define t template<typename T,typename S>
//Implementazione hash table

t
class item{

    public:
    T key;
    S value;

    item(T key,S value) : key(key), value(value){}


};

t
class hashTable
{
    public:
        std::vector<item<T,S>*> table;
        int m;

        hashTable(int m) : m(m)
        {
            //Definizione della dimensione del vettore
            //e inizializzazione dei suoi elementi a nullptr
            table.resize(m,nullptr);
        }

        //Funzione di hash per mappare gli elementi
        int hash(T key,int i);

        //Inserisci un elemento
        void insert(item<T,S>*& it);

        //Cerca una chiave
        item<T,S>* find(T key);

        //Rimuovi un elemento
        void remove(T key);

        //Stampa hash
        void print(std::ofstream &out);


};



#include "hash.tpp"






