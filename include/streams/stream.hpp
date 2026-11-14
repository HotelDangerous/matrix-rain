#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

#include "streams/stream_character.hpp"

// Container for a single vertical stream of StreamCharacters
class Stream {
  public:
    // Constructor: takes the vertical length of a stream
    Stream(std::size_t capacity);
    
    // Add a StreamCharacter to the stream and fade all previous characters
    void increment();

    // Return true if atleast one StreamCharacter is visible
    bool is_visible() const;

    // Print Stream
    friend std::ostream& operator<<(std::ostream& os, const Stream& stream);
  
  private:
    static constexpr std::uint8_t fade_amount_ { 10 };  // alpha lost per increment

    std::size_t capacity_;                 // total capacity of the stream
    std::size_t length_;                   // current length of the stream
    std::vector<StreamCharacter> stream_;  // container
};
