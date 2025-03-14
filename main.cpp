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
    std::string cicl("File/graph.txt");
    popolaGrafo<P>(fileType::NUMBER_FILE,type::DFS_TOPOLOGICA);
    return 0;
}
