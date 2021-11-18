#include <iostream>
#include <vector>
using namespace std;

class HashMap
{
public:
    int size;
    vector <int> keys;
    vector <int> vals;
    
    HashMap();
    int get(int key);
    void put(int key, int val);
    void remove(int key);
};

HashMap::HashMap()
{
    size = 0;
    keys.clear();
    vals.clear();
}

int HashMap::get(int k)
{
    for (int i = 0; i < size; i++)
    {
        if (keys[i] == k)
        {
            return vals[i];
        }
    }
    return -1;
}

void HashMap::put(int k, int v)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (keys[i] == k)
        {
            vals[i] = v;
            found = true;
        }
    }
    if (!found)
    {
        keys.push_back(k);
        vals.push_back(v);
        size++;
    }
}

void HashMap::remove(int k)
{
    for (int i = 0; i < size; i++)
    {
        if (keys[i] == k)
        {
            keys.erase(keys.begin()+i);
            vals.erase(vals.begin()+i);
            size--;
            return;
        }
    }
}

int main(int argc, const char * argv[])
{
    HashMap hashmap;
    hashmap.put(1, 1);
    hashmap.put(2, 2);
    hashmap.get(1);
    hashmap.get(3);
    hashmap.put(2, 1);
    hashmap.get(2);
    hashmap.remove(2);
    hashmap.get(2);

    return 0;
}
