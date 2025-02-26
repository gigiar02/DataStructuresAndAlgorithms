#include "Albero.hpp"

int main()
{
    std::vector<int> vt = {1,100,200,300};

    AB<int> tree;
    node<int>* nodo = new treeNode<int>();
    nodo = tree.addChild(nodo,vt[0]);
    node<int>* child = tree.addChild(nodo,vt[1]);
    child = tree.addChild(nodo,vt[2]);
    std::cout<<"Data = "<<nodo->getData()<<std::endl;
    tree.printChildren(nodo);
    tree.printRoot();




    return 0;
}
