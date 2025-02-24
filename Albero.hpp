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
    //Serve ad identificare in modo univoco il nodo
    int NodeID;
    //PayLoad del nodo
    T data;
    //Lista dei figli del nodo
    std::vector<node*> adj;
    Color color;
public:

    node()
    {
        NodeID = 0;
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
    std::vector<node*> getChildren()
    {
        return adj;
    }

    //Ottieni il payLoad del nodo
    T getData()
    {
        return data;
    }

    int getID()
    {
        return NodeID;
    }
    void setID(int id)
    {
        NodeID = id;
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
        adj.push_back(child);

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
            this->adj.push_back(child);
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
    std::vector<node<T>*> nodes;
    node<T>* root;
    int ID;

public:

    AB()
    {
        root = nullptr;
        ID = 0;
    }

    //Aggiungi la radice o un figlio al padre attraverso il suo ID.
    //Se va a buon fine da in output l'ID del figlio creato
    int addChild(int FatherID,T Data);

    T getData(int ID);

    //Stampa tutti i figli appartenenti al ID del nodo passato in input
    void printChildren(int ID);
};

#include "Albero/Albero.tpp"
