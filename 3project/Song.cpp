#include "Song.hpp"

//calls the PlaylistItem constructor 


Song :: Song(std::string title, double length, std::string genre , std::string artist)
:PlaylistItem(title, length, genre), artist_(artist){

}

string Song :: getArtist() const{
    return this->artist_;
}


void Song :: setArtist(string artist){
    this-> artist_ = artist;
}


void Song :: display() const {
    std :: cout<<getTitle()<< std ::endl;
    std :: cout<<"Artist: "<<this->artist_<<std::endl;
    cout<<"Genre: "<<getGenre()<<endl;
    cout<<"Length: "<<getLength()<<endl<<endl;
}


