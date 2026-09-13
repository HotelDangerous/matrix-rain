#include <cstdint>
#include <iostream>

// Simple data type containing character and opacity data 
struct StreamCharacter {
  public:
    // If only character value is given, color will default to green
    StreamCharacter(char character) : 
      character(character), 
      red(0), green(255), blue(0) {}

    // Constructor: choosing a color
    StreamCharacter(char character, uint8_t red, uint8_t green, uint8_t blue) :
      character(character),
      red(red), green(green), blue(blue) {}
    
    // return the current transparency / opacity value of the character
    std::uint8_t get_alpha() const { return alpha; }

    // Decrement alpha by the amount given; saturating at 0
    void fade(uint8_t amount) {
      amount > alpha ? alpha = 0 : alpha -= amount;
    }

    // Overload the << operator, for printing with std::cout 
    // printing considers color and transparency of the character
    friend std::ostream& operator<<(std::ostream& os, const StreamCharacter& stream_character) {
      // normalize brightness between 0 and 1 inclusively
      float brightness = stream_character.alpha / 255.0f;
      
      // apply brightness to each color, and save as an integer
      std::uint32_t final_red   = static_cast<uint32_t>(stream_character.red * brightness);
      std::uint32_t final_green = static_cast<uint32_t>(stream_character.green * brightness);
      std::uint32_t final_blue  = static_cast<uint32_t>(stream_character.blue * brightness);

      // first line sets the output color, second prints the character, last returns output 
      // color to white, so that the terminal is not stuck printing some arbitrary color
      os << "\033[38;2;" << final_red << ";" << final_green << ";" << final_blue << "m"
         << stream_character.character 
         << "\033[0m";

      return os;
    }

  private:
    char character;

    // character coloring
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha { 255 };
};
