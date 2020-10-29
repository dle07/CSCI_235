#ifndef PODCAST_
#define PODCAST_



#include "PlaylistItem.hpp"
#include <string>
#include <iostream>
using namespace std;
class AudioBook : public PlaylistItem{
    private:
    std::string author_;
    std::string speaker_;

    public:

    AudioBook(std::string title, double length, std::string genre,
    std::string author, std::string speaker);

    
    std::string getAuthor() const;
    std::string getSpeaker() const;

    void setAuthor(std::string author);
    void setSpeaker(std::string speaker);

/*
    Goal: Displays the member variables to the console. 
          Format is based on the given example in audioBookExample.txt.
*/
    void display() const override;


};


#endif