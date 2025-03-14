//#include "HashTable/hash.hpp"
#include "Albero.hpp"
class P
{
public:
    int key = 0;
    int distance = 0;
    int START = 0;
    int END = 0;
    bool extracted = false;
    int numChild = 0;
    int f = 0;
    std::string nome;
    std::string name;
    std::string cognome;
};


int main()
{
    treeNode<P> *root;
    root = Codifica<P>();
    decodifica(root);

    std::cout<<"Total: "<<root->getData().f;

    return 0;
}
