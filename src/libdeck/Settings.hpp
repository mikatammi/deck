#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <map>
#include <string>
#include <boost/thread/mutex.hpp>

namespace deck {

class Settings
{
public:
    /// Constructor for Settings
    explicit Settings();

    /// Loads settings from disk
    /// @param filename File for sett
    void load(const std::string& filename = "");

    /// Flushes settings to disk
    void save(const std::string& filename = "");

    /// Sets key value
    /// @param key Key string
    /// @param value Value string
    void setValue(std::string key, std::string value);

    /// Gets setting value by key
    /// @param key Key string
    /// @returns Value string
    std::string getValue(std::string key) const;

    /// Gets current user's home directory
    /// @return Home directory as string
    static std::string getHomeDir();

    /// Gets config default location
    /// @return Config file default location as string
    static std::string getConfigDefaultLocation();

private:
    mutable boost::mutex settings_mutex_;

    typedef std::map <std::string, std::string> SettingsMap;
    SettingsMap settings_map_;
};

}

#endif // SETTINGS_HPP
