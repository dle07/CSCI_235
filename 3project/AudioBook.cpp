#include "AudioBook.hpp"

AudioBook :: AudioBook (
    std::string title, double length, std::string genre,
    std::string author, std::string speaker)
    :PlaylistItem(title, length,genre),author_(author),speaker_(speaker){

}


string AudioBook :: getAuthor() const {
    return this->author_;
}

string AudioBook :: getSpeaker() const {
    return this-> speaker_;
}

void AudioBook :: setAuthor ( string author){
    this-> author_ = author;
}
void AudioBook :: setSpeaker(string speaker){
    this-> speaker_ = speaker;
}

void AudioBook :: display() const {
    cout<< this-> getTitle()<<endl;
    cout<<"Author: "<<this->author_<<endl;
    cout<<"Narrator: "<<this->speaker_<<endl;
    cout<<"Genre: "<<getGenre()<<endl;
    cout<<"Length: "<<getLength()<<endl<<endl;
}