#include <chrono>
#include <format>
#include <iostream>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include "../include/streams/Stream.hpp"



int main() {
  StreamCharacter stream_character{ 'a' };

  for (int i = 0; i < 100; i++)
  {
    std::cout << stream_character << "\n";
    stream_character.fade(3);
  }
}
