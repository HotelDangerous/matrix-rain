#include <utility>

// Structure representing a single Stream of rain
struct Stream
{
  public:
    // Get the current position of the stream
    const std::pair<uint32_t, uint32_t> get_position()
    {
      return position;
    }

    // Increment y by one: downward motion
    void advance() { position.first += 1; }

  private:
    // Vector of characters in the stream; the last character in
    // the vector is the most recently added character
    std::vector<char> stream_characters { 'B' };

    // Hold the position of the head of stream (x, y)
    // Increase in the x direction corresponds to a rightward shift 
    // Increase in the y direction corresponds to a downward shift
    std::pair<uint32_t, uint32_t> position { 0, 0 };  // (x, y)
};

