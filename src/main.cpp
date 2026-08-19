#include <chrono>
#include <format>
#include <iostream>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include "../include/Matrix.hpp"



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
