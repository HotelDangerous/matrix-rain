// Represents one element in a Stream 
// Simple type with only two member variables and one method. The character value 
// its alpha (transparency) and a method that reports whether the character is 
// visible or not.  When the alpha is zero, the character is not visible.
struct StreamElement
{
  char character;
  uint32_t alpha;

  bool is_visible()
  {
    return alpha == 0;
  };
}
