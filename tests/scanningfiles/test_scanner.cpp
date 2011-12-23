#include "db/scanner/Scanner.hpp"
#include "db/scanner/ScannerTrackInfo.hpp"

#include <boost/foreach.hpp>

#define BOOST_TEST_MODULE ScannerTrackInfo test
#include <boost/test/included/unit_test.hpp>

// const std::string testpath = "/toybox/stuff-c/musica";
//const std::string testpath2 = "/toybox/stuff-c/music";
const std::string testpath = "/mnt/stuffy/music-active-torrents";

BOOST_AUTO_TEST_CASE( ScannerTest )
{
    deck::db::scanner::Scanner scanner(testpath);
    //deck::db::scanner::Scanner scanner2(testpath2);
    //deck::db::scanner::Scanner scanner3(testpath2);

    scanner.start();
    //scanner2.start();
    //scanner3.start();

    deck::db::scanner::ScannerTrackInfoList resultlist =
            scanner.get();
    /*
    deck::db::scanner::ScannerTrackInfoList resultlist2 =
            scanner2.get();
    resultlist.insert(resultlist.end(),
                      resultlist2.begin(), resultlist2.end());
    resultlist2.clear();

    deck::db::scanner::ScannerTrackInfoList resultlist3 =
            scanner3.get();
    resultlist.insert(resultlist.end(),
                      resultlist3.begin(), resultlist3.end());
    resultlist3.clear();
    */

    BOOST_FOREACH(boost::shared_ptr<deck::db::scanner::ScannerTrackInfo> t,
                  resultlist)
    {
        deck::db::scanner::ScannerTrackInfo::MetaInfo m = t->getMetaInfo();

        std::cout << m.artist << " - " <<
                     m.album << " - " <<
                     m.title << std::endl;
    }

    // scanner

    /*
    BOOST_CHECK_EQUAL(m.artist, "Pink Floyd");
    BOOST_CHECK_EQUAL(m.album,
                      "Dark Side of the Moon [Remastered 1994]");
    BOOST_CHECK_EQUAL(m.title, "Money");
    BOOST_CHECK_EQUAL(m.tracknumber, 5);
    BOOST_CHECK_EQUAL(m.year, 1973);
    BOOST_CHECK_EQUAL(m.genre, "Psychedelic Rock");
    BOOST_CHECK_EQUAL(m.length, 392);
    BOOST_CHECK_EQUAL(m.comment.length(), 0);
    */
}
