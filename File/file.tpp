
TEMPLATE
void BFS_FILE(Grafo<T>& G)
{
    //Apro il file su cui scrivere in output
    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Il file per la scrittura out.txt non è stato aperto correttamente");
    }

    std::string fileout = " Before BFS \n ";

    std::vector<node<T>*> v = G.getVertex();

    //Distanze prima della bfs
    for(auto& x : v)
    {

        std::string key = std::to_string(x->getData().key);
        std::string distance = std::to_string(x->getData().distance);
        fileout = fileout + " KEY: " + key  + " DISTANCE " + distance + " \n";
    }

    fileout = fileout + " After BFS : \n ";

    G.BFS(v[0]);

    for(auto& x : v)
    {

        std::string key = std::to_string(x->getData().key);
        std::string distance = std::to_string(x->getData().distance);
        std::string father = "NULL";
        if(x->getFather())
        {
            father = std::to_string(x->getFather()->getData().key);
        }


        fileout = fileout + " KEY: " + key  + " DISTANCE " + distance +  " PREDECESSOR: " + father + " \n";
    }


    out << fileout;

    out.close();
}

//Operazione DFS
TEMPLATE
void DFS_FILE(Grafo<T>& G)
{
    std::ofstream out("File/out.txt");
    std::string buff = "PRE DFS \n";
    if(!out)
    {
        perror("Errore nell'apertura del file");
    }

    std::vector<node<T>*> vert = G.getVertex();

    for(auto& v : vert)
    {
        std::string s = std::to_string(v->getData().START);
        std::string f = std::to_string(v->getData().END);
        std::string key = std::to_string(v->getData().key);
        std::string p = "NULL";
        if(v->getFather())
        {
            p = std::to_string(v->getFather()->getData().key);
        }

        buff += " KEY = " + key + " START = " + s + " END = " + f + " PREDECESSOR = " + p + "\n";
    }

    G.DFS();

    buff += "POST DFS \n";
    for(auto& v : vert)
    {
        std::string s = std::to_string(v->getData().START);
        std::string f = std::to_string(v->getData().END);
        std::string key = std::to_string(v->getData().key);
        std::string p = "NULL";
        if(v->getFather())
        {
            p = std::to_string(v->getFather()->getData().key);
        }

        buff += " KEY = " + key + " START = " + s + " END = " + f + " PREDECESSOR = " + p + "\n";
    }

    out << buff;
    out.close();

}


//Verifica se nel grafo c'è almeno un ciclo hamiltoniano. Se ciò è vero stampa tutti i nodi di tale ciclo
TEMPLATE
bool CICLO_HAMILTONIANO(Grafo<T>& G,std::ofstream& out,node<T>*& start,node<T>*& current,int total)
{
    current->setColor(GRAY);
    int key = current->getData().key;


    for(auto& v : current->getChildren())
    {

        //Se il nodo corrente è l'ultimo nodo e ha come figlio il nodo di partenza
        if(v == start && total == G.getVertex().size())
        {
            int key = v->getData().key;
            out<<" Ultimo nodo: "<<key<<" \n";
            return true;
        }

        //Se il nodo non è stato visitato
        if(v->getColor() == WHITE)
        {
            if(CICLO_HAMILTONIANO(G,out,start,v,total+1))
            {
                int key = v->getData().key;
                out<<" Nodo interno: "<<key<<" \n";
                return true;
            }
        }
    }

    current->setColor(WHITE);
    return false;
}


TEMPLATE
void verificaCiclo(Grafo<T>& G)
{
    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Errore nell' apertura del file");
        return;
    }

    for(auto& u : G.getVertex())
    {
        if(u->getColor() == WHITE)
        {
            if(CICLO_HAMILTONIANO(G,out,u,u,1))
            {
                out<<"è un ciclo hamiltoniano \n";
                return;
            }
        }
    }

    out<<"Non è un ciclo hamiltoniano";
    out.close();
}



TEMPLATE
void popolaGrafo(std::string path,type operation)
{
    Grafo<T> G;
    std::string row;
    int num_nodi;
    int num_archi;

    //Apri il file in lettura
    std::ifstream inFile(path);
    if(!inFile)
    {
        perror("Errore nell' apertura del file");
    }

    //La prima riga contiene il numero di nodi e di archi
    getline(inFile,row);
    try
    {
        std::size_t current_pos;
        num_nodi = std::stoi(row,&current_pos);
        num_archi = std::stoi(row.substr(current_pos),&current_pos);


    }
    catch(int err){
        perror("Inserisci correttamente il numero di nodi e di archi");
    }

    //Nelle righe successive troverò "sorgente  destinazione  peso"
    while(getline(inFile,row))
    {
        T data1,data2;
        int W;
        std::size_t pos;

        //Estrazione dati nodi
        data1.key = std::stoi(row,&pos);
        data2.key = std::stoi(row.substr(pos),&pos);
        W =  std::stoi(row.substr(pos + 1),&pos);

        //Creazione ed inserimento nodi
        //node<T>* first = new node<T>(data1);
        //node<T>* second = new node<T>(data2);

        //Crea arco non orientato
        G.addUnorientedEdge(data1.key,data2.key,W);
        //G.addEdge(data2.key,data1.key,W);

    }

    //Chiudo il file per la lettura
    inFile.close();
    std::vector<node<T>*> v = G.getVertex();
    //Fase di scelta tra le diverse operazioni
    switch(operation)
    {
        case type::BFS :
            BFS_FILE(G);
            break;
        case type::DFS :
            DFS_FILE(G);
            break;
        case type::PRIM :
            G.Prim(v[0]);
            break;
        case type::NOTHING :
            break;
        case type::CICLO_HAMILTONIANO :
            verificaCiclo(G);
            break;
        default:
            break;
    }




}



