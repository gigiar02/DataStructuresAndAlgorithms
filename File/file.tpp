
TEMPLATE
void BFS_FILE(Grafo<T>& G)
{
    //Apro il file su cui scrivere in output
    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Il file per la scrittura out.txt non � stato aperto correttamente");
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

TEMPLATE
void dfsVisit(node<T>*& u,std::stack<node<T>*>& S,int TIME)
{
    TIME += 1;
    u->getData().START = TIME;
    u->setColor(GRAY);

    for(auto& v : u->getChildren())
    {
        if(v->getColor() == WHITE)
        {
            dfsVisit(v,S,TIME);
        }
    }

    TIME += 1;
    u->getData().END = TIME;
    u->setColor(BLACK);

    //Aggiungi u allo stack
    S.push(u);

}


//DFS TOPOLOGICA
TEMPLATE
void DfsTopologica(Grafo<T>& G)
{
    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Errore durante l'apertura del file");
        return;
    }
   //Stack in cui avr� gli elementi ordinati in maniera topologica
   std::stack<node<T>*> S;
   std::vector<node<T>*> vertex = G.getVertex();

   //Inizializzazione
   for(auto& v : vertex)
   {
       v->setColor(WHITE);
       v->getData().START = 0;
       v->getData().END = 0;
   }
   int TIME = 0;
   for(auto& v : vertex)
   {
       if(v->getColor() == WHITE)
       {
           dfsVisit(v,S,TIME);
       }
   }

   //Scrittura su file di output
   while(!S.empty())
   {
       node<T>* x = S.top();
       int key = x->getData().key;
       int START = x->getData().START;
       int END = x->getData().END;

       out<<" NODO : "<<key<<" START "<<START<<" END "<<END<<std::endl;
       S.pop();
   }

   out.close();

}


//Verifica se nel grafo c'� almeno un ciclo hamiltoniano. Se ci� � vero stampa tutti i nodi di tale ciclo
TEMPLATE
bool CICLO_HAMILTONIANO(Grafo<T>& G,std::ofstream& out,node<T>*& start,node<T>*& current,int total)
{
    current->setColor(GRAY);
    int key = current->getData().key;


    for(auto& v : current->getChildren())
    {

        //Se il nodo corrente � l'ultimo nodo e ha come figlio il nodo di partenza
        if(v == start && total == G.getVertex().size())
        {
            int key = v->getData().key;
            out<<" Ultimo nodo: "<<key<<" \n";
            return true;
        }

        //Se il nodo non � stato visitato
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
                out<<"� un ciclo hamiltoniano \n";
                return;
            }
        }
    }

    out<<"Non � un ciclo hamiltoniano";
    out.close();
}


void estraiNomeCognome(std::string& appoggio1,std::string& nome,std::string& cognome)
{
    appoggio1 = appoggio1.erase(0,1);

    std::string appoggio2;
    for(auto c : appoggio1)
    {
         if(c == ',')
         {
            nome = appoggio2;
            std::cout<<"Nome "<<nome<<std::endl;
            appoggio2 = "";

         }else if(c == '>')
         {
             cognome = appoggio2;
             std::cout<<"Cognome "<<cognome<<std::endl;
         }else
         {
            appoggio2 += c;
         }

    }
}


//<nome,cognome> key <nome,cognome> key W
TEMPLATE
Grafo<T> dataFileExtraction()
{
    std::string path = getFileName(fileType::DATA_FILE);
    std::ifstream in(path);
    std::string appoggio1;
    std::string nome1;
    std::string cognome1;
    int key1;
    std::string appoggio2;
    std::string nome2;
    std::string cognome2;
    int key2;
    int W;

    Grafo<T> G;
    if(!in)
    {
        perror("Errore durante la creazione del file");
    }

    while(in>>appoggio1>>key1>>appoggio2>>key2>>W)
    {
        std::cout<<appoggio1<<key1<<appoggio2<<key2<<W<<std::endl;
        estraiNomeCognome(appoggio1,nome1,cognome1);
        estraiNomeCognome(appoggio2,nome2,cognome2);

        T data1,data2;

        data1.key = key1;
        data1.nome = nome1;
        data1.cognome = cognome1;

        data2.key = key2;
        data2.nome = nome2;
        data2.cognome = cognome2;

        G.addUnorientedEdge(data1,data2,W);

    }

    return G;
}


TEMPLATE
Grafo<T> numberFileExtraction()
{
    std::string row;
    int num_nodi;
    int num_archi;
    std::string name = getFileName(fileType::NUMBER_FILE);
    //Apri il file in lettura
    std::ifstream inFile(name);
    Grafo<T> G;
    if(!inFile)
    {
        perror("Errore nell' apertura del file");
    }

    //La prima riga contiene il numero di nodi e di archi
    //getline(inFile,row);
    inFile>>num_nodi;
    inFile>>num_archi;


    //Nelle righe successive trover� "sorgente  destinazione  peso"
    int key1;
    int key2;
    int W;
    while(inFile>>key1>>key2>>W)
    {

        T data1,data2;
        std::size_t pos;

        //Estrazione dati nodi
        data1.key = key1;
        data2.key = key2;

        G.addUnorientedEdge(data1.key,data2.key,W);
    }

    //Chiudo il file per la lettura
    inFile.close();

    return G;
}
//Estrazione dati
TEMPLATE
Grafo<T> estrazioneDati(fileType path)
{
    Grafo<T> G;
    switch(path)
    {
        case fileType::NUMBER_FILE:
            G = numberFileExtraction<T>();
            return G;
            break;
        case fileType::DATA_FILE:
            G = dataFileExtraction<T>();
            return G;
            break;
        default:
            G = numberFileExtraction<T>();
            return G;
            break;

    }
}


TEMPLATE
void popolaGrafo(fileType path,type operation)
{
    Grafo<T> G = estrazioneDati<T>(path);
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
        case type::DFS_TOPOLOGICA :
            DfsTopologica(G);
            break;
        default:
            break;
    }




}



