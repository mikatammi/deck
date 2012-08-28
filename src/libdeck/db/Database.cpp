#include "Database.hpp"
#include "Database.pb.h"
#include "../Settings.hpp"

namespace deck {
namespace db {

Database::Database() :
    artists_(),
    albums_(),
    tracks_(),
    readonly_(false)
{
}

Database::~Database()
{
}

void Database::init(const std::string &filename)
{
    // TODO
}

bool Database::load(const std::string &filename, bool readonly)
{
    // TODO
    readonly_ = readonly;

    // Return false until implemented
    return false;
}

bool Database::save()
{
    // TODO
    // Return false until implemented
    return false;
}

std::string Database::getDatabaseDir()
{
    return deck::Settings::getConfigDir() + "/db";
}

}
}
