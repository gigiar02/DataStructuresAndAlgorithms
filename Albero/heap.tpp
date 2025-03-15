
TEMPLATE
void MinHeap<T>::heapInsert(T& element)
{
    heap.push_back(element);
}

TEMPLATE
void MinHeap<T>::MinHeapify(int i)
{
    int min;
    int l = this->getLeft(i);
    int r = this->getRight(i);

    if(heap[l].key < heap[i].key && heapSize >= l)
    {
        min = l;
    }else
    {
        min = i;
    }

    if(heap[min].key > heap[r].key && heapSize >= r)
    {
        min = r;
    }

    if(min != i)
    {
        std::swap(heap[i],heap[min]);
        MinHeapify(min);
    }

}

TEMPLATE
void MinHeap<T>::BuildMinHeap()
{
    heapSize = heap.size()-1;

    for(int i = (heapSize-1)/2; i >= 0; i--)
    {
        MinHeapify(i);
    }
}


TEMPLATE
void MinHeap<T>::stampaHeap()
{
    std::cout<<"Inizio Stampa"<<std::endl;
    for(auto x : heap)
    {
        std::cout<<"A[i] = "<<x.key<<std::endl;
    }
    std::cout<<"Fine Stampa"<<std::endl;
}


TEMPLATE
void MinHeap<T>::heapSort()
{
    BuildMinHeap();
    const int size = heapSize;
    for(int j = size; j > 0; j--)
    {
        std::swap(heap[0],heap[j]);
        heapSize--;
        MinHeapify(0);
    }
}

