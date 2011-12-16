#include "Scanner.hpp"

namespace deck {
namespace db {
namespace scanner {

Scanner::Scanner(const std::string &path) :
    filelist_(),
    mutex_(),
    main_thread_(),
    main_future_(),
    run_main_thread_(false),
    resultlist_()
{
}

Scanner::~Scanner()
{
}

void Scanner::start()
{
    boost::packaged_task <ScannerTrackInfoList>
            pt(ScannerTrackInfoList main_thread);
    //main_future_ = pt.get_future();
}

void Scanner::stop()
{
}

void Scanner::wait()
{
    // Wait for main future to be ready
    main_future_.wait();
}

bool Scanner::isReady() const
{
    // Return main future readyness
    return main_future_.is_ready();
}

ScannerTrackInfoList Scanner::get()
{
    if(!isReady() /* && sth else TODO: Verify process started */)
    {
        wait();
    }
    else
    {
        // Some sort of fail.
        // Returning empty list.
        return ScannerTrackInfoList();
    }

    // Returns resulting list
    return main_future_.get();
}

ScannerTrackInfoList Scanner::main_thread()
{
}

void Scanner::scan_gather_files()
{
}

}
}
}
