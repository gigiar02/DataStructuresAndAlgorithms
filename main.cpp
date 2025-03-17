//#include "HashTable/hash.hpp"
#include "Esercizi/Esercitazione1/codici_huffman.hpp"





class P
{

};


int main()
{

    BST<P> tree;

    tree.PreInsert();
    tree.prePrint();

    Huffman<P> huff;
    huff.tree = tree;

    string ciao = "abc";
    string buff = huff.Codifica(ciao);

    huff.decodifica(buff);


    return 0;
}
