#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include "scanner/ScannerManager.hpp"
#include <set>

namespace deck {
namespace db {

/// Manages multiple audio track databases from different sources.
class DatabaseManager
{
public:
    explicit DatabaseManager();

    /// Queries all databases for tracks
    /// @param query Query object containing requested query parameters.
    /// @return TrackList containing resulting tracks. Returns empty
    ///         tracklist if no tracks found.
    /// TODO: Fix types
    void /* TrackSet */ query( /* Query query */ );

    /// Set directories for DatabaseManager to watch
    /// @param directories List of directory strings
    void setScanDirectories(const std::set<std::string> &directories);


private:
    DatabaseManager(const DatabaseManager&);
    DatabaseManager& operator= (const DatabaseManager &);

    scanner::ScannerManager scannermanager_;

};

}
}

#endif // DATABASEMANAGER_HPP
