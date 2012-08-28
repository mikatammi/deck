#ifndef SCANNERMANAGER_HPP
#define SCANNERMANAGER_HPP

#include <string>
#include <set>
#include <list>

namespace deck {
namespace db {
namespace scanner {

class Scanner;

/// Class which watches set directories for changes
class ScannerManager
{
public:
    /// Default constructor
    explicit ScannerManager();

    /// Destructor
    ~ScannerManager();

    /// Set directories for ScannerManager to watch
    /// @param directories List of directory strings
    void setScanDirectories(const std::set <std::string>& directories);

    /// Get directories which are currently being scanned
    std::set <std::string> getScanDirectories() const;

private:
    void stopAndDeleteScanners();

    ScannerManager(const ScannerManager&);
    ScannerManager& operator= (const ScannerManager&);

    std::set <std::string> scan_directories_;
    std::list <Scanner*> scanners_;
};

}
}
}
#endif // SCANNERMANAGER_HPP
