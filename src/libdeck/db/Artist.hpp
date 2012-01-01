#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>
#include <vector>

namespace deck {
namespace db {

class Album;

class Artist
{
public:
    /// Constructor for artist
    /// @param name Artist name
    explicit Artist(const std::string& name = "");

    /// Sets artist name
    /// @param name Artist name
    void setName(const std::string& name);

    /// Gets artist's name
    /// @return Artist name
    std::string getName() const;

    /// Adds album to this artist
    /// @param album Pointer to album
    void addAlbum(Album* album);

    /// Get count of albums this artist has
    /// @return Number of albums
    unsigned int albumCount() const;

    /// Get album by index
    /// @param index Index of the album
    /// @return Pointer to album, 0 if invalid index
    Album* getAlbum(unsigned int index);

private:
    Artist(const Artist&);
    Artist& operator= (const Artist&);

    std::string name_;
    std::vector <Album*> albums_;
};

}
}
#endif // ARTIST_HPP
