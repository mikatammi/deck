#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "ScannerTrackInfo.hpp"

#include <string>
#include <list>
#include <queue>

#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/future.hpp>

namespace deck {
namespace db {
namespace scanner {

typedef std::list <boost::shared_ptr <ScannerTrackInfo> >
    ScannerTrackInfoList;

/// Scanner which scans particular subdirectory recursively.
class Scanner
{
public:
    /// Constructor for scanner.
    /// @param path Path to scan.
    explicit Scanner(const std::string& path);

    /// Destructor
    ~Scanner();

    /// Start scan job thread.
    void start();

    /// Stop scan job thread.
    void stop();

    /// Wait for execution of thread
    void wait();

    /// Checks whether scanner job is ready or not.
    /// @return True if ready.
    bool isReady() const;

    /// Get result. Waits if process not ready.
    /// @return Resulting list from scan
    ScannerTrackInfoList get();

private:
    ScannerTrackInfoList main_thread();
    void scan_gather_files();

    std::queue <std::string> filelist_;

    boost::mutex mutex_;

    boost::thread main_thread_;
    boost::unique_future<ScannerTrackInfoList>
        main_future_;

    bool run_main_thread_;

    ScannerTrackInfoList resultlist_;
};

}
}
}

#endif // SCANNER_HPP
