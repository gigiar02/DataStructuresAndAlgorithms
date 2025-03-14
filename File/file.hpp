#include "../Grafo/Grafo.hpp"
#include <stack>
//Tipo di operazione che si vuole effettuare sul grafo
enum class type
{
    BFS,
    DFS,
    PRIM,
    NOTHING,
    CICLO_HAMILTONIANO,
    DFS_TOPOLOGICA

};


//Tipo di file
enum class fileType
{
    //File con numeri separati da uno spazio. Nella prima riga ci sono il nuumero di nodi e di arhci
    NUMBER_FILE,
    //File ove ogni riga contiene <"Nome","Cognome","Key"> <"Nome","Cognome","Key"> Peso(int)
    DATA_FILE
};

//Ottieni il percorso per il file selezionato
std::string getFileName(fileType path)
{
    switch(path)
    {
        case fileType::NUMBER_FILE :
            return "File/graph.txt";
            break;
        case fileType::DATA_FILE :
            return "File/data.txt";
            break;

    }
}

//Popola un grafo attraverso un file ed esegue un'operazione a scelta dell'utente. Stampa infine il risultato nel file
//out.txt
TEMPLATE
void popolaGrafo(fileType path,type operation);

//Esegui una bfs e scrivi su file il risultato
TEMPLATE
void BFS_FILE(Grafo<T>& G);

TEMPLATE
void verificaCiclo(Grafo<T>& G);

TEMPLATE
bool CICLO_HAMILTONIANO(Grafo<T>& G,std::ofstream& out,node<T>*& start,node<T>*& current,int total);

TEMPLATE
void DfsTopologica(Grafo<T>& G);




#include "file.tpp"
