#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

#include "stream_character.hpp"

// Container for a single vertical stream of StreamCharacters
class Stream {
  public:
    // Constructor: takes the vertical length of a stream 
    Stream(std::size_t capacity) : capacity_(capacity), length_(0) {
      stream_.reserve(capacity_);
    }
    
    // Add a StreamCharacter to the stream and fade all previous characters
    void increment() {
      for (auto& stream_character : stream_) {
        stream_character.fade(fade_amount_);
      }

      if (length_ < capacity_) {
        stream_.push_back(StreamCharacter('a'));
        length_ += 1;
      }
    }

    // Return true if atleast one StreamCharacter is visible
    bool is_visible() const {
      for (const auto& stream_character : stream_) {
        if (stream_character.is_visible()) { return true; }
      }

      return false;
    }

    // Print Stream 
    friend std::ostream& operator<<(std::ostream& os, const Stream& stream) {
      for (const auto& stream_character : stream.stream_) {
        os << stream_character;
      }

      return os;
    }
  
  private:
    static constexpr std::uint8_t fade_amount_ { 10 };  // alpha lost per increment

    std::size_t capacity_;                 // total capacity of the stream
    std::size_t length_;                   // current length of the stream  
    std::vector<StreamCharacter> stream_;  // container 
};
