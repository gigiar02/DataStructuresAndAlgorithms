#include "File/file.hpp"

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

    std::string path("File/graph.txt");
    type tipo = type::PRIM;
    popolaGrafo<P>(path,tipo);







    return 0;
}
