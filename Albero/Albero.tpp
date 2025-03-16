

TEMPLATE
void treeDiscovery(std::map<char,std::string>& codifica,treeNode<T>*& root,std::string bit)
{
    if(root->getData().name != "-")
    {
        std::string h = root->getData().name;
        char z = h[0];
        codifica[z] = bit;
        return;
    }

    //Se hai figlio sinistro
    if(root->getLeft())
    {
        std::string leftBit = bit + "0";
        treeNode<T>* l = root->getLeft();
        treeDiscovery(codifica,l,leftBit);
    }

    if(root->getRight())
    {
        std::string RightBit = bit + "1";
        treeNode<T>* r = root->getRight();
        treeDiscovery(codifica,r,RightBit);
    }

}


//Restituisce l'albero di huffman
TEMPLATE
treeNode<T>* Codifica()
{
    std::ifstream in("File/huffman.txt");
    std::map<char,int> amap;

    char c;
    std::string h;

    while(in>>c)
    {
        amap[c]++;
    }

    std::priority_queue<treeNode<T>*,std::vector<treeNode<T>*>,Verifica<T>> Q;

    for(auto& x : amap)
    {
        T data;

        //frequenza
        data.f = x.second;

        //carattere
        data.name = x.first;

        treeNode<T>* nodo = new treeNode<T>(data);
        Q.push(nodo);
    }

    //Codifica
    const int sizeQ = Q.size();
    for(int i = 0; i < sizeQ - 1; i++)
    {
        //Creo il nodo z la cui frequenza sarà z = l.f + r.f
        T data;
        data.name = "-";
        treeNode<T>* l = Q.top();
        Q.pop();
        treeNode<T>* r = Q.top();
        Q.pop();
        data.f = l->getData().f + r->getData().f;

        treeNode<T>* z = new treeNode<T>(data);
        z->setLeft(l);
        z->setRight(r);

        std::cout<<" KEY F = "<<z->getData().f<<" KEY L = "<<l->getData().f<<" KEY R = "<<r->getData().f<<" i "<<i<<std::endl;
        Q.push(z);

    }
    Q.pop();

    std::ofstream out("File/huffmanout.txt");
    if(!out)
    {
        perror("Errore nell'apertura del file");
        return nullptr;
    }


    treeNode<T>* root = Q.top();


    //Codifica
    std::map<char,std::string> codifica;
    std::string bitString = "";
    treeDiscovery<T>(codifica,root,bitString);

    out<<"Caratteri Codificati: "<<std::endl;

    //Stampo i caratteri
    for(auto& x: codifica)
    {
        char key = x.first;
        std::string value = x.second;

        out<<" Char: "<<key<<" Value: "<<value<<std::endl;
    }

    //Stampo codifica
    out<<"Codifica: "<<std::endl;

    std::ifstream in2("File/huffman.txt");
    char s;
    while(in2>>s)
    {
        out<<codifica[s];
    }

    in.close();
    in2.close();
    out.close();

    return Q.top();





}

TEMPLATE
bool discovery(treeNode<T>*& start,treeNode<T>*& current,char& bit)
{
    if(bit == '0')
    {
        //Vai a sinistra
        std::cout<<"Vado a sinistra"<<std::endl;
        current = current->getLeft();
    }else if(bit == '1')
    {
        //Vai a destra
        std::cout<<"Vado a destra"<<std::endl;
        current = current->getRight();
    }
    if(current->getData().name != "-")
    {
        std::cout<<"Ho trovato un carattere "<<current->getData().name<<std::endl;
        return true;
    }

    return false;
}
TEMPLATE
void decodifica(treeNode<T>*& node)
{
    std::ifstream in("File/huffmandecodifica.txt");
    std::ofstream out("File/huffmandecodificaout.txt");
    if(!in)
    {
        perror("Errore nell'apertura del file huffmandecodifica");
        return;
    }

    char c;
    treeNode<T>* root = node;
    std::string decodifica;
    while(in>>c)
    {
        std::cout<<" c = "<<c<<std::endl;
        if(discovery(root,node,c))
        {
            std::string h = node->getData().name;
            out<<h<<std::endl;
            node = root;
        }
    }

    out.close();
}
