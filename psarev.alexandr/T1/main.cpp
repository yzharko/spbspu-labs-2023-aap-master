#include <sstream>
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
      errMark = psarev::ringDataRework(std::cin, rectData, queue);
    }
    else if (keyWord == "TRIANGLE") {
      errMark = psarev::triDataRework(std::cin, rectData, queue);
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

        double prevAreaSum = 0.0;
        double newAreaSum = 0.0;
        std::vector<double> startFrames;
        std::vector<double> newFrames;
        int rCtr = 0;

        for (size_t i = 0; i < queue.size(); i++) {
          if (queue[i] == 'r') {
            psarev::Rectangle rect({ rectData[rCtr++], rectData[rCtr++]}, { rectData[rCtr++], rectData[rCtr++] });
            psarev::rectangle_t rectFrame = rect.getFrameRect();
            prevAreaSum += rectFrame.width * rectFrame.height;
            startFrames.push_back(rectFrame.pos.x - (rectFrame.width / 2));
            startFrames.push_back(rectFrame.pos.y - (rectFrame.height / 2));
            startFrames.push_back(rectFrame.pos.x + (rectFrame.width / 2));
            startFrames.push_back(rectFrame.pos.y + (rectFrame.height / 2));
            psarev::point_t startPos = rectFrame.pos;
            rect.move({ scaleCenter.x, scaleCenter.y });
            psarev::point_t newPos;
            newPos.x = fabs(rectFrame.pos.x - scaleCenter.x) * coef;
            newPos.y = fabs(rectFrame.pos.y - scaleCenter.y) * coef;
            rect.scale(coef);
            rect.move(newPos.x, newPos.y);
            rectFrame = rect.getFrameRect();
            newAreaSum += rectFrame.width * rectFrame.height;
            newFrames.push_back(rectFrame.pos.x - (rectFrame.width / 2));
            newFrames.push_back(rectFrame.pos.y - (rectFrame.height / 2));
            newFrames.push_back(rectFrame.pos.x + (rectFrame.width / 2));
            newFrames.push_back(rectFrame.pos.y + (rectFrame.height / 2));
          }
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << prevAreaSum << ' ';
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
