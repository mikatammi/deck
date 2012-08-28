#include "ScannerManager.hpp"
#include "Scanner.hpp"

#include <boost/foreach.hpp>

namespace deck {
namespace db {
namespace scanner {

ScannerManager::ScannerManager() :
    scan_directories_(),
    scanners_()
{
}

ScannerManager::~ScannerManager()
{
    // Stop and delete scanners on scannermanager destruction
    stopAndDeleteScanners();
}

void ScannerManager::setScanDirectories(
        const std::set<std::string> &directories)
{
    // Stop existing scanners
    stopAndDeleteScanners();

    // Set directories to scan
    scan_directories_ = directories;

    // Iterate through every directory
    BOOST_FOREACH(std::string dir, scan_directories_)
    {
        // Create and start scanner for each directory
        Scanner* new_scanner = new Scanner(dir);
        new_scanner->start();

        // Add scanners to scanner list
        scanners_.push_back(new_scanner);
    }
}

std::set <std::string> ScannerManager::getScanDirectories() const
{
    // Returns list of directories currently being scanned
    return scan_directories_;
}

void ScannerManager::stopAndDeleteScanners()
{
    // Iterate through every scanner
    for(std::list <Scanner*> ::iterator it = scanners_.begin();
        it != scanners_.end();
        ++it)
    {
        // Stop every scanner
        (*it)->stop();

        // Delete every scanner
        delete (*it);
        (*it) = 0;
    }

    // Clear scanner list
    scanners_.clear();
}

}
}
}
