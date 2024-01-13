#include "class.hpp"
#include "file.hpp"
#include <fstream>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "argc != 4";
    return 1;
  }
  try
  {
    int num = std::stoi(argv[1]);
    std::ifstream infile(argv[2]);
    std::ofstream outfile(argv[3]);
    if (!infile.is_open() || !outfile.is_open())
    {
      std::cerr << "error file";
      return 1;
    }
    std::string intext = file::readFile(infile);
    if (intext.empty())
    {
      std::cerr << "fail text";
      return 2;
    }
    infile.close();
    if (num == 1)
    {
      matrix::Matrix mtrx;
      mtrx(intext);
      mtrx.creatStaticMatrix(intext);
      if (mtrx.isSquareMatrix() && mtrx.matrixConditionCheck(1))
      {
        file::printToFile(outfile, "true");
      }
      else
      {
        file::printToFile(outfile, "falase");
      }
      outfile.close();
    }
    else if (num == 2)
    {
      matrix::Matrix mtrx;
      mtrx(intext);
      mtrx.creatDynamicMatrix(intext);
      if (mtrx.isSquareMatrix() && mtrx.matrixConditionCheck(2))
      {
        file::printToFile(outfile, "true");
      }
      else
      {
        file::printToFile(outfile, "false");
      }
      outfile.close();
      mtrx.delMatrix();
    }
  }
  catch (const std::invalid_argument & ex)
  {
    std::cerr << ex.what();
    return 1;
  }
  catch (const std::out_of_range & ex)
  {
    std::cerr << ex.what();
    return 2;
  }
}
