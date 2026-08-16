#include <chrono>
#include <format>
#include <iostream>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>


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


// Container to hold all Stream of rain
class Matrix
{
  public:
    // Constructors: 
    // Create a matrix with the default number of Streams 
    Matrix()
    {
      streams.assign(100, Stream());
    }
    
    // Create a string of a Matrix with `width` Streams
    Matrix(uint32_t width)
    {
      streams.assign(width, Stream());
    }

    // Destructor
    ~Matrix() = default;
    
    // Returns a reference to the vector of streams. Allows us to 
    // draw and advance streams in the vector. Returned object is a 
    // reference to the actual streams vector. Handle with care 
    std::vector<Stream>& get_streams()
    {
      return streams;
    }

  private:
    std::vector<Stream> streams;
};



int main() {

  // Constants 
  constexpr std::string_view CLEAR_SCREEN{"\033[2J"};

  // Dimensions of the StreamMatrix
  constexpr uint32_t WIDTH = 80;

  // Frame Rate: one frame per second
  const std::chrono::duration<uint32_t, std::ratio<1>> FRAME_RATE{ 1 };

  // Instantiate Matrix of rain Streams with a specified width
  // Matrix matrix(WIDTH);
  Matrix matrix;

  // Flush the screen
  std::cout << CLEAR_SCREEN;


  // Main Loop: Print to the screen FRAME_RATE times per second
  uint32_t start{ 0 }, stop{ 30 };
  while (start != stop) {
    std::this_thread::sleep_for(FRAME_RATE);

    // Draw Streams
    auto& streams = matrix.get_streams();
    for (auto& stream : streams)
    {
      // Draw the stream, then advance it by one position
      std::cout << stream.get_position().first;
      stream.advance();
    }
    std::cout << '\n';
    
    start += 1; // increment count
  }

  return 0;
}
