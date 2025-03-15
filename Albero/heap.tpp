
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


TEMPLATE
void MinHeap<T>::DecreaseKey(int i,int x)
{
    //Verifico che l'input sia valido
    if(heap[i].key < x)
    {
        perror("Non e' possibile decrementare la chiave di i se x è maggiore");
        return;
    }

    //Vado a sostituire la chiave
    heap[i].key = x;
    int f = getFather(i);
    while(heap[f].key > heap[i].key && i != 0)
    {
        std::swap(heap[f],heap[i]);
        i = getFather(i);
    }
}


TEMPLATE
void MinHeap<T>::stampaSuFile()
{
    std::ifstream in("Albero/heap.txt");
    std::ofstream out("Albero/heapout.txt");
    int key;

    out<<"Array passato in input: "<<std::endl;

    //Lettura numeri
    while(in>>key)
    {
        T data;
        data.key = key;
        heapInsert(data);
        out<<" Key: "<<key;
    }

    in.close();
    out<<std::endl;
    BuildMinHeap();
    out<<"Post BuildMinHeap "<<std::endl;
    for(auto x : heap)
    {
       out<<" Key: "<<x.key;
    }

    out<<std::endl;
    out<<"Post DecreaseKey (4,1) "<<std::endl;

    DecreaseKey(4,1);

    for(auto x : heap)
    {
        out<<" Key: "<<x.key;
    }

    out<<std::endl;
    out<<"Post HeapSort "<<std::endl;

    heapSort();

    for(auto x : heap)
    {
        out<<" Key: "<<x.key;
    }

    out.close();

}

