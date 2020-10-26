#include "PlaylistItem.hpp"




PlaylistItem :: PlaylistItem(std::string title, double length, std::string genre){
    this-> title_ = title;
    this-> length_ = length;
    this-> genre_ =genre;
}

std :: string PlaylistItem :: getTitle() const{
    return this-> title_;
}

void PlaylistItem :: setTitle(string title){
    this->title_ = title;
}
double PlaylistItem :: getLength() const{
    return this -> length_;
}

std :: string PlaylistItem :: getGenre() const{
    return this-> genre_;
}

void PlaylistItem :: setLength(double length){
    this -> length_ = length;
}

void PlaylistItem :: setGenre(std :: string genre){
    this -> genre_ = genre;
}