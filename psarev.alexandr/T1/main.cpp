#include <iomanip>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "funcsDepot.hpp"

int main()
{
  std::string keyWord = "";
  std::vector<double> rectData;
  std::vector<double> ringData;
  std::vector<double> triData;
  std::vector<char> queue;
  bool scaleMark = false;
  bool errMark = false;

  while (std::cin >> keyWord) {
    if (keyWord == "RECTANGLE") {
      errMark = psarev::rectDataRework(std::cin, rectData, queue);
    }
    else if (keyWord == "RING") {
      errMark = psarev::ringDataRework(std::cin, ringData, queue);
    }
    else if (keyWord == "TRIANGLE") {
      errMark = psarev::triDataRework(std::cin, triData, queue);
    }
    else if (keyWord == "SCALE") {
      if (queue.size() == 0) {
        std::cerr << "Error: There is no descriptions of the supported figures!\n";
        return 1;
      }

      psarev::point_t scaleCenter = {};
      double coef = 0.0;

      if ((std::cin >> scaleCenter.x >> scaleCenter.y >> coef) && (coef > 0)) {
        scaleMark = true;

        double startAreaSum = 0.0;
        double newAreaSum = 0.0;
        std::vector<double> startFrames;
        std::vector<double> newFrames;
        int rC = 0;
        int iC = 0;
        int tC = 0;

        for (size_t i = 0; i < queue.size(); i++) {
          if (queue[i] == 'r') {
            psarev::Rectangle rect({ rectData[rC], rectData[rC + 1]}, { rectData[rC + 2], rectData[rC + 3] });
            rC += 4;
            psarev::rectangle_t rectFrame = rect.getFrameRect();
            psarev::fillData(startFrames, rectFrame, startAreaSum);
            psarev::modify(scaleCenter, coef, rect, rectFrame);
            psarev::fillData(newFrames, rectFrame, newAreaSum);
          }
          else if (queue[i] == 'i') {
            psarev::Ring ring({ ringData[iC], ringData[iC + 1] }, ringData[iC + 2], ringData[iC + 3] );
            iC += 4;
            psarev::rectangle_t ringFrame = ring.getFrameRect();
            psarev::fillData(startFrames, ringFrame, startAreaSum);
            psarev::modify(scaleCenter, coef, ring, ringFrame);
            psarev::fillData(newFrames, ringFrame, newAreaSum);
          }
          else if (queue[i] == 't') {
            psarev::Triangle tri({ triData[tC], triData[tC + 1] }, { triData[tC + 2], triData[tC + 3] }, { triData[tC + 4], triData[tC + 5] });
            tC += 6;
            psarev::rectangle_t triFrame = tri.getFrameRect();
            psarev::fillData(startFrames, triFrame, startAreaSum);
            psarev::modify(scaleCenter, coef, tri, triFrame);
            psarev::fillData(newFrames, triFrame, newAreaSum);
          }
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << startAreaSum << ' ';
        for (size_t i = 0; i < startFrames.size(); i++) {
          if (startFrames.size() - i == 1) {
            std::cout << startFrames[i];
          } else {
            std::cout << startFrames[i] << ' ';
          }
        }
        std::cout << '\n';
        std::cout << newAreaSum << ' ';
        for (size_t i = 0; i < newFrames.size(); i++) {
          if (newFrames.size() - i == 1) {
            std::cout << newFrames[i];
          } else {
            std::cout << newFrames[i] << ' ';
          }
        }
        std::cout << '\n';
      }
    }
  }
  if (!scaleMark) {
    std::cerr << "Error: Scale command is missing or incorrect!\n";
    return 1;
  }
  if (errMark) {
    std::cerr << "Error: One or more supported shapes are not specified correctly!\n";
  }
  return 0;
}
