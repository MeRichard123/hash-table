#include "utils.cpp"

#define MAX_SIZE 2000;
#define PRIME 163;

/*
- Implement Resizing
- https://github.com/jamesroutley/write-a-hash-table/tree/master/06-resizing
*/

// struct to hold the item itself
typedef struct {
    char* key;
    char* value;
} HashItem;

// temp item for deleted values
static HashItem HT_DELETED_ITEM = {NULL, NULL};

class Hashtable {
    private:
        // class variables
        int size;
        int count;
        HashItem** items;
        int prime, mod;

        // hash function
        int hash(const char* str, const int prime, const int mod) {
            assert(!is_valid_prime(prime) && "Must be a prime number");

            long int hash = 0;
            const int string_length = strlen(str);
            for (int i = 0; i < string_length; ++i) {
                hash += pow(prime, string_length - (i+1)) * str[i];
                hash = hash % mod;
            }
            return (int)hash;
        }

        // create a new hashtable item
        HashItem* hash_new_item(const char* key, const char* value) {
            HashItem* item = new HashItem;
            item->key = strdup(key);
            item->value = strdup(value);

            return item;
        }

        // free the memory of an item
        void delete_item(HashItem* item) {
            if (item != nullptr) {
                delete item;
            }
        }

    public:
        Hashtable() {
            // constructor
            size = MAX_SIZE;
            items = new HashItem*[size];
            count = 0;
            prime = PRIME;
            mod = MAX_SIZE;
            
            for (int i = 0; i < size; ++i) {
                items[i] = NULL;
            }
        }

        ~Hashtable() {
            // destructor to free memory
            for (int i = 0; i < size; ++i) {
                if (items[i] != nullptr) {
                    delete items[i];
                    delete[] items;
                }
            }
        }

        int get_hash(const char* s, const int attempt) {
            // double hash to reduce collisions (open addressing)
            const int hash_a = hash(s, prime, mod);
            const int hash_b = hash(s, next_prime(prime), mod);
            return (hash_a + (attempt * (hash_b + 1))) % mod;
        }

        void insert(const char* key, const char* value) {
            HashItem* new_item = hash_new_item(key, value);
            int index = get_hash(new_item->key, 0);
            
            HashItem* cur_item = items[index];
            int i = 1;
            // dealing with collision (re-hashing)
            while (cur_item != NULL && cur_item != &HT_DELETED_ITEM) {
                index = get_hash(new_item->key, i);
                cur_item = items[index];
                i++;
            }
            while (cur_item != NULL) {
                if (cur_item != &HT_DELETED_ITEM) {
                    if (strcmp(cur_item->key, key) == 0) {
                        delete_item(cur_item);
                        items[index] = new_item;
                        return;
                    }
                }
            }
            items[index] = new_item;
            count++;
        }

        char* search(const char* key) {
            int index = get_hash(key, 0);
            HashItem* item = items[index];
            int i = 1;
            while (item != NULL || item != nullptr) {
                if (item != &HT_DELETED_ITEM) { 
                    if (strcmp(item->key, key) == 0) {
                        return item->value;
                    }
                }
                index = get_hash(key, i);
                item = items[index];
                i++;
            } 
            return NULL;
        }

        void remove(const char* key) {
            int index = get_hash(key, 0);
            HashItem* item = items[index];
            int i = 1;
            while (item != NULL || item != nullptr) {
                if (item != &HT_DELETED_ITEM) {
                    if (item->key != NULL && strcmp(item->key, key) == 0) {
                        delete_item(item);
                        items[index] = &HT_DELETED_ITEM;
                        break;
                    }
                }
                index = get_hash(key, i);
                item = items[index];
                i++;
            }
            count--;
        }
};