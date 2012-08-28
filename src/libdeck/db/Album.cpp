#include "Album.hpp"

namespace deck {
namespace db {

Album::Album(const std::string &name):
    name_(name),
    tracks_()
{
}

void Album::setName(const std::string &name)
{
    name_ = name;
}

std::string Album::getName() const
{
    return name_;
}

}
}
