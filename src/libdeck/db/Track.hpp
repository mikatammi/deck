#ifndef TRACK_HPP
#define TRACK_HPP

#include <vector>
#include <string>

namespace deck {
namespace db {

class Track
{
public:
    Track();

    /// Set track's name
    /// @param name Artist name
    void setName(const std::string& name);

    /// Gets track's name
    /// @return Artist name
    std::string getName() const;


private:
    Track(const Track&);
    Track& operator= (const Track&);
};

typedef std::vector <Track*> TrackList;

}
}

#endif // TRACK_HPP
