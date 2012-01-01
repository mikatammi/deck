#ifndef TRACK_HPP
#define TRACK_HPP

#include <vector>

namespace deck {
namespace db {

class Track
{
public:
    Track();

private:
    Track(const Track&);
    Track& operator= (const Track&);
};

typedef std::vector <Track*> TrackList;

}
}

#endif // TRACK_HPP
