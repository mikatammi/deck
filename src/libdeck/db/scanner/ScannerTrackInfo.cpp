#include "ScannerTrackInfo.hpp"

#include <taglib/fileref.h>
#include <taglib/tag.h>

#include <boost/thread/locks.hpp>

namespace deck {
namespace db {
namespace scanner {

ScannerTrackInfo::FileInfo::FileInfo() :
    filename(),
    filesize(0),
    lastmodified(0)
{
}

ScannerTrackInfo::MetaInfo::MetaInfo() :
    title(),
    artist(),
    album(),
    year(-1),
    comment(),
    tracknumber(-1),
    genre(),
    length(0),
    bitrate(0)
{
}

boost::mutex ScannerTrackInfo::taglib_mutex_;

ScannerTrackInfo::ScannerTrackInfo() :
    fileinfo_(),
    metainfo_()
{
}

ScannerTrackInfo::ScannerTrackInfo(const ScannerTrackInfo& other) :
    fileinfo_(),
    metainfo_()
{
    // Use assign function to implement copy constructing
    assign(other);
}

ScannerTrackInfo& ScannerTrackInfo::operator= (const ScannerTrackInfo& other)
{
    // Use assign function to implement assign operator
    return assign(other);
}

ScannerTrackInfo& ScannerTrackInfo::assign(const ScannerTrackInfo& trackinfo)
{
    // Copy fileinfo and metainfo values from other class
    fileinfo_ = trackinfo.getFileInfo();
    metainfo_ = trackinfo.getMetaInfo();

    // Return reference into this
    return *this;
}

bool ScannerTrackInfo::read(const FileInfo& fileinfo)
{
    // Assign file info into this structure
    fileinfo_ = fileinfo;

    MetaInfo m;

    // Since taglib is not thread safe, lock mutex for taglib call
    boost::lock_guard <boost::mutex> lock(taglib_mutex_);

    // Open file using taglib
    TagLib::FileRef f(fileinfo_.filename.c_str());

    if(f.isNull())
    {
        assign(ScannerTrackInfo());
        return false;
    }

    // Read properties to metainfo structure using taglib
    m.title = f.tag()->title().to8Bit();
    m.artist = f.tag()->artist().to8Bit();
    m.album = f.tag()->album().to8Bit();
    m.year = f.tag()->year();
    m.comment = f.tag()->comment().to8Bit();
    m.tracknumber = f.tag()->track();
    m.genre = f.tag()->genre().to8Bit();
    m.length = f.audioProperties()->length();
    m.bitrate = f.audioProperties()->bitrate();

    metainfo_ = m;

    return true;
}

const ScannerTrackInfo::FileInfo& ScannerTrackInfo::getFileInfo() const
{
    // Return reference to fileinfo
    return fileinfo_;
}

const ScannerTrackInfo::MetaInfo& ScannerTrackInfo::getMetaInfo() const
{
    // Return reference to metainfo
    return metainfo_;
}

}
}
}
