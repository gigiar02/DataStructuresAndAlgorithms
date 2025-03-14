#include <vector>
#include <iostream>
#define TEMPLATE template <typename T>
#include <map>
#include <fstream>
#include <queue>
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

//Nodo d'albero
TEMPLATE
class treeNode
{
    T data;
    treeNode* left;
    treeNode* right;
    treeNode* father;

    public:
        treeNode(T& data) : data(data){left = nullptr; right = nullptr; father;}

        //Getter
        treeNode* getLeft(){return left;}
        treeNode* getRight(){return right;}
        treeNode* getFather(){return father;}
        T         getData(){return data;}
        const T& getConstData() const {return data;}


        //Setter
        void setLeft(treeNode* left){this->left = left;}
        void setRight(treeNode* right){this->right = right;}
        void setFather(treeNode* father){this->father = father;}
        void setData(T& data){this->data = data;}




};


//Binary Tree
TEMPLATE
class BT
{
    //Radice
    protected:
        treeNode<T>* root;

    public:
        BT(treeNode<T>* root) : root(root){}
        BT(){root = nullptr;}

        //Aggiungi un figlio sinistro al nodo
        void addLeft(node<T>*& father,node<T>*& leftChild){father->setLeft(leftChild); leftChild->setFather(father);}
        void addRight(node<T>*& father,node<T>*& rightChild){father->setRight(rightChild); rightChild->setFather(father);}
};

TEMPLATE
class Verifica
{
    public:
    bool operator()( treeNode<T>* one, treeNode<T>* two)
    {
        return  one->getConstData().f > two->getConstData().f;
    }
};


//Legge dal file huffman.txt e ne scrive la codifica sul file huffmanout.txt
TEMPLATE
treeNode<T>* Codifica();

#include "Albero/Albero.tpp"
