#define TEMPLATE template <typename T>
#include <vector>
#include <iostream>
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
    //Lista dei figli del nodo
    std::vector<node<T>*>* adj;
    Color color;
public:

    node()
    {
        adj = new std::vector<node*>();
    }
    node(T& data)
    {
        this->data = data;
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
    std::vector<node*>* getChildren()
    {
        return adj;
    }

    //Ottieni il payLoad del nodo
    T getData()
    {
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
        adj->push_back(child);

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

    //Stampa tutti i figli appartenenti al figlio passato in input
    void printChildren(node<T>* root);
    //Stampa tutti i figli dell'albero
    void printRoot();
};

#include "Albero/Albero.tpp"
