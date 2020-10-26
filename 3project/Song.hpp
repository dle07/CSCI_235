#ifndef SONG_
#define SONG_
#include "PlaylistItem.hpp"


//Song must have the artist_ private member on top of the title_, length_ and genre_ member
// variables that are inherited from PlaylistItem:

class Song : public PlaylistItem{

    private:
    std::string artist_;

    public:
    Song(std::string title, double length,std::string genre, std::string artist);

    std::string getArtist() const;

    void setArtist(std::string artist);
    void display() const override;


};//endif


#endif