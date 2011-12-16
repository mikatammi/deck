#ifndef DUMMYAUDIOOUTPUT_HPP
#define DUMMYAUDIOOUTPUT_HPP

#include "AbstractAudioOutput.hpp"

namespace deck {
namespace audio {
namespace output {

class DummyAudioOutput : public AbstractAudioOutput
{
public:
    DummyAudioOutput();
};

}
}
}
#endif // DUMMYAUDIOOUTPUT_HPP
