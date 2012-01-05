#include "Settings.hpp"

#include <boost/assert.hpp>
#include <boost/thread/locks.hpp>

#if defined(ANDROID)
    // TODO
#elif defined(LINUX) or defined(APPLE) or defined(UNIX)

#include <unistd.h>
#include <pwd.h>

#elif defined(WINDOWS)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <io.h>
#include <shlobj.h>

#endif

namespace deck {

Settings::Settings() :
    settings_mutex_(),
    settings_map_()
{
}

void Settings::load(const std::string& filename)
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

}

void Settings::save(const std::string& filename)
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

}

void Settings::setValue(std::string key, std::string value)
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    // Set value to settings map
    settings_map_[key] = value;
}

std::string Settings::getValue(std::string key) const
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    // Try to find key value from settings map
    SettingsMap::const_iterator it = settings_map_.find(key);

    // If found, return it
    if (it != settings_map_.end())
    {
        return (*it).second;
    }

    // Otherwise return empty string
    return std::string();
}

std::string Settings::getHomeDir()
{
    std::string retval;

#if defined(ANDROID)
    // TODO
#elif defined(LINUX) or defined(APPLE) or defined(UNIX)

    // Try to get passwd structure using current users uid.
    struct passwd* pw = getpwuid(getuid());
    if (pw)
    {
        // If succesful, set return value.
        retval = pw->pw_dir;
    }
    else
    {
        // If not succesful, try $HOME env variable.
        retval = getenv("HOME");
    }

    // Default return value on unix platforms in case nothing
    // else is available.
    if(retval.empty())
    {
        retval = "/";
    }

#elif defined(WINDOWS)

    // Windows-style folder name retrieval
    TCHAR dir[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_FLAG_CREATE|CSIDL_PERSONAL,
                                  NULL, 0, dir)))
    {
        retval = std::string(dir);
    }

#endif

    BOOST_ASSERT(!retval.empty());
    BOOST_ASSERT(retval.length() > 0);

    return retval;
}

std::string Settings::getConfigDefaultLocation()
{
    std::string retval;

    // Add proper end to directory depending on operating system
#if defined(ANDROID)
    // TODO
#elif defined(APPLE)
    retval = getHomeDir() + "/Libraries/Deck";
#elif defined(LINUX) or defined(UNIX)
    retval = getHomeDir() + "/.deck";
#elif defined(WINDOWS)
    retval = getHomeDir() + "/Deck";
#endif

    BOOST_ASSERT(!retval.empty());
    BOOST_ASSERT(retval.length() > 0);

    return retval;
}

}
