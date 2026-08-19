#include <vector>
#include "../include/Streams.hpp"

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
