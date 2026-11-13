#include <iostream>
#include <optional>
#include <vector>

#include "./include/streams/stream_character.hpp"

// Container for a single vertical stream of StreamCharacters
class Stream {
  public:
    // Constructor: takes the vertical length of a stream 
    Stream(std::size_t capacity) : capacity_(capacity), length(0) {
      // create an empty vector with capacity length of std::nullopt characters
      std::vector<std::optional<StreamCharacter>> stream_ {};
      stream_.reserve(length);
    }
    
    // Add a StreamCharacter to the stream and fade all previous characters
    void increment() {
      for (stream_character : stream_) {
        stream_character.fade();
      }

      if (length_ < capacity_) {
        stream_[length_] = StreamCharacter("a");
        length_ += 1;
      }
    }

    // Return true if atleast one StreamCharacter is visible
    bool is_visible() {
      for (stream_character : stream_) {
        if (stream_character.is_visible()) { return true; }
      }

      return false;
    }

    // Print Stream 
    friend std::ostream& operator<<(std::ostream& os) {
      for (stream_character : stream_) {
        os << stream_character;
      }
    }
  
  private:
    std::size_t capacity_;                 // total capacity of the stream
    std::size_t length_;                   // current length of the stream  
    std::vector<StreamCharacter> stream_;  // container 
}
