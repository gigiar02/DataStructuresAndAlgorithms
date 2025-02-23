
//Aggiungi la radice o un figlio al padre attraverso il suo ID.
//Se va a buon fine da in output l'ID del figlio creato
TEMPLATE
int AB<T>::addChild(int FatherID,T Data)
    {
        //Se la radice non esiste
        if(root == nullptr)
        {

            root = new treeNode<T>();
            root->setID(0);
            ID++;
            nodes.push_back(root);
            return 0;
        }

        //Altrimenti verifica che l'ID del padre esista e se esiste aggiungi un nuovo figlio
        if(FatherID > nodes.size()-1)
        {
            return -1;
        }

        //Inizializzo il nuovo figlio
        node<T>* newChild = new treeNode<T>();
        newChild->setData(Data);
        newChild->setID(ID);
        ID++;

        //Il padre di newChild viene impostato in questa funzione
        if((nodes[FatherID]->addChild(newChild)) == -1)
        {
            return -1;
        }
        nodes.push_back(newChild);
        return newChild->getID();


    }


    TEMPLATE
    T AB<T>::getData(int ID)
    {
        T temp;
        return ID > nodes.size() ? temp : nodes[ID]->getData();
    }


    TEMPLATE
    void AB<T>::printChildren(int ID)
    {
        std::cout<<"Inizio ID = "<<ID<<"Size = "<<nodes.size()<<std::endl;
        if(ID < nodes.size())
        {

            node<T>* f = nodes[ID];
            std::vector<node<T>*> numb = f->getChildren();
            std::cout<<"Children = "<<numb.size()<<std::endl;


            for(auto child : f->getChildren())
            {
                std::cout<<"Nodo con ID: "<<child->getID()<<" Valore "<<child->getData()<<std::endl;
                treeNode<T>* temp = dynamic_cast<treeNode<T>*>(f);
                if(temp)
                {
                    std::cout<<temp->getFather()->getID()<<std::endl;
                }
            }
        }
    }
