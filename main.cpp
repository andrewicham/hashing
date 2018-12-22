#include <iostream>
#include <fstream>
#include <string>
#include "Hash.h"


int main() {
    std::string line;
    int index;
    Hash hashObj;
    std::ifstream file("Dictionary.txt");
    //reading in each line of the file and assigning it to the variable line
    int j = 0;
    while(file>>line){
        //performing the hash function on each of the strings in the file, and this value an index
        index = hashObj.hashIndexValue(line);
        //adding a new item to the bucket
        hashObj.addItem(index, line);
        std::cout << "j: " << j << std::endl;
        j++;
    }
    
    file.close();
    for(int i =0; i < 37; i++){
        hashObj.printTable(i);
    }
    std::string input;
    std::cout << "Please enter the value you want to search for: ";
    std::cin >> input;
    hashObj.findData(input);
    return 0;
}


