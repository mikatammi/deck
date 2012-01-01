#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>

namespace deck {
namespace db {

class Track;

class Album
{
public:
    /// Constructor for album
    /// @param name Album name
    explicit Album(const std::string& name = "");

    /// Sets album name
    /// @param name Album name
    void setName(const std::string& name);

    /// Gets album's name
    /// @return Album name
    std::string getName() const;

private:
    Album(const Album&);
    Album& operator= (const Album&);

    std::string name_;
};

}
}
#endif // ALBUM_HPP
