#include "db/scanner/ScannerTrackInfo.hpp"
using deck::db::scanner::ScannerTrackInfo;

#define BOOST_TEST_MODULE ScannerTrackInfo test
#include <boost/test/included/unit_test.hpp>

const std::string testfile =
        "/mnt/stuffy/music-active-torrents/Pink Floyd- Dark Side of " \
        "the Moon [Remasterer 1994]/05 Money.flac";

BOOST_AUTO_TEST_CASE( ScannerTrackInfoTest )
{
    deck::db::scanner::ScannerTrackInfo::FileInfo fi;
    fi.filename = testfile;
    fi.filesize = 420;
    fi.lastmodified = 1324435811;

    deck::db::scanner::ScannerTrackInfo t;
    t.read(fi);

    deck::db::scanner::ScannerTrackInfo::MetaInfo m = t.getMetaInfo();

    BOOST_CHECK_EQUAL(m.artist, "Pink Floyd");
    BOOST_CHECK_EQUAL(m.album,
                      "Dark Side of the Moon [Remastered 1994]");
    BOOST_CHECK_EQUAL(m.title, "Money");
    BOOST_CHECK_EQUAL(m.tracknumber, 5);
    BOOST_CHECK_EQUAL(m.year, 1973);
    BOOST_CHECK_EQUAL(m.genre, "Psychedelic Rock");
    BOOST_CHECK_EQUAL(m.length, 392);
    BOOST_CHECK_EQUAL(m.comment.length(), 0);
}
