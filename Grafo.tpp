

TEMPLATE
//Aggiunge un nuovo vertice al grafo
int  Grafo<T>::addEdge(int ID1,int ID2)
{
    //L' ID passato in input non puo essere piu grande dell' id globale poiché non si accederebbe sicuramente ad un nodo
    if(ID1 > ID && ID2 > ID)
    {
        return -1;
    }
    node<T>* vertex1 = vertex[ID1];
    node<T>* vertex2 = vertex[ID2];
    Edge<T>* newEdge = new Edge(vertex1,vertex2);
    edges.push_back(newEdge);
    return 1;
}


TEMPLATE
//Aggiunge un arco al grafo
int Grafo<T>::addVertex(T& data)
{
    //Crea un nuovo nodo contenete il payLoad preso in input
    node<T>* newNode = new node(data);
    //Imposta l ID del nuovo nodo
    newNode->setID(ID);
    ID++;
    //Inserisci il nuovo nodo nella lista dei vertici
    vertex.push_back(newNode);
    //L'ID serve a poter accedere a un nodo in seguito
    return newNode->getID();
}


TEMPLATE
void Grafo<T>::printData()
{
    for(auto v : vertex)
    {
        std::cout<<"ID = "<<v->getID()<<" data:"<<v->getData()<<std::endl;
    }
}


TEMPLATE
void Grafo<T>::print(int ID)
{
    std::cout<<"ID = "<<ID<<" data: "<<vertex[ID]->getData()<<std::endl;
}


TEMPLATE
//Esegue la BFS partendo da un vertice x. Restituisce i cammini minimi di ogni vertice dalla sorgente
std::vector<int> Grafo<T>::BFS(int ID)
{
    //Avrei voluto fare un return di un nullptr ma da problemi
    //Se l'ID dato in input non è valido
    if (this->ID < ID)
    {
        std::vector<int> vuoto;
        return vuoto;
    }

    //Prendi il nodo da cui partire
    node<T>* sorgente = vertex[ID];
    //Creiamo la pila e il vettore che conterra tutte le distanze dalla sorgente
    std::vector<node<T>*> pila;
    std::vector<int> distance;

    //Inizializzazione di tutti i nodi ad eccezione della sorgente
    for(int i = 0; i < vertex.size(); i++)
    {
        distance.push_back(-1);
        vertex[i]->setColor(WHITE);
    }
    //Modifico il colore della sorgente
    sorgente->setColor(WHITE);
    distance[ID] = 0;
    pila.push_back(sorgente);

    //Eseguo il while finche la pila è piena
    while(pila.size() != 0)
    {
        //Estrai l' elemento dalla pila e cancellalo da quest' ultima
        node<T>* u = pila[0];
        pila.erase(pila.begin());

        //Scorri i figli adiacenti ad u
        for(const auto& v : u->getChildren())
        {
            if(v->getColor() == WHITE)
            {
                //Aggiungi all' albero

                //Modifica colore e distanza
                v->setColor(GRAY);
                distance[v->getID()] = distance[u->getID()] + 1;

                //Aggiungi il nodo v alla pila
                pila.push_back(v);
            }
        }

        u->setColor(BLACK);
    }

    return distance;

}


TEMPLATE
//Esegue la dfs visit prendendo in input un nodo da cui partire e i tempi di fine e di inizio
void Grafo<T>::DFS_VISIT(node<T>*& v,std::vector<int>& I,std::vector<int>& F,int &TIME)
{
    //Incremento il tempo
    TIME = TIME + 1;
    //Imposto il tempo di inizio del processo
    I[v->getID()] = TIME;
    //Il vertice è stato scoperto
    v->setColor(GRAY);

    //Vado a visitare gli adiacenti di v
    for(auto& adj : v->getChildren())
    {
        if(adj->getColor() == WHITE)
        {
            //Imposta il padre di adj nell'albero. Da fare!

            DFS_VISIT(adj,I,F,TIME);
        }
    }

    //Imposta il tempo di fine
    TIME = TIME + 1;
    F[v->getID()] = TIME;
    //Imposta il colore del nodo a Nero
    v->setColor(BLACK);
}


TEMPLATE
//Esegue la DFS e restituisce i tempi di inizio e di fine
void Grafo<T>::DFS(std::vector<int>& I, std::vector<int>& F)
{
    //Inizializzazione dei vertici
    for(auto& v : vertex)
    {
        I[v->getID()] = 0;
        F[v->getID()] = 0;
        v->setColor(WHITE);
    }
    //Il tempo globale inizialmente è a 0
    int TIME = 0;

    for(auto& v : vertex)
    {
        if(v->getColor() == WHITE)
        {
            //Esegui la Dfs visit per ogni vertice bianco
            DFS_VISIT(v,I,F,TIME);
        }
    }
}
