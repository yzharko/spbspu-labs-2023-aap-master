#include <iomanip>
#include <iostream>
#include "rectangle.hpp"
#include "ring.hpp"
#include "triangle.hpp"
#include "funcsDepot.hpp"

int main()
{
  std::string keyWord = "";
  size_t figCount = 0;
  size_t rectDataSize = 4;
  double* rectData = new double [rectDataSize];
  size_t ringDataSize = 4;
  double* ringData = new double[rectDataSize];
  size_t triDataSize = 6;
  double* triData = new double[rectDataSize];
  size_t queueSize = 10;
  double* queue = new double[queueSize];
  bool scaleMark = false;
  bool errMark = false;

  while (std::cin >> keyWord) {
    if (figCount == queueSize) {
      queue = psarev::increaseArr(queue, queueSize);
    }
    if (keyWord == "RECTANGLE") {
      errMark = psarev::addRectData(rectData, rectDataSize, queue, figCount);
    }
    else if (keyWord == "RING") {
      errMark = psarev::addRingData(ringData, ringDataSize, queue, figCount);
    }
    else if (keyWord == "TRIANGLE") {
      errMark = psarev::addTriData(triData, triDataSize, queue, figCount);
    }
    else if (keyWord == "SCALE") {
      if (figCount == 0) {
        std::cerr << "Error: There are no descriptions of the supported figures!\n";
        delete[] rectData;
        delete[] ringData;
        delete[] triData;
        delete[] queue;
        return 1;
      }

      psarev::point_t scaleCenter = {};
      double coef = 0.0;
      try
      {
        if (std::cin >> scaleCenter.x >> scaleCenter.y >> coef) {
          scaleMark = true;

          double startAreaSum = 0.0;
          double newAreaSum = 0.0;
          double* startFrames = new double[rectDataSize];
          double* newFrames = new double[rectDataSize];
          int rC = 0;
          int iC = 0;
          int tC = 0;

          for (size_t i = 0; i < figCount; i++) {
            if (queue[i] == 1) {
              psarev::Rectangle rect({ rectData[rC], rectData[rC + 1] }, { rectData[rC + 2], rectData[rC + 3] });
              rC += 4;
              psarev::rectangle_t rectFrame = rect.getFrameRect();
              startAreaSum += rect.getArea();
              psarev::fillData(startFrames, rectFrame, rC);
              psarev::modify(scaleCenter, coef, rect, rectFrame);
              newAreaSum += rect.getArea();
              psarev::fillData(newFrames, rectFrame, rC);
            }
            else if (queue[i] == 2) {
              psarev::Ring ring({ ringData[iC], ringData[iC + 1] }, ringData[iC + 2], ringData[iC + 3]);
              iC += 4;
              psarev::rectangle_t ringFrame = ring.getFrameRect();
              startAreaSum += ring.getArea();
              psarev::fillData(startFrames, ringFrame, iC);
              psarev::modify(scaleCenter, coef, ring, ringFrame);
              newAreaSum += ring.getArea();
              psarev::fillData(newFrames, ringFrame, iC);
            }
            else if (queue[i] == 3) {
              psarev::Triangle tri({ triData[tC], triData[tC + 1] }, { triData[tC + 2], triData[tC + 3] }, { triData[tC + 4], triData[tC + 5] });
              tC += 6;
              psarev::rectangle_t triFrame = tri.getFrameRect();
              startAreaSum += tri.getArea();
              psarev::fillData(startFrames, triFrame, tC);
              psarev::modify(scaleCenter, coef, tri, triFrame);
              newAreaSum += tri.getArea();
              psarev::fillData(newFrames, triFrame, tC);
            }
          }
          std::cout << std::fixed << std::setprecision(1);
          std::cout << startAreaSum << ' ';
          for (size_t i = 0; i < rectDataSize; i++) {
            if (rectDataSize - i == 1) {
              std::cout << startFrames[i];
            } else {
              std::cout << startFrames[i] << ' ';
            }
          }
          std::cout << '\n';
          std::cout << newAreaSum << ' ';
          for (size_t i = 0; i < rectDataSize; i++) {
            if (rectDataSize - i == 1) {
              std::cout << newFrames[i];
            } else {
              std::cout << newFrames[i] << ' ';
            }
          }
          std::cout << '\n';
          delete[] startFrames;
          delete[] newFrames;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what();
        delete[] rectData;
        delete[] ringData;
        delete[] triData;
        delete[] queue;
        return 1;
      }
      
    }
  }
  delete[] rectData;
  delete[] ringData;
  delete[] triData;
  delete[] queue;
  if (!scaleMark) {
    std::cerr << "Error: Scale command is missing!\n";
    return 1;
  }
  if (errMark) {
    std::cerr << "Error: One or more supported shapes are not specified correctly!\n";
  }
  return 0;
}
