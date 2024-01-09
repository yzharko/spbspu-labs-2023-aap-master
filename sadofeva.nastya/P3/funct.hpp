#ifndef FUNCT_HPP
#define FUNCT_HPP

namespace sadofeva
{
  class Str
  {
  public:
    size_t Str_read(char* input);
    std::string Hr(std::string str);
  private:
    char c = 0;
    size_t read = 0;
    std::string str;
  };
}

#endif
