#include "input_output.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include <iostream>
#include <cmath>
using namespace seryj;
void seryj::writeAnswer(std::ostream& out, CompositeShape& cs)
{
  std::vector<rectangle_t> rec_vec = cs.getFrameRect();
  double area = cs.getArea();
  writeDouble(out, area, ' ');
  for (size_t i = 0; i < cs.shapes; i++)
  {
    writeDouble(out, rec_vec[i].pos.x - rec_vec[i].width / 2, ' ');
    writeDouble(out, rec_vec[i].pos.y - rec_vec[i].height / 2, ' ');
    writeDouble(out, rec_vec[i].pos.x + rec_vec[i].width / 2, ' ');
    writeDouble(out, rec_vec[i].pos.y + rec_vec[i].height / 2, i == cs.shapes - 1 ? '\n' : ' ');
  }
}
std::vector<std::string> seryj::readText(std::istream& inp)
{
  std::vector<std::string> text;
  int scale_args = 0;
  bool is_after_scale = 0;
  while (!inp.eof() && scale_args < 3)
  {
    std::string line;
    std::getline(inp, line, '\n');
    std::string word = "";
    for(int i = 0; i < line.length(); i++)
    {
      if (line[i] == ' ' || i == line.length() - 1)
      {
        word += (i == line.length()) ? line[i] : 0;
        scale_args += is_after_scale ? 1 : 0;
        if (word == "SCALE")
          is_after_scale = true;
        text.push_back(word);
        word = "";
      }
      else
        word += line[i];
    }
  }
  if (scale_args == 0)
    throw std::invalid_argument("No scale command\n");
  if (scale_args < 3)
    throw std::invalid_argument("Not enough scale arguments\n");
  return text;
}
void seryj::textToCompositeShape(std::vector<std::string> inp, CompositeShape& cs)
{
std::string shape_name;
Shape* ptr = nullptr;
std::string error = "";
do
{
  if (ptr)
    cs += ptr;
  shape_name = inp[0];
  try
  {
    if (shape_name == "SQUARE")
    ptr = new Square({ std::stod(inp[1]) ,std::stod(inp[2]) }, std::stod(inp[3]));
    if (shape_name == "RECTANGLE")
      ptr = new Rectangle({ std::stod(inp[1]) , std::stod(inp[2]) }, { std::stod(inp[3]), std::stod(inp[4]) });
    if (shape_name == "REGULAR")
    {
      double arr[6];
      for (int i = 1; i <= 6; i++)
        arr[i - 1] = std::stod(inp[i]);
      ptr = new Regular({ arr[0], arr[1] }, { arr[2],arr[3] }, { arr[4],arr[5] });
    }
  }
  catch (std::logic_error const& e)
  {
    error = e.what();
    ptr = nullptr;
  }
  if (shape_name != "SCALE")
    seryj::skipShape(inp);
} while (shape_name != "SCALE");
if (error.length() > 0)
  throw std::logic_error(error);
}
void seryj::skipShape(std::vector<std::string>& v)
{
  do
  {
    v.erase(v.begin(), v.begin() + 1);
  } while (v[0] != "SQUARE" && v[0] != "RECTANGLE" && v[0] != "REGULAR" && v[0] != "SCALE");
}

void seryj::writeDouble(std::ostream& out, double d, char after)
{
  int i = std::round(d * 10);
  if (d >= 0)
    out << i / 10 << '.' << i % 10 << after;
  else out << '-' << abs(i / 10) << '.' << abs(i % 10) << after;
}
