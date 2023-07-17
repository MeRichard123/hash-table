#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_SIZE 2000;
#define PRIME 163;

// struct to hold the item itself
typedef struct {
    char *key;
    char *value;
} HashItem;

class Hashtable {
    private:
        int size;
        int count;
        int prime, mod;
        HashItem **items;

        int hash(const char *str, const int prime, const int mod);

        HashItem *hash_new_item(const char *key, const char *value);

        void delete_item(HashItem *item);

    public:
        Hashtable();

        ~Hashtable();

        int get_hash(const char *s, const int attempt);

        void insert(const char *key, const char *value);

        char *search(const char *key);

        void remove(const char *key);
};

#endif // hash_table.h