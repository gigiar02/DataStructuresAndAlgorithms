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

std::vector<int> c = {30,70,20,10,15,60,45};
int main()
{
    MinHeap<P> heap;
    /*

    for(int i = 0; i < 7; i++)
    {
        P data;
        data.key = c[i];
        heap.heapInsert(data);
    }

    heap.stampaHeap();
    heap.BuildMinHeap();
    heap.stampaHeap();

    heap.heapSort();
    */
    heap.stampaSuFile();




    return 0;
}
