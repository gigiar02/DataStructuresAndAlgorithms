/*
    Leggere da file di testo e inserire in un ABR in preorder
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define TEMPLATE template<typename T>
using namespace std;

TEMPLATE
class Node
{
    public:
        T data;
        Node<T>* father;
        Node<T>* left;
        Node<T>* right;
        char key;
        int  value;

        Node(char key,int value,T& data) : key(key), value(value), data(data){left,right,father = nullptr;}
        Node(char key,int value) : key(key), value(value){left = nullptr; right = nullptr; father = nullptr;}

};

TEMPLATE
class BST
{
    public:
        Node<T>* root;

        BST(){root = nullptr;}


        void Insert(Node<T>*& x)
        {
            Node<T>* y = root;
            if(root == nullptr)
            {
                root = x;
                return;
            }

           while (true)
           {
               if(x->value >= y->value)
               {
                   if(y->right)
                   {
                      y = y->right;
                   }else
                   {
                      y->right = x;
                      return;
                   }
               }else
                {
                   if(y->left != nullptr)
                   {
                       cout<<"Y left "<<y->left->key<<endl;
                        y = y->left;
                   }else
                    {
                        y->left = x;
                        return;
                    }
                }
           }
        }


        void print(ofstream& out,Node<T>*& current)
        {
            if(!current)
            {
                perror("Errore albero vuoto");
                return;
            }
            //Stampa il nodo
            char key = current->key;
            int value = current->value;
            out<<"key: "<<key<<" value: "<<value<<endl;

            if(current->left)
            {
                print(out,current->left);
            }

            if(current->right)
            {
                print(out,current->right);
            }



        }

        void prePrint()
        {
            ofstream out("Esercizi/out.txt");
            Node<T>* root = this->root;
            print(out,root);
        }

        void PreInsert()
        {
            ifstream in("Esercizi/read.txt");
            char key;
            int value;

            while(in>>key>>value)
            {
                Node<T>* newNode = new Node<T>(key,value);
                Insert(newNode);

            }
        }
};


TEMPLATE
class Huffman
{
    public:
        BST<T> tree;
        map<char,string> codifiche;

        void CharFill(Node<T>*& current,string bit)
        {

            if(current->left)
            {
                string leftBit = bit + "0";
                CharFill(current->left,leftBit);
            }

            if(current->right)
            {
                string rightBit = bit + "1";
                CharFill(current->right,rightBit);
            }

            if(!current->left && !current->right)
            {
                char c = current->key;
                codifiche[c] = bit;
                return;
            }
        }
        string Codifica(string text)
        {
            string buff = "";
            Node<T>* current = tree.root;
            ofstream out("Esercizi/out.txt");
            string bit = "";
            CharFill(current,bit);
            for(auto& x : codifiche)
            {
                cout<<" char = "<<x.first<<" value = "<<x.second<<endl;
            }

            out<<"Codifica: "<<endl;
            for(char z : text)
            {
                string s = codifiche[z];
                buff += s;
                out<<s<<endl;
            }

            out.close();
            return buff;
        }

        string decodifica(string text)
        {
            Node<T>* current = tree.root;
            //ofstream out("Esercizi/out.txt");
            fstream out;
            out.open("Esercizi/out.txt",ios::app);
            char k;
            string bit = "";
            out<<"Decodifica "<<endl;
            for(char k : text)
            {
                if(k == '0')
                {
                    current = current->left;

                }else
                {
                    current = current->right;
                }

                if(!current->left && !current->right)
                {
                    out<<current->key;
                    current = tree.root;
                }

            }
        }

};














