#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

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

private:
    DatabaseManager(const DatabaseManager&);
    DatabaseManager& operator= (const DatabaseManager &);

};

#endif // DATABASEMANAGER_HPP
