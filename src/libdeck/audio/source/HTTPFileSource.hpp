#ifndef HTTPFILESOURCE_HPP
#define HTTPFILESOURCE_HPP

#include "AbstractAudioFileSource.hpp"

namespace deck {
namespace audio {
namespace source {

class HTTPFileSource : public AbstractAudioFileSource
{
public:
    HTTPFileSource();
};

}
}
}
#endif // HTTPFILESOURCE_HPP
