#include <iostream>
#include "hash_table.cpp"

using namespace std;

int main()
{
    cout << "Hello World; \n";

    Hashtable *ht = new Hashtable();
    ht->insert("Richard", "19");
    ht->insert("Day", "21");
    ht->insert("Harry", "19");
    ht->insert("Harry1", "19");
    ht->insert("Harry2", "19");
    ht->insert("Harry3", "19");
    ht->insert("Harry4", "19");
    ht->insert("Harry5", "19");
    ht->insert("Harry6", "19");
    ht->insert("Harry7", "19");
    ht->insert("Harry8", "19");
    ht->insert("Harry9", "19");
    ht->insert("Harry10", "19");
    ht->insert("Harry11", "19");
    ht->insert("Harry12", "19");

    ht->print_table();

    cout << "Finding Items" << endl;
    cout << ht->search("Day") << endl;
    /*
    cout << ht->search("Richard") << endl;
    cout << ht->search("Harry4") << endl;

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
    */
}