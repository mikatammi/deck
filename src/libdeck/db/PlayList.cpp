#include "PlayList.hpp"

namespace deck {
namespace db {

PlayList::PlayList() :
    tracklist_()
{
}

TrackSourceInfo* PlayList::at(PlayList::size_type index)
{
    if(index < count())
    {
        return tracklist_.at(index);
    }
    else
    {
        return 0;
    }
}

PlayList::size_type PlayList::count() const
{
    return tracklist_.size();
}

}
}
