#define BOOST_FILESYSTEM_VERSION 2

#include "Scanner.hpp"

#include <boost/filesystem/operations.hpp>
#include <boost/foreach.hpp>

#include <taglib/fileref.h>
#include <set>
#include <iostream>

namespace deck {
namespace db {
namespace scanner {

Scanner::Scanner(const std::string &path) :
    scanpath_(path),
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
            pt(boost::bind(&Scanner::main_thread, scanpath_));
    main_future_ = pt.get_future();

    main_thread_ = boost::thread(boost::move(pt));
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
    if(/* TODO: Verify process started */ false)
    {
        // Some sort of fail.
        // Returning empty list.
        return ScannerTrackInfoList();
    }

    // Wait for result
    wait();

    // Returns resulting list
    return main_future_.get();
}

ScannerTrackInfoList Scanner::main_thread(const std::string& pathname)
{
    std::cout << "Scanner main_thread started" << std::endl;
    std::cout << "Scanning pathname: " << pathname << std::endl;

    // Check if directory/file exists
    if(!boost::filesystem::exists(boost::filesystem::path(pathname.c_str())))
    {
        std::cerr << "Directory doesn't exist" << std::endl;

        // Return empty list if it doens't
        return ScannerTrackInfoList();
    }

    // Get list of supported extensions
    TagLib::StringList tl_extensions = TagLib::FileRef::defaultFileExtensions();
    std::set <std::string> extensions;

    for(TagLib::StringList::Iterator it = tl_extensions.begin();
        it != tl_extensions.end();
        ++it)
    {
        // Insert extension to extension set
        extensions.insert((*it).to8Bit());
    }

    std::cout << "Supported extensions: " << tl_extensions.toString(",") <<
                 std::endl;

    // Step 1: Gather file names for scan
    std::list <ScannerTrackInfo::FileInfo> fileinfolist =
            scan_gather_files(boost::filesystem::path(pathname.c_str()));

    // Step 2: Scan files
    ScannerTrackInfoList tracklist;

    BOOST_FOREACH(ScannerTrackInfo::FileInfo fileinfo,
                  fileinfolist)
    {
        std::string extension = boost::filesystem::path(fileinfo.filename)
                .extension().c_str();

        if(extension.length() > 0)
        {
            extension = extension.substr(1);
        }

        if(extensions.count(extension) > 0)
        {
            boost::shared_ptr<ScannerTrackInfo>
                    trackinfo(new ScannerTrackInfo());

            if(trackinfo->read(fileinfo))
            {
                tracklist.push_back(trackinfo);
            }
        }
    }

    // Step 3: Collect output to final ScannerTrackInfolist

    return tracklist;
}

std::list <ScannerTrackInfo::FileInfo>
    Scanner::scan_gather_files(const boost::filesystem::path& p)
{
    std::list <ScannerTrackInfo::FileInfo> retval;

    if (boost::filesystem::is_regular_file(p))
    {
        ScannerTrackInfo::FileInfo fi;

        fi.filename = p.string();
        fi.filesize = boost::filesystem::file_size(p);
        fi.lastmodified = boost::filesystem::last_write_time(p);

        std::cout << "file: " << fi.filename
                  << "  size: " << fi.filesize
                  << "  lastmodified: " << fi.lastmodified << std::endl;

        retval.push_back(fi);
    }
    else if(boost::filesystem::is_directory(p))
    {
        std::cout << p << " is a directory" << std::endl;

        boost::filesystem::directory_iterator it(p);

        for(it; it != boost::filesystem::directory_iterator(); ++it)
        {
            boost::filesystem::path subpath(*it);

            std::list <ScannerTrackInfo::FileInfo>
                    subvals(scan_gather_files(subpath));

            retval.insert(retval.end(), subvals.begin(), subvals.end());
        }
    }

    return retval;
}

}
}
}
