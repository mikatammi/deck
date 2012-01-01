#include "Artist.hpp"
#include "Album.hpp"
#include <algorithm>

namespace deck {
namespace db {

Artist::Artist(const std::string &name) :
    name_(name),
    albums_()
{
}

void Artist::setName(const std::string& name)
{
    name_ = name;
}

std::string Artist::getName() const
{
    return name_;
}

bool albumNameSort(Album* a, Album* b)
{
    return a->getName() < b->getName();
}

void Artist::addAlbum(Album *album)
{
    albums_.push_back(album);
    std::sort(albums_.begin(), albums_.end(), albumNameSort);
}

unsigned int Artist::albumCount() const
{
    return albums_.size();
}

Album* Artist::getAlbum(unsigned int index)
{
    if(index < albumCount())
    {
        return albums_.at(index);
    }
    else
    {
        return 0;
    }
}

}
}
