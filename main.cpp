#include "File/file.hpp"

class P
{
public:
    int key = 0;
    int distance = 0;
    int START = 0;
    int END = 0;
    bool extracted = false;
};


//Passo il nome del file
//Apro il file
//Prendo informazioni
//Scrivo nel file di output
int main()
{
    /*
    Grafo<P> andonio;
    node<P>* sorgente;
    std::vector<P> pkeys;
    P data,data1;
    data.key = 10;
    sorgente = andonio.addVertex(data);
    node<P>* ciao = new node<P>();
    data1.key = 4;
    ciao->setData(data1);
    andonio.addVertex(ciao);
    andonio.addEdge(sorgente,ciao);
    P data2;
    data2.key = 20;
    node<P>* h = andonio.addVertex(data2);
    andonio.addEdge(sorgente,h);

    andonio.DFS();
    andonio.printTime();
    */

    std::string path("File/graph.txt");
    type tipo = type::PRIM;
    popolaGrafo<P>(path,tipo);







    return 0;
}
