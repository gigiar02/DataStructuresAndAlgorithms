
TEMPLATE
void popolaGrafo(std::string path)
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
        std::cout<<"data1 : "<<data1.key<<" data2: "<<data2.key<<" W: "<< W<<std::endl;

        //Creazione ed inserimento nodi
        //node<T>* first = new node<T>(data1);
        //node<T>* second = new node<T>(data2);

        //Crea arco non orientato
        G.addEdge(data1.key,data2.key,W);
        G.addEdge(data2.key,data1.key,W);

    }

    //Chiudo il file per la lettura
    inFile.close();

    //Apro il file su cui scrivere in output
    std::ofstream out("File/out.txt");
    if(!out)
    {
        perror("Il file per la scrittura out.txt non è stato aperto correttamente");
    }

    std::string fileout = " Before BFS \n";

    std::vector<node<T>*> v = G.getVertex();

    //Distanze prima della bfs
    std::cout<<"Distanza pre bfs"<<std::endl;
    for(auto& x : v)
    {

        std::string key = std::to_string(x->getData().key);
        std::string distance = std::to_string(x->getData().distance);
        std::cout<<"KEY: "<<key<<" DISTANCE: "<<distance<<std::endl;
        fileout = fileout + " KEY: " + key  + " DISTANCE " + distance + " \n";
    }

    fileout = fileout + " After BFS : \n";

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

        std::cout<<"KEY: "<<key<<" DISTANCE: "<<distance<<" PREDECESSOR: "<<father<<std::endl;;

        fileout = fileout + " KEY: " + key  + " DISTANCE " + distance +  " PREDECESSOR: " + father + " \n";
    }


    std::cout<<fileout<<std::endl;
    out << fileout;

    out.close();




}

