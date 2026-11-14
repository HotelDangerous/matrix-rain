#include "streams/stream.hpp"

// Constructor: takes the vertical length of a stream 
Stream::Stream(std::size_t capacity) : capacity_(capacity), length_(0) {
  stream_.reserve(capacity_);
}

// Add a StreamCharacter to the stream and fade all previous characters
void Stream::increment() {
  for (auto& stream_character : stream_) {
    stream_character.fade(fade_amount_);
  }

  if (length_ < capacity_) {
    stream_.push_back(StreamCharacter('a'));
    length_ += 1;
  }
}

// Return true if atleast one StreamCharacter is visible
bool Stream::is_visible() const {
  for (const auto& stream_character : stream_) {
    if (stream_character.is_visible()) { return true; }
  }

  return false;
}

// Print Stream 
std::ostream& operator<<(std::ostream& os, const Stream& stream) {
  for (const auto& stream_character : stream.stream_) {
    os << stream_character;
  }

  return os;
}
