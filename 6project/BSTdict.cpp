#include "BSTdict.hpp"
using namespace std;



BSTdict :: ~BSTdict(){

}



bool BSTdict :: isEmpty(){
    if(this->root) return false;
    return true;
}

bool BSTdict :: insert(const std :: string & word){
    shared_ptr<BinaryNode<string>> temp = this->root;
    if( temp == nullptr){
        temp = shared_ptr<BinaryNode<string>>(new string(word));
        return true;
    }
    while( temp){
        if( temp ->getItem() == word) return false; //duplicate has been found
        if(word < temp->getItem()){
            if( temp->getLeftChildPtr() == nullptr)
                temp->setLeftChildPtr(shared_ptr<BinaryNode<string>>(new string(word)));
            else{
                temp = temp->getLeftChildPtr();
            }
        }else{
            if( temp->getRightChildPtr() == nullptr)
                temp->setRightChildPtr(shared_ptr<BinaryNode<string>>(new string(word)));
            else{
                temp = temp->getRightChildPtr();
            }

        }
         
    }

    return true;
}

void BSTdict :: display(){
    this->displayHelper(this->root);

}

int BSTdict :: getHeight(){
    int res = getHeightHelper(this->root);

    return res;
    
}

bool BSTdict:: insertVector( const std :: vector<std :: string>& vec){

    for( int i =0; i< vec.size(); i++)
    {
        //Found a duplicate, cant add it, return false
        if(!this->insert(vec[i])){
            return false;
        }
    }

    return true;
}

int BSTdict :: getHeightHelper(std :: shared_ptr<BinaryNode<std::string>> root){

    if(root == nullptr)
        return 0;
    
    int left = getHeightHelper(root->getLeftChildPtr()) +1;
    int right = getHeightHelper(root->getRightChildPtr()) +1;
    return max(left,right);


}




void BSTdict :: displayHelper(std::shared_ptr<BinaryNode<std::string>> root){

    if( root == nullptr)return;
    displayHelper(root->getLeftChildPtr());
    std :: cout<<root->getItem()<<std :: endl;
    displayHelper(root->getRightChildPtr());


}



