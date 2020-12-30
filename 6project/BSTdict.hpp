#ifndef BST_DICTIONARY_
#define BST_DICTIONARY_

#include "BinaryNode.hpp"
#include <string>
#include <vector>
#include <iostream>

class BSTdict{

    private:
    std :: shared_ptr<BinaryNode<std::string>> root;

    public:
    BSTdict();
    BSTdict(BSTdict &target);
    ~BSTdict();
    
    bool isEmpty();
    bool insert(const std :: string& word); // adds a word to the dictionary and maintains the BST property. DOES NOT ALLOW DUPLICATES
    bool remove(const std :: string& word);
    int getHeight(); // retuns the number of nodes on the longest path from root to leaf
    bool insertVector(const std :: vector<std :: string>& vec); // adds a vector of words to the dictionary
    void display(); // prints words one per line using in-order traversal.


    void displayHelper(std :: shared_ptr<BinaryNode<std::string>> root);
    int getHeightHelper(std :: shared_ptr<BinaryNode<std::string>> root);
    
};




#endif