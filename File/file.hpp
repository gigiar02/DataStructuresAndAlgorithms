#include "../Grafo/Grafo.hpp"
enum class type
{
    BFS,
    DFS,
    PRIM,
    NOTHING,
    CICLO_HAMILTONIANO

};
//Popola un grafo attraverso un file ed esegue un'operazione a scelta dell'utente. Stampa infine il risultato nel file
//out.txt
TEMPLATE
void popolaGrafo(std::string path,type operation);

//Esegui una bfs e scrivi su file il risultato
TEMPLATE
void BFS_FILE(Grafo<T>& G);


TEMPLATE
void verificaCiclo(Grafo<T>& G);



TEMPLATE
bool CICLO_HAMILTONIANO(Grafo<T>& G,std::ofstream& out,node<T>*& start,node<T>*& current,int total);


#include "file.tpp"
