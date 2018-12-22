#include <cstdlib>
#include <iostream>
#include <string>
#include "Hash.h"
#include "TimeInterval.h"

Hash::Hash()
{
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Node;
        HashTable[i]->data = "";
        HashTable[i]->next = NULL;
    }
}

void Hash::addItem(int index, std::string data)
{
    if(HashTable[index]->data == "")
    {
        HashTable[index]->data = data;
    }
    //if the node is already occupied with data, it will add it to a linked list in the hashtable bucket
    //Hashing by chaining
    else
    {
        Node* Ptr = HashTable[index];
        Node* N = new Node;
        N->data = data;
        N->next = NULL;
        //points to the next Ptr until it finds one that is NULL
        while(Ptr->next != NULL)
        {
            Ptr = Ptr->next;
        }
        Ptr->next = N;
    }
}

/*The assignment instructions weren't specific about what sort of hash function to use, so I figured this would be good enough.
I elected to sort each string by the first two letters, and not the first letter. This leads to some data values with the same first letter
to be hashed into a different bucket, but all with the same two first letters are hashed into the same bucket no matter what. */
int Hash::hashIndexValue(std::string key){
    int hash1 = 0;
    int hash2 = 0;
    int hash = 0;
    int index;
    //an example of type casting, where we convert the character values to ascii int values.
    hash1 = (int)key[0];
    hash2 = (int)key[1];
    //this will account for uppercase values, and add 32 to them so that they are not treated any differently than lowercase. 
    if(hash1 < 97){
        hash1 = hash1 + 32;
    }
    if(hash2 < 97){
        hash = hash + 32;
    }
    //3 and 7 were simply chosen as random, prime coefficients 
    hash = 3*(hash1) + 7*(hash2);
    index = hash % tableSize;
    return index; 
}

void Hash::findData(std::string input)
{
    int key = hashIndexValue(input);
    bool found = false;
    std::string name;
    Node* Ptr = HashTable[key];
    while(Ptr != NULL)
    {
        if(Ptr->data == input){
            found = true;
        }
        //increments until Ptr = NULL
        Ptr = Ptr->next;
    }
    if(found == true)
    {
        TimeInterval newTime;
        newTime.start();
        std::cout << "\nTrue" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Suggested Words: " << std::endl;
        Node* Ptr2 = HashTable[key];
        while(Ptr2 != NULL){
            //treating the strings as character arrays, to compare the first two values
            if(input[0] == Ptr2->data[0] && input[1] == Ptr2->data[1])
            {
                //to make sure that it only prints the values starting with the same two letters EXCEPT for the words itself
                if(input != Ptr2->data){
                    std::cout << Ptr2->data << std::endl;
                }
            }
            Ptr2 = Ptr2->next;
        }
        newTime.stop();
        std::cout << "" << std::endl;
        std::cout << newTime.GetInterval() << " Micro Seconds\n" << std::endl;
    }
    else
    {
        std::cout << "\nFalse" << std::endl;
    }
}

//NOT USED. kept for testing purposes
void Hash::printTable(int index)
{
    Node* Ptr = HashTable[index];
    std::cout << "index = " << index << std::endl;
    
    while(Ptr != NULL){
        std::cout << "----------\n";
        std::cout << Ptr->data << std::endl;        
        Ptr = Ptr->next;
    }
}
