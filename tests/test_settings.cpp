#include "Settings.hpp"

#define BOOST_TEST_MODULE Settings test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( SettingsTest )
{
    deck::Settings s0, s1, s2;

    s0.init(false);
    s1.init(true);
    s2.init(false);
    const std::string tmpconfig("/tmp/tmpAQWERT.bin");
    std::string str("aqwerth54eg/ge21/qwefsdf/ERDGF");

    std::set <std::string> strset;
    strset.insert(str);

    std::string nodename("NameOfNode");

    s0.setNodeName(nodename);
    s0.setDatabaseDirectories(strset);
    s0.save(tmpconfig);

    s1.load(tmpconfig);
    s1.save(tmpconfig);

    s2.load(tmpconfig);

    BOOST_CHECK_EQUAL(s0.getNodeName(), s1.getNodeName());
    BOOST_CHECK_EQUAL(s1.getNodeName(), s2.getNodeName());

    BOOST_CHECK_EQUAL(*(s0.getDatabaseDirectories().begin()), str);
    BOOST_CHECK_EQUAL(*(s0.getDatabaseDirectories().begin()),
                      *(s1.getDatabaseDirectories().begin()));
    BOOST_CHECK_EQUAL(*(s1.getDatabaseDirectories().begin()),
                      *(s2.getDatabaseDirectories().begin()));

    s0.load(tmpconfig);
    BOOST_CHECK_EQUAL(*(s0.getDatabaseDirectories().begin()), str);

    s0.init(true);
    s0.load(tmpconfig);
    BOOST_CHECK_EQUAL(*(s0.getDatabaseDirectories().begin()), str);

    s0.clear();
    BOOST_CHECK_EQUAL(s0.getDatabaseDirectories().size(), 0);
    BOOST_CHECK_EQUAL(s0.getNodeName(), "");

    s0.load(tmpconfig);
    BOOST_CHECK_EQUAL(*(s0.getDatabaseDirectories().begin()), str);

    BOOST_CHECK_GT(s0.getConfigDefaultLocation().size(), 0);
    BOOST_CHECK_GT(s0.getConfigDir().size(), 0);
    BOOST_CHECK_GT(s0.getHomeDir().size(), 0);
}
