#ifndef _PODCAST_
#define _PODCAST_

#include "PlaylistItem.hpp"

class Podcast : public PlaylistItem{
    private:

    string name_of_podcast_;
    string host_;
    string guest_;

    public:
    Podcast();

    Podcast(std::string title, double length, std::string genre, 
    std::string nameOfPodcast, std::string host, std::string guest);

    std::string getNameOfPodcast() const;
    std::string getHost() const;
    std::string getGuest() const;

    void setNameOfPodcast(std::string nameOfPodcast);
    void setHost(std::string host);
    void setGuest(std::string guest);

    void display() const override;

};


#endif