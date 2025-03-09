
TEMPLATE
//Aggiunge un arco al grafo
node<T>* Grafo<T>::addVertex(T& data)
{
    //Crea un nuovo nodo contenete il payLoad preso in input
    node<T>* newNode = new node(data);

    //Inserisci il nuovo nodo nella lista dei vertici
    vertex.push_back(newNode);
    return newNode;
}

TEMPLATE
//Aggiunge un arco al grafo
node<T>* Grafo<T>::addVertex(node<T>*& newNode)
{
    //Inserisci il nuovo nodo nella lista dei vertici
    vertex.push_back(newNode);
    return newNode;
}


TEMPLATE
//Aggiunge un nuovo vertice al grafo
void  Grafo<T>::addEdge(node<T>*& x,node<T>*& y,int W)
{
    bool v_x = false;
    bool v_y = false;

    //Controlla l'esistenza dei vertici e se non esistono già creali
    for( auto& nodo : this->vertex)
    {

        if(nodo == x)
        {
            v_x = true;
        }
    }

    if(!v_x)
    {
        this->addVertex(x);
    }

    for(auto& nodo : this->vertex)
    {
        //std::cout<<"Fin"<<std::endl;
        if(nodo == y)
        {
            v_y = true;
        }
    }

    if(!v_y)
        {
            this->addVertex(y);
        }


    //Crea un nuovo arco e aggiungilo alla lista di archi
    Edge<T>* newEdge = new Edge<T>(x,y,W);
    edges.push_back(newEdge);


}


TEMPLATE
void Grafo<T>::printDistance()
{
    for(auto v : vertex)
    {
        std::cout<<"ID = "<<v<<" data:"<<v->getData().key<<std::endl;
    }
}

TEMPLATE
void Grafo<T>::printTime()
{
    for(auto v : vertex)
    {
        std::cout<<"ID = "<<v<<" START: "<<v->getData().START<<" END: "<<v->getData().END<<std::endl;
    }
}


TEMPLATE
//Esegue la BFS partendo da un vertice x. Restituisce i cammini minimi di ogni vertice dalla sorgente
void Grafo<T>::BFS(node<T>*& sorgente)
{
    //Creiamo la pila e il vettore che conterra tutte le distanze dalla sorgente
    std::vector<node<T>*> pila;


    //Inizializzazione di tutti i nodi ad eccezione della sorgente
    for(int i = 0; i < vertex.size(); i++)
    {

        vertex[i]->setColor(WHITE);
    }

    //Modifico il colore della sorgente
    sorgente->setColor(GRAY);
    pila.push_back(sorgente);

    //Eseguo il while finche la pila è piena
    while(pila.size() != 0)
    {
        //Estrai l' elemento dalla pila e cancellalo da quest' ultima
        node<T>* u = pila[0];

        pila.erase(pila.begin());

        //Scorri i figli adiacenti ad u
        for(auto &v : u->getChildren())
        {
            if(v->getColor() == WHITE)
            {
                //Modifica colore e distanza
                v->setColor(GRAY);
                v->getData().distance = (u->getData().distance) + 1;

                //Il cammino minimo da s a v passa per u che sarà il predecessore di v
                v->setFather(u);
                //Aggiungi il nodo v alla pila
                pila.push_back(v);

            }
        }
        u->setColor(BLACK);
    }

}


TEMPLATE
//Esegue la dfs visit prendendo in input un nodo da cui partire e i tempi di fine e di inizio
void Grafo<T>::DFS_VISIT(node<T>*& v,int &TIME)
{
    //Incremento il tempo
    TIME = TIME + 1;

    //Imposto il tempo di inizio del processo
    v->getData().START = TIME;

    //Il vertice è stato scoperto
    v->setColor(GRAY);

    //Vado a visitare gli adiacenti di v
    for(auto& adj : v->getChildren())
    {
        if(adj->getColor() == WHITE)
        {
            //Imposta il padre di adj nell'albero
            adj->setFather(v);
            DFS_VISIT(adj,TIME);
        }
    }

    //Imposta il tempo di fine
    TIME = TIME + 1;
    v->getData().END = TIME;
    //Imposta il colore del nodo a Nero
    v->setColor(BLACK);
}


TEMPLATE
//Esegue la DFS e restituisce i tempi di inizio e di fine
void Grafo<T>::DFS()
{

    //Inizializzazione dei vertici
    for(auto& v : vertex)
    {
        v->setColor(WHITE);
    }
    //Il tempo globale inizialmente è a 0
    int TIME = 0;

    for(auto& v : vertex)
    {
        if(v->getColor() == WHITE)
        {
            //Esegui la Dfs visit per ogni vertice bianco
            DFS_VISIT(v,TIME);
        }
    }
}

