#pragma once

#include <cstdint>
#include <iostream>

// Simple data type containing character and opacity data
struct StreamCharacter {
  public:
    // If only character value is given, color will default to green
    StreamCharacter(char character);

    // Constructor: choosing a color
    StreamCharacter(char character, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
    
    // return the current transparency / opacity value of the character
    std::uint8_t get_alpha() const;

    // Decrement alpha by the amount given; saturating at 0
    void fade(std::uint8_t amount);
    
    // if the value of alpha is 0, then the character is not visible,
    // otherwise, the character is considered visible
    bool is_visible() const;

    // Overload the << operator, for printing with std::cout
    // printing considers color and transparency of the character
    friend std::ostream& operator<<(std::ostream& os, const StreamCharacter& stream_character);

  private:
    char character;

    // character coloring
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha { 255 };
};
