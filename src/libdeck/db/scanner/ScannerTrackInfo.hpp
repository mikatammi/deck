#ifndef SCANNERTRACKINFO_HPP
#define SCANNERTRACKINFO_HPP

#include <string>
#include <stdint.h>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/mutex.hpp>

namespace deck {
namespace db {
namespace scanner {

class ScannerTrackInfo : public boost::enable_shared_from_this<ScannerTrackInfo>
{
public:
    struct FileInfo
    {
        /// Default constructor for FileInfo, sets default values
        FileInfo();

        /// Filename
        std::string filename;

        /// Size of the file in bytes
        uint64_t filesize;

        /// Last modified time in unix time (seconds)
        uint64_t lastmodified;
    };

    struct MetaInfo
    {
        /// Default constructor for MetaInfo, sets default values
        MetaInfo();

        /// Track title name
        std::string title;

        /// Artist name
        std::string artist;

        /// Album name
        std::string album;

        /// Year of track (0 unset)
        int16_t year;

        /// Possible comment
        std::string comment;

        /// Track number (0 unset)
        int16_t tracknumber;

        /// Genre
        std::string genre;

        /// Length in seconds
        uint64_t length;

        /// Bitrate in kilobits per second
        uint32_t bitrate;
    };

    /// Default constructor
    explicit ScannerTrackInfo();

    /// Copy constructor
    /// @param other Class which track information is copied from
    ScannerTrackInfo(const ScannerTrackInfo& other);

    /// Assign operator
    /// @param other Class which track information is copied from
    /// @return Reference into this class instance
    ScannerTrackInfo& operator= (const ScannerTrackInfo& other);

    /// Assign other ScannerTrackInfo's data into this
    /// @param trackinfo Track information to be assigned
    /// @return Reference into this class instance
    ScannerTrackInfo& assign(const ScannerTrackInfo& trackinfo);

    /// Reads MetaInfo from file using file information
    /// @param fileinfo Properly filled fileinfo structure
    /// @return Boolean which tell if read succeeded or not
    bool read(const FileInfo& fileinfo);

    /// Get file information
    /// @return FileInfo structure containing file information
    const FileInfo& getFileInfo() const;

    /// Get meta info
    /// @return MetaInfo structure containing meta information read from file
    const MetaInfo& getMetaInfo() const;

private:
    FileInfo fileinfo_;
    MetaInfo metainfo_;

    static boost::mutex taglib_mutex_;
};

}
}
}
#endif // SCANNERTRACKINFO_HPP
