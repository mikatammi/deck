#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <set>
#include <string>
#include <boost/thread/mutex.hpp>

namespace deck {

namespace proto {
    class Settings;
}

class Settings
{
public:
    /// Constructor for Settings
    explicit Settings();

    /// Destructor for Settings
    ~Settings();

    /// Initializes internal protobuf datastructure and optionally defaults.
    /// Used in cases such as settings file doesn't exist or corrupted.
    void init(bool defaults = true);

    /// Clears settings datastructures
    void clear();

    /// Loads settings from disk
    /// @param filename File for settings
    void load(const std::string& filename = "");

    /// Flushes settings to disk
    /// @param filename File for settings
    void save(const std::string& filename = "");

    /// Sets directories to be scanned to database
    /// @param dirs Directories
    void setDatabaseDirectories(std::set <std::string> dirs);

    /// Gets directories to be scanned to database
    /// @return Set of directory strings
    std::set <std::string> getDatabaseDirectories() const;


    /// Gets current user's home directory
    /// @return Home directory as string
    static std::string getHomeDir();

    /// Gets config directory for current operating system
    /// @return Config directory
    static std::string getConfigDir();

    /// Creates directory to path given by getConfigDir()
    static void createConfigDir();

    /// Gets config default location
    /// @return Config file default location as string
    static std::string getConfigDefaultLocation();

private:
    void internal_init(bool defaults = true);
    void internal_clear();

    mutable boost::mutex settings_mutex_;
    proto::Settings* settings_proto_;
};

}

#endif // SETTINGS_HPP
