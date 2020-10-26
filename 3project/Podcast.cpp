#include "Podcast.hpp"


Podcast :: Podcast(
    string title, double length, string genre,
    string nameOfPodcast, string host, string guest)
    :PlaylistItem(title,length,genre),name_of_podcast_(nameOfPodcast),
    host_(host),guest_(guest){

    };


string Podcast :: getNameOfPodcast() const {
    return this-> name_of_podcast_;
}

string Podcast :: getHost() const {
    return this -> host_;
}

string Podcast :: getGuest () const {
    return this-> guest_;
}

void Podcast :: setNameOfPodcast (std::string nameOfPodcast){
    this-> name_of_podcast_ = nameOfPodcast;
}

void Podcast :: setHost(std::string host){
    this-> host_ = host;
}

void Podcast :: setGuest(std::string guest){
    this-> guest_ = guest;
}


void Podcast :: display() const {
    cout<< this-> getTitle()<<endl;
    cout<<"Podcast: "<<this->name_of_podcast_<<endl;
    cout<<"Host: "<<this->host_<<endl;
    cout<<"Guest: "<<this->guest_<<endl;
    cout<<"Genre: "<<this->getGenre()<<endl;
    cout<<"Length: "<<this->getLength()<<endl<<endl;
}