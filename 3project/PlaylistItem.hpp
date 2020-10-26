#ifndef PLAY_LIST_ITEM_
#define PLAY_LIST_ITEM_

/*
The purpose of an abstract class (often referred to as an ABC) is to provide an appropriate base class from which other classes can inherit. Abstract classes cannot be used to 
instantiate objects and serves only as an interface. Attempting to instantiate an object of an abstract class causes a compilation error.

*/

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


class PlaylistItem{
    private:
    
    std::string title_ ;
    double length_ ;
    std::string genre_ ;

    public:
    PlaylistItem(std::string title, double length, std::string genre);
    std::string getTitle() const;
    void setTitle(string title);
    double getLength() const;
    std::string getGenre() const;
    void setLength(double length);
    void setGenre(std::string genre);
    
    
    virtual void display() const =0;

};











#endif