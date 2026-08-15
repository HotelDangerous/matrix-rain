#include <chrono>
#include <format>
#include <iostream>
#include <string_view>
#include <thread>

int main() {
  constexpr std::string_view CLEAR_SCREEN{"\033[2J"};
  constexpr std::string_view OUTPUT{"Welcome to the Matrix"};

  // Frame Rate: one frame per second
  const std::chrono::duration<uint32_t, std::ratio<1>> FRAME_RATE{1};

  // Flush the screen
  std::cout << CLEAR_SCREEN;

  // Main Loop: Print to the screen FRAME_RATE times per second
  uint32_t start{0}, stop{30};
  while (start != stop) {
    std::this_thread::sleep_for(FRAME_RATE);
    std::cout << std::format("{:^80}", OUTPUT) << std::endl;
    start += 1;
  }

  return 0;
}
