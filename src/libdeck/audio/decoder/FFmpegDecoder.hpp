#ifndef FFMPEGDECODER_HPP
#define FFMPEGDECODER_HPP

#include "AbstractAudioDecoder.hpp"

namespace deck {
namespace audio {
namespace decoder {

class FFmpegDecoder : public AbstractAudioDecoder
{
public:
    FFmpegDecoder();
};

}
}
}
#endif // FFMPEGDECODER_HPP
