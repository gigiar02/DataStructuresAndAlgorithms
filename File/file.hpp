#include "../Grafo/Grafo.hpp"
#include <fstream>
enum class type
{
    BFS,
    DFS,
    PRIM,
    NOTHING
};
//Popola un grafo attraverso un file ed esegue un'operazione a scelta dell'utente. Stampa infine il risultato nel file
//out.txt
TEMPLATE
void popolaGrafo(std::string path,type operation);

//Esegui una bfs e scrivi su file il risultato
TEMPLATE
void BFS_FILE(Grafo<T>& G);


#include "file.tpp"
