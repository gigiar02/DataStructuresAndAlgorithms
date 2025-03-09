
TEMPLATE
node<T>* AB<T>::addChild(node<T>*& father,T Data)
{

        //Se la radice non esiste
        if(root == nullptr)
        {
            root = new treeNode<T>();
            root->setData(Data);
            return root;
        }

        //Inizializzo il nuovo figlio
        node<T>* newChild = new treeNode<T>();
        newChild->setData(Data);

        //Il padre di newChild viene impostato in questa funzione
        father->addChild(newChild);
        return newChild;


}


TEMPLATE
node<T>* AB<T>::addChild(node<T>*& father,node<T>*& child)
{
    //Se la radice non esiste
        if(root == nullptr)
        {
            root = father;
            root->addChild(child);
            return child;
        }

        //Il padre di newChild viene impostato in questa funzione
        father->addChild(child);
        return child;
}



TEMPLATE
void AB<T>::printChildren(node<T>* root)
{
    //Per ogni figlio effettua una chiamata ricorsiva
    std::cout<<"Sono "<<root<<" key: "<<root->getData().key<<std::endl;
    int h = 10;
    for(auto &i : root->getChildren())
    {
        //Stampa il figlio i-esimo di root
        printChildren(i);
    }
}

TEMPLATE
void AB<T>::printRoot()
{

    printChildren(root);
}
