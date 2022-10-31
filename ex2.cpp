#include <bits/stdc++.h>
using namespace std;

#define m 13

class DoubleHash
{
    int *hashTable;
    int curr_size;
 
public:
    bool isFull()
    {
        return (curr_size == m);
    }
 
    int hash1(int key)
    {
        return (key % m);
    }
 
    int hash2(int key)
    {
        return (7 - (key % 7));
    }
 
    DoubleHash()
    {
        hashTable = new int[m];
        curr_size = 0;
        for (int i=0; i<m; i++)
            hashTable[i] = -1;
    }
 
    void insertHash(int key)
    {
        if (isFull())
            return;

        int index = hash1(key);

        if (hashTable[index] != -1)
        {
            int index2 = hash2(key);
            int i = 1;
            while (1)
            {
                int newIndex = (index + i * index2) % m;
 
                if (hashTable[newIndex] == -1)
                {
                    hashTable[newIndex] = key;
                    break;
                }
                i++;
            }
        }

        else
            hashTable[index] = key;
        curr_size++;
    }

    void displayHash()
    {
        for (int i = 0; i < m; i++)
        {
            if (hashTable[i] != -1)
                cout << i << " --> "
                     << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};
 
int main()
{
    int a[] = {19, 27, 36, 10, 64, 13, 45, 73, 14, 20, 57};
    int n = sizeof(a)/sizeof(a[0]);

    DoubleHash h;
    for (int i = 0; i < n; i++)
        h.insertHash(a[i]);
 
    h.displayHash();
    return 0;
}
