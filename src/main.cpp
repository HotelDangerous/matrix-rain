#include <iostream>
#include <vector>
#include "../include/streams/StreamCharacter.hpp"


int main() {
  std::vector<StreamCharacter> stream_vec;
  for (int i{0}; i < 50; i++)
  {
    stream_vec.push_back(StreamCharacter{ 'a' });
  }

  // ugly, but lets us see the character fade
  for (int i = 0; i < 100; i++)
  {
    for (int j {0}; j < 50; j++){
      std::cout << stream_vec[j] << " ";
      stream_vec[j].fade(3);
    }
    std::cout << stream_vec[0].is_visible();
    std::cout << std::endl;
  }
}
