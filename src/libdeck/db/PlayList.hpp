#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <vector>

namespace deck {
namespace db {

class TrackSourceInfo;

class PlayList
{
public:
    /// Constructor for PlayList
    PlayList();

    typedef std::vector <TrackSourceInfo*> ::size_type size_type;

    /// Gets playlist entry from index
    /// @param index Entry index
    /// @return Pointer to TrackSourceInfo at given index or 0 if failure
    TrackSourceInfo* at(size_type index);

    /// Gets playlist size
    /// @return Playlist size
    size_type count() const;

private:
    PlayList(const PlayList&);
    PlayList& operator= (const PlayList&);


    std::vector <TrackSourceInfo*> tracklist_;

};

}
}
#endif // PLAYLIST_HPP
