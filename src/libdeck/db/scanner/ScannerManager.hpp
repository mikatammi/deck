#ifndef SCANNERMANAGER_HPP
#define SCANNERMANAGER_HPP

#include <list>

namespace deck {
namespace db {
namespace scanner {

class Scanner;

class ScannerManager
{
public:
    ScannerManager();

private:
    ScannerManager(const ScannerManager&);
    ScannerManager& operator= (const ScannerManager&);

    std::list <Scanner> scanners_;
};

}
}
}
#endif // SCANNERMANAGER_HPP
