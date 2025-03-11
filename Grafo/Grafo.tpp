//Classe grafo: vertici + archi

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


    //Crea un nuovo arco
    edges[{x,y}] = W;
    x->addChild(y);


}


//Aggiunge un arco attraverso la sua key
TEMPLATE
void Grafo<T>::addEdge(int key1,int key2,int W)
{
    bool eKey1 = false;
    bool eKey2 = false;
    T data1,data2;

    data1.key = key1;
    data2.key = key2;

    node<T>* nKey1 = new node<T>(data1);
    node<T>* nKey2 = new node<T>(data2);

    for(auto& x : this->vertex)
   {
       //Se esiste già il nodo di cui vuoi creare un arco
       if(x->getData().key == key1)
       {
           eKey1 = true;
           nKey1 = x;
       }

       if(x->getData().key == key2)
       {
           eKey2 = true;
           nKey2 = x;
       }

   }

   //Aggiungi l'arco
   this->addEdge(nKey1,nKey2,W);
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

//Trova un' MST(Minimum Spanning Tree)
TEMPLATE
void Grafo<T>::Prim(node<T>*& s)
{
    //Queue di minima priorità
    std::priority_queue<node<T>*,std::vector<node<T>*>,Compare<T>> Q;
    std::vector<node<T>*> vertex = this->getVertex();
    node<T>* u = new node<T>();
    std::unordered_map<std::pair<node<T>*,node<T>*>, int,PairHash> mst;
    node<T>* f;
    node<T>* node = nullptr;
    std::string buff = "PRE PRIM \n";
    std::string key;
    std::string predecessor;
    std::string distance;
    std::string edge;

    //Setta la distanza rispetto ad s
    for(auto& x : this->getVertex())
    {
        if(x != s)
        {
            x->getData().distance = INT_MAX;
            x->setFather(node);
            x->getData().extracted = false;
        }
    }

    s->getData().distance = 0;
    s->setFather(node);

    for(auto& x : vertex)
    {
        key = std::to_string(x->getData().key);
        distance = std::to_string(x->getData().distance);
        predecessor = "NULLPTR";
        buff += "KEY : " + key + " DISTANCE " + distance + " PREDECESSOR " + predecessor + "\n";
        Q.push(x);
    }

    for (const auto& [key, value] : edges) {
        std::cout << "Chiave: (" << key.first << ", " << key.second << ") "
                  << "Valore: " << value << std::endl;
    }

    //std::unordered_map<std::pair<node<T>*,node<T>*>, int,PairHash> mst;
    buff += " After Prim: \n";
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        if(u->getFather() && !u->getData().extracted)
        {
            mst[{f,u}] = edges[{f,u}];
            f = u->getFather();
            key = std::to_string(u->getData().key);
            std::string key2 = std::to_string(f->getData().key);
            edge = std::to_string(edges[{f,u}]);

            //Aggiorno il numero di figli del padre
            f->getData().numChild++;

            //
            std::string numChild = std::to_string(f->getData().numChild);

            //Aggiungo al buffer l'arco del mst
            buff += " u: " + key2 + " v: " + key + " weight: " + edge + "NUMERO FIGLI PADRE: " + numChild +  " \n";

        }
        u->getData().extracted = true;
        for(auto& v : u->getChildren())
        {
            //Se v non è già stato estratto e w(u,v) < d[v]
            if(!v->getData().extracted && edges[{u,v}] < v->getData().distance)
            {

                //Imposto la distanza
                v->getData().distance = edges[{u,v}];

                //Imposto il predecessore v
                v->setFather(u);

                //Inserisco nella coda v in modo tale che possa essere estratto
                Q.push(v);
            }
        }

    }


    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Errore nell'apertura del file");
    }

    out << buff;
    out.close();








}
