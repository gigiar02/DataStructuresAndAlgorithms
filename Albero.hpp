#include <vector>
#include <iostream>
#define TEMPLATE template <typename T>
//Colore
enum Color
{
    WHITE,
    GRAY,
    BLACK,
    RED
};


//Classe nodo
TEMPLATE
class node
{

protected:

    //PayLoad del nodo
    T data;
    //predecessore del nodo
    node<T>* father;
    //Lista dei figli del nodo
    std::vector<node<T>*> adj;
    Color color;

public:

    node()
    {
        father = nullptr;
        color = WHITE;
    }


    node(T& data)
    {
        this->data = data;
        father = nullptr;
        color = WHITE;
    }


    //Colore
    Color getColor()
    {
        return color;
    }

    void  setColor(Color newColor)
    {
        color = newColor;
    }


    //Ottieni la lista dei figli del nodo
    std::vector<node<T>*> getChildren()
    {
        return adj;
    }

    node<T>* getFather()
    {
        return father;
    }

    void setFather(node<T>*& father)
    {
        this->father = father;
    }


    //Ottieni il payLoad del nodo
    T& getData()
    {
        return data;
    }

    const T& getConstData() const {  // Aggiungi il qualificatore 'const'
        return data;
    }

    //Modifica il payLoad
    void setData(T& data)
    {
        this->data = data;
    }

    //Aggiungi un figlio
    int virtual addChild(node<T>*& child)
    {

        if(!child)
        {
            return -1;

        }

        this->adj.push_back(child);
        //In questo caso va per forza a buon fine a meno che il nodo passato in input non sia nullptr
        return 1;
    }

};


//Nodo Albero
TEMPLATE
class treeNode : public node<T>
{
protected:
    treeNode<T>* father;

public:

    treeNode() : node<T>()
    {
        father = nullptr;
    }

    treeNode<T>* getFather()
    {
        return father;
    }


    void setFather(treeNode<T>*& f)
    {
        father = f;
    }


    //Aggiungi un figlio al nodo che diventerà il suo nuovo padre
    int addChild(node<T>*& newNode) override
    {
        treeNode<T>* child = dynamic_cast<treeNode<T>*>(newNode);
        if(!child)
        {
            std::cout<<"Cast non riuscito"<<std::endl;
            return -1;
        }

        //Aggiungi il nodo solo se non ha già un padre
        if(!child->getFather())
        {
            treeNode<T>* temp = this;
            child->setFather(temp);
            this->adj->push_back(child);
        }
        else
        {
            std::cout<<"[!] Il nodo che si vuole aggiungere ha già un padre"<<std::endl;
            return -1;
        }

        return 1;
    }
};


//Albero con n figli
TEMPLATE
class AB
{
    //Radice dell'Albero
    node<T>* root;

public:

    AB()
    {
        root = nullptr;
    }

    //Aggiungi un figlio al nodo passato in input
    node<T>* addChild(node<T>*& child,T Data);
    node<T>* addChild(node<T>*& father,node<T>*& child);

    //Stampa tutti i figli appartenenti al figlio passato in input
    void printChildren(node<T>* root);
    //Stampa tutti i figli dell'albero
    void printRoot();
};

#include "Albero/Albero.tpp"
