
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
void AB<T>::printChildren(node<T>* root)
{
    //Per ogni figlio effettua una chiamata ricorsiva
    std::cout<<"Sono node: "<<root<<" ho valore: "<<root->getData()<<std::endl;
    for(auto &i : *(root->getChildren()))
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
