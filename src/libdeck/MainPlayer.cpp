#include "MainPlayer.hpp"
#include "Settings.hpp"
#include "audio/AudioManager.hpp"
#include "connection/ConnectionManager.hpp"
#include "db/DatabaseManager.hpp"
#include "db/PlayList.hpp"

#include <boost/assert.hpp>

namespace deck
{

MainPlayer::MainPlayer() :
    state_(STOPPED),
    settings_(0),
    audiomanager_(0),
    connectionmanager_(0),
    databasemanager_(0),
    activeplaylist_(0)
{
    // New settings manager
    settings_ = new Settings();
    settings_->load();

    // Create new manager objects for audio, connections and database
    audiomanager_ = new audio::AudioManager();
    connectionmanager_ = new connection::ConnectionManager();
    databasemanager_ = new db::DatabaseManager();
    activeplaylist_ = new db::PlayList();

    BOOST_ASSERT(audiomanager_ != 0);
    BOOST_ASSERT(connectionmanager_ != 0);
    BOOST_ASSERT(databasemanager_ != 0);
    BOOST_ASSERT(activeplaylist_ != 0);
}

void MainPlayer::play()
{
    state_ = PLAYING;

    // TODO: Use audio manager to play
}

void MainPlayer::pause()
{
    if(state_ == PLAYING)
    {
        state_ = PAUSED;
    }
    else if(state_ == PAUSED)
    {
        state_ = PLAYING;
    }

    // TODO: Use audio manager to pause
}

void MainPlayer::stop()
{
    if(state_ == PLAYING || state_ == PAUSED)
    {
        state_ = STOPPED;
    }

    // TODO: Use audio manager to stop
}

void MainPlayer::prev()
{
    // TODO
}

void MainPlayer::next()
{
    // TODO
}

MainPlayer::PlayState MainPlayer::getState() const
{
    return state_;
}

db::PlayList * MainPlayer::getActivePlayList()
{
    return activeplaylist_;
}

void MainPlayer::setActivePlayList(db::PlayList *playlist)
{
    activeplaylist_ = playlist;
    BOOST_ASSERT(activeplaylist_ != 0);
}

Settings * MainPlayer::getSettings()
{
    return settings_;
}

}
