#include "HashTable/hash.hpp"

class P
{
public:
    int key = 0;
    int distance = 0;
    int START = 0;
    int END = 0;
    bool extracted = false;
    int numChild = 0;
};


int main()
{

    hashTable<int,std::string> H(999);
    item<int,std::string>* it = new item<int,std::string>(1,"ciao");
    H.insert(it);
    std::ofstream out("HashTable/out.txt");
    if(!out)
    {
        perror("Errore");
    }

    H.print(out);
    out.close();







    return 0;
}
