#include "DatabaseManager.hpp"

namespace deck {
namespace db {

DatabaseManager::DatabaseManager() :
    scannermanager_()
{
}

void DatabaseManager::query()
{
}

void DatabaseManager::setScanDirectories(
        const std::set <std::string>& directories)
{
    // Set directories for scannermanager
    scannermanager_.setScanDirectories(directories);
}

}
}
