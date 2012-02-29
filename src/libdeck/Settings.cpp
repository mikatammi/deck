#include "Settings.hpp"

#include <boost/assert.hpp>
#include <boost/thread/locks.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem/v3/operations.hpp>

#include <fstream>

#include "Settings.pb.h"

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
    settings_proto_(0)
{
}

Settings::~Settings()
{
    clear();
}

void Settings::init(bool defaults)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    internal_init(defaults);
}

void Settings::internal_init(bool defaults)
{
    internal_clear();

    // Initialize settings proto
    settings_proto_ = new proto::Settings();

    // TODO: Set defaults
    if(defaults)
    {
    }
}

void Settings::clear()
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    internal_clear();
}

void Settings::internal_clear()
{
    // Free settings proto, if allocated
    if(settings_proto_ != 0)
    {
        delete settings_proto_;
        settings_proto_ = 0;
    }
}

void Settings::load(const std::string& filename)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    // Initialize settings proto
    internal_init(false);

    // Open settings file input stream
    std::ifstream settings_file(filename.c_str(),
                                std::ifstream::in | std::ifstream::binary);


    // Parse stream only if file was opened correctly,
    // otherwise use defaults
    if(settings_file.is_open())
    {
        settings_proto_->ParseFromIstream(&settings_file);
    }
    else
    {
        internal_init(true);
    }

    settings_file.close();
}

void Settings::save(const std::string& filename)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    if(settings_proto_ != 0)
    {
        createConfigDir();

        // Opening settings file output stream
        std::ofstream settings_file(filename.c_str(),
                                    std::ofstream::out | std::ofstream::binary);

        // Write file to stream only if it is opened
        if(settings_file.is_open())
        {
            settings_proto_->SerializeToOstream(&settings_file);
        }

        settings_file.close();
    }
}

void Settings::setDatabaseDirectories(std::set<std::string> dirs)
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    if(settings_proto_ != 0)
    {
        // Clear old values
        settings_proto_->clear_database_directories();

        // Store strings from set to protobuf structure
        BOOST_FOREACH(std::string dir, dirs)
        {
            std::string * str = settings_proto_->add_database_directories();
            (*str) = dir;
        }
    }
}

std::set <std::string> Settings::getDatabaseDirectories() const
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    std::set <std::string> retval;

    if(settings_proto_ != 0)
    {
        // Read strings to return value set
        BOOST_FOREACH(std::string dir, settings_proto_->database_directories())
        {
            retval.insert(dir);
        }
    }

    return retval;
}

void Settings::setNodeName(std::string nodename)
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    if(settings_proto_ != 0)
    {
        settings_proto_->set_nodename(nodename);
    }
}

std::string Settings::getNodeName() const
{
    // Lock mutex for this class instance
    boost::lock_guard <boost::mutex> lock(settings_mutex_);

    std::string retval;

    if(settings_proto_ != 0)
    {
        if(settings_proto_->has_nodename())
        {
            retval = settings_proto_->nodename();
        }
    }

    return retval;
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

std::string Settings::getConfigDir()
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

void Settings::createConfigDir()
{
    boost::filesystem3::create_directory(getConfigDir());
}

std::string Settings::getConfigDefaultLocation()
{
    return getConfigDir() + "/settings.bin";
}

}
