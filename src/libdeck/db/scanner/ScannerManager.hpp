#ifndef SCANNERMANAGER_HPP
#define SCANNERMANAGER_HPP

#include <string>
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
    void setScanDirectories(const std::list <std::string>& directories);

    /// Get directories which are currently being scanned
    std::list <std::string> getScanDirectories() const;

private:
    void stopAndDeleteScanners();

    ScannerManager(const ScannerManager&);
    ScannerManager& operator= (const ScannerManager&);

    std::list <std::string> scan_directories_;
    std::list <Scanner*> scanners_;
};

}
}
}
#endif // SCANNERMANAGER_HPP
