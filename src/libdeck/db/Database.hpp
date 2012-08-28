#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Artist.hpp"
#include "Album.hpp"
#include "Track.hpp"

#include <vector>
#include <string>

namespace deck {
namespace db {

class Database
{
public:
    explicit Database();
    ~Database();

    /// Initialize a new database
    void init(const std::string& filename);

    /// Load database from file
    /// @param filename Filename of database file.
    /// @param readonly Whether to open this database file read only.
    /// @return True on success, False if not
    bool load(const std::string& filename, bool readonly = false);

    /// Save database to file
    /// @return True on success, False if not
    bool save();

    /// Get database directory
    /// @return Database directory path in string
    static std::string getDatabaseDir();

private:
    Database(const Database&);
    Database& operator= (const Database &);

    std::vector <Artist> artists_;
    std::vector <Album> albums_;
    std::vector <Track> tracks_;

    bool readonly_;
};

}
}

#endif // DATABASE_HPP
