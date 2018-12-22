#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

class Hash{
    
    private:
        //the notes say that primes are best for the size of m (table size), and the table size cannot dependent on the data at all
        static const int tableSize = 37;
        struct Node{
            std::string data;
            Node* next;
        };

        Node* HashTable[tableSize];

    public:
        Hash();
        int hashIndexValue(std::string key);
        void addItem(int index, std::string data); 
        void findData(std::string input);
        void printTable(int index);
};
#endif /* HASH_H */