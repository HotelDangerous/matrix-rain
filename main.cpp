#include <iostream>
#include <vector>
#include "streams/stream_character.hpp"
#include "streams/stream.hpp"

int main() {

  Stream stream = Stream(20);

  // Print the stream until all characters are not visible
  do {
    // add a new character and print the stream
    stream.increment();
    std::cout << stream << std::endl;
  } while (stream.is_visible());
  
  return 0;
}
