//#include "HashTable/hash.hpp"
#include "Esercizi/Componenti_connesse/lib.hpp"





class P
{
    public:
    int key;
    int distance = 0;
    Color color = Color::WHITE;
};


int main()
{

   Grafo<P> G;
   G.popola();
   G.calcolaComponentiConnesse();



    return 0;
}
