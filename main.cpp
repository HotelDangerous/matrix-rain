#include <iostream>
#include <vector>
#include "./include/streams/stream_character.hpp"
#include "./include/streams/stream.hpp"

int main() {

  Stream stream = Stream(20);

  // Print the stream until all characters are not visible
  while (stream.is_visible()) {
    // print the stream and add a new character
    std::cout << stream << std::endl;
    stream.increment();
  }
  
  return 0;
}
