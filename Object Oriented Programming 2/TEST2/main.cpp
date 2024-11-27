#include <iostream>

using namespace std;

int main(void) {
  try
  {
    throw invalid_argument("message");
    
  }
  catch(const std::invalid_argument& e)
  {
    std::cerr <<  e.what() << '\n';
  }
  

  return 0;
}
