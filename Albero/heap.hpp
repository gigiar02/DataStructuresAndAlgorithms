
TEMPLATE
class MinHeap
{
    std::vector<T> heap;
    int heapSize = 0;

    public:
        MinHeap(){}

        //Consente di inserire un'elemento nell'heap
        void heapInsert(T& element);

        //Metodi per ottenere figlio sinistro destro e padre di un elemento i
        int getLeft(int i)  {i = i >= 0 ? 2*i + 1 : INT_MAX; return i;}
        int getRight(int i) {i = i >= 0 ? 2*i + 2 : INT_MAX; return i;}
        int getFather(int i){i = i > 0 ? (i-1)/2 : INT_MAX; return i;}

        //Operazioni con l'heap
        void MinHeapify(int i);
        void BuildMinHeap();
        void heapSort();
        void stampaHeap();

};

#include "heap.tpp"
