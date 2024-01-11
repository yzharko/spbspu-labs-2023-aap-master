#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"

int main()
{
  std::string keyWord = "";
  std::vector<double> rectData(4);
  std::vector<double> ringData(4);
  std::vector<double> trianData(6);
  char* queue = new char[3] {};
  bool scaleMark = false;
  bool errMark = false;
  size_t figIndex = 0;

  while (std::cin >> keyWord) {
    if (keyWord == "RECTANGLE") {
      if ((std::cin >> rectData[0] >> rectData[1] >> rectData[2] >> rectData[3])\
      && ((rectData[0] < rectData[2]) && (rectData[1] < rectData[3]))) {
        queue[figIndex++] = 'r';
      } else {
        errMark = true;
      }
    }
    else if (keyWord == "RING") {
      if ((std::cin >> ringData[0] >> ringData[1] >> ringData[2] >> ringData[3])\
      && ((ringData[2] > 0) && (ringData[3] > 0) && (ringData[2] > ringData[3]))) {
        queue[figIndex++] = 'i';
      } else {
        errMark = true;
      }
    }
    else if (keyWord == "TRIANGLE") {
      if ((std::cin >> trianData[0] >> trianData[1] >> trianData[2] >> trianData[3]\
      >> trianData[4] >> trianData[5])) {
        double firEdge = (sqrt(pow(trianData[2] - trianData[0], 2)\
        + pow(trianData[3] - trianData[1], 2)));
        double secEdge = (sqrt(pow(trianData[4] - trianData[2], 2)\
        + pow(trianData[5] - trianData[3], 2)));
        double thirEdge = (sqrt(pow(trianData[4] - trianData[0], 2)\
        + pow(trianData[5] - trianData[1], 2)));
        bool result = 0;
        result = (firEdge + secEdge > thirEdge) && (firEdge + thirEdge > secEdge)\
        && (secEdge + secEdge > firEdge);
        if (result) {
          queue[figIndex++] = 't';
        } else {
          errMark = true;
        }
      } else {
        errMark = true;
      }
    }
    else if (keyWord == "SCALE") {
      if (figIndex == 0) {
        std::cerr << "Error: There is no descriptions of the supported figures!\n";
        delete[] queue;
        return 1;
      }

      psarev::point_t scaleCenter = {};
      double coef = 0.0;

      if ((std::cin >> scaleCenter.x >> scaleCenter.y >> coef) && (coef > 0)) {
        scaleMark = true;

        double prevAreaSum = 0.0;
        double newAreaSum = 0.0;
        double* prevFramesData = new double[12] {};
        double* newFramesData = new double[12] {};
        size_t prevCoosNum = 0;
        size_t newCoosNum = 0;

        for (size_t i = 0; i < figIndex; i++) {
          if (queue[i] == 'r') {
            psarev::Rectangle taskRect({ rectData[0], rectData[1]},\
            { rectData[2], rectData[3] });
            psarev::rectangle_t taskRectFrame = taskRect.getFrameRect();
            prevAreaSum += taskRectFrame.width * taskRectFrame.height;
            prevFramesData[prevCoosNum] = taskRectFrame.pos.x\
            - (taskRectFrame.width / 2);
            prevCoosNum++;
            prevFramesData[prevCoosNum] = taskRectFrame.pos.y\
            - (taskRectFrame.height / 2);
            prevCoosNum++;
            prevFramesData[prevCoosNum] = taskRectFrame.pos.x\
            + (taskRectFrame.width / 2);
            prevCoosNum++;
            prevFramesData[prevCoosNum] = taskRectFrame.pos.y\
            + (taskRectFrame.height / 2);
            prevCoosNum++;
            taskRect.move(0 - scaleCenter.x, 0 - scaleCenter.y);
            taskRect.scale(coef);
            taskRectFrame = taskRect.getFrameRect();
            newAreaSum += taskRectFrame.width * taskRectFrame.height;
            newFramesData[newCoosNum] = taskRectFrame.pos.x\
            - (taskRectFrame.width / 2);
            newCoosNum++;
            newFramesData[newCoosNum] = taskRectFrame.pos.y\
            - (taskRectFrame.height / 2);
            newCoosNum++;
            newFramesData[newCoosNum] = taskRectFrame.pos.x\
            + (taskRectFrame.width / 2);
            newCoosNum++;
            newFramesData[newCoosNum] = taskRectFrame.pos.y\
            + (taskRectFrame.height / 2);
            newCoosNum++;
          }
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << prevAreaSum << ' ';
        for (size_t i = 0; i < prevCoosNum; i++) {
          std::cout << prevFramesData[i] << ' ';
        }
        std::cout << '\n';
        std::cout << newAreaSum << ' ';
        for (size_t i = 0; i < newCoosNum; i++) {
          std::cout << newFramesData[i] << ' ';
        }
        std::cout << '\n';
        delete[] prevFramesData;
        delete[] newFramesData;
      }
    }
  }
  if (!scaleMark) {
    std::cerr << "Error: Scale command is missing or incorrect!\n";
    delete[] queue;
    return 1;
  }
  if (errMark) {
    std::cerr << "Error: One or more supported shapes are not specified correctly!\n";
  }
  delete[] queue;
  return 0;
}
