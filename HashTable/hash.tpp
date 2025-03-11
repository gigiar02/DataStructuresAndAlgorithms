

t
int hashTable<T,S>::hash(T key,int i)
{
    return (key + i) % m;
}

//Inserisci un elemento
t
void hashTable<T,S>::insert(item<T,S>*& it)
{
   int i = 0;
   int key = it->key;
   int j = hash(key,i);

   //Cerco il primo posto vuoto
   while(i < m)
   {
       if(table[j] == nullptr)
       {
           table[j] = it;
           return;
       }else
       {
           i++;
           j = hash(key,i);
       }
   }
}

t
item<T,S>* hashTable<T,S>::find(T key)
{
    int i = 0;
    int j = hash(key,i);

    while(i != m && table[j] != nullptr)
    {
        if(table[j]->key == key)
        {
            return table[j];
        }else
        {
            i++;
            j = hash(key,i);
        }
    }

    return nullptr;
}

t
void hashTable<T,S>::remove(T key)
{
    int i = 0;
    int j = hash(key,i);

    while(table[j] != nullptr && i != m)
    {
        if(table[j]->key == key)
        {
            delete table[j];
            table[j] == nullptr;
            return;
        }

        i++;
        j = hash(key,i);
    }
}


//Stampa hash
t
void hashTable<T,S>::print(std::ofstream &out)
{
    for(int i = 0; i < table.size(); i++)
    {
        if(table[i] != nullptr)
        {
            out<<" CHIAVE: "<<table[i]->key<<" VALORE: "<<table[i]->value<<std::endl;
        }
    }
}
