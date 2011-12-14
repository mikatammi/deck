#ifndef DATABASE_HPP
#define DATABASE_HPP

namespace deck {
namespace db {

class Database
{
public:
    explicit Database();
    ~Database();

private:
    Database(const Database&);
    Database& operator= (const Database &);
};

}
}

#endif // DATABASE_HPP
