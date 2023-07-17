#include <iostream>
#include <cassert>
#include <cstring>

#include "hash_table.cpp"

using namespace std;

int main()
{
    cout << "Hello World; \n";

    Hashtable *ht = new Hashtable();
    ht->insert("Richard", "19");
    ht->insert("Day", "21");
    ht->insert("Harry", "19");

    cout << ht->search("Day") << endl;
    cout << ht->search("Richard") << endl;
    cout << ht->search("Harry") << endl;

    ht->remove("Harry");

    auto value = ht->search("Harry");

    if (value != NULL)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}