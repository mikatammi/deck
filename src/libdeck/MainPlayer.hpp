#ifndef MAINPLAYER_HPP
#define MAINPLAYER_HPP

namespace deck {

class Settings;

// Forward declaration for AudioManager
namespace audio {
class AudioManager;
}

// Forward declaration for ConnectionManager
namespace connection {
class ConnectionManager;
}

// Forward declaration for DatabaseManager and PlayList
namespace db {
class DatabaseManager;
class PlayList;
}

/// Main Player class handles all abstraction to user interface.
/// Subsystems handle different parts of the program and are
/// available using getters.
class MainPlayer
{
public:
    enum PlayState
    {
        PLAYING, PAUSED, STOPPED
    };

    /// Constructs Main Player
    explicit MainPlayer();

    /// Start playing if player is stopped or paused. If already playing,
    /// song is started from beginning.
    void play();

    /// Pause current song. If there is no song playing, does nothing.
    void pause();

    /// Stops current song. If there is no song playing, does nothing.
    void stop();

    /// Moves to previous song. If there is no previous song, does nothing.
    void prev();

    /// Moves to next song. If there is no next song, stops playing.
    void next();

    /// Get status of playing
    /// @return Enum-value of player status (PLAYING, PAUSED or STOPPED)
    PlayState getState() const;

    /// Get active playlist
    /// @return Pointer to active playlist
    db::PlayList * getActivePlayList();

    /// Set active playlist
    /// @param playlist Pointer to playlist
    void setActivePlayList(db::PlayList * playlist);

private:
    MainPlayer(const MainPlayer&);
    MainPlayer& operator= (const MainPlayer&);

    PlayState state_;

    Settings * settings_;

    audio::AudioManager * audiomanager_;
    connection::ConnectionManager * connectionmanager_;
    db::DatabaseManager * databasemanager_;
    db::PlayList * activeplaylist_;

};
}

#endif // MAINPLAYER_HPP
