#ifndef TRACKSET_HPP
#define TRACKSET_HPP

namespace deck {
namespace db {

/// Return type for database queries
class TrackSet
{
public:
    TrackSet();

private:
    TrackSet(const TrackSet&);
    TrackSet& operator= (const TrackSet&);
};

}
}

#endif // TRACKSET_HPP
