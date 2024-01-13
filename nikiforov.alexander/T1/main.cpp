#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "rectangle.hpp"
#include "square.hpp"
#include "ellipse.hpp"
#include "addSizeParam.hpp"

int main() 
{
  std::string nameFigure;
  double* RectParam = new double[0];
  double* SqParam = new double[0];
  double* ElParam = new double[0];
  double* arrPrimalPoints = new double[0];
  double* arrAfterPoints = new double[0];

  size_t countRectParam = 0;
  size_t countSqParam = 0;
  size_t countElParam = 0;
  bool errInd = false;
  std::vector<std::string> sequence;

  while (std::cin >> nameFigure)
  {
    if (nameFigure == "RECTANGLE")
    {
      RectParam = nikiforov::AddFourElem(RectParam, countRectParam);
      if (std::cin >> RectParam[countRectParam - 4] >> RectParam[countRectParam - 3] >> RectParam[countRectParam - 2] >> RectParam[countRectParam - 1])
      {
        sequence.push_back(nameFigure);
      }
      else 
      {
        errInd = true;
      }
    }
    else if (nameFigure == "SQUARE")
    {
      SqParam = nikiforov::AddThreeElem(SqParam, countSqParam);
      if (std::cin >> SqParam[countSqParam - 3] >> SqParam[countSqParam - 2] >> SqParam[countSqParam - 1])
      {
        sequence.push_back(nameFigure);
      }
      else
      {
        errInd = true;
      }
    }
    else if (nameFigure == "ELLIPSE")
    {
      ElParam = nikiforov::AddFourElem(ElParam, countElParam);
      if (std::cin >> ElParam[countElParam - 4] >> ElParam[countElParam - 3] >> ElParam[countElParam - 2] >> ElParam[countElParam - 1])
      {
        sequence.push_back(nameFigure);
      }
      else
      {
        errInd = true;
      }
    }
    else if (nameFigure == "SCALE")
    {
      
      double x_c = 0.0;
      double y_c = 0.0;
      double k = 0.0;
      countRectParam = 0;
      countSqParam = 0;
      countElParam = 0;

      double AreaSum = 0.0;
      double newAreaSum = 0.0;
      
      point_t primalLeftPoint = { 0, 0 };
      point_t primalRightPoint = { 0, 0 };
      point_t newLeftPoint = { 0, 0 };
      point_t newRightPoint = { 0, 0 };
      point_t movePoints = { 0, 0 };

      size_t countArrPrimalPoints = 0;
      size_t countArrAfterPoints = 0;

      if (sequence.size() > 0)
      {
        if ((std::cin >> x_c >> y_c >> k) && (k > 0))
        {
          point_t scaleCenter = { x_c , y_c };
          countRectParam = 0;

          for (size_t i = 0; i < sequence.size(); i++)
          {
            if (sequence[i] == "RECTANGLE")
            {
              arrPrimalPoints = nikiforov::AddFourElem(arrPrimalPoints, countArrPrimalPoints);
              arrAfterPoints = nikiforov::AddFourElem(arrAfterPoints, countArrAfterPoints);
              
              primalLeftPoint = { RectParam[countRectParam++] ,RectParam[countRectParam++] };
              primalRightPoint = { RectParam[countRectParam++] ,RectParam[countRectParam++] };
              nikiforov::Rectangle Rect({ primalLeftPoint.x, primalLeftPoint.y }, { primalRightPoint.x, primalRightPoint.y });
              rectangle_t rectFrame = Rect.getFrameRect();

              AreaSum += Rect.getArea();
              Rect.scale(k);

              movePoints = { ((rectFrame.pos.x - scaleCenter.x) * k) - (rectFrame.pos.x - scaleCenter.x),(rectFrame.pos.y - scaleCenter.y) * k - (rectFrame.pos.y - scaleCenter.y) };
              newLeftPoint = { Rect.lPoint.x + movePoints.x, Rect.lPoint.y + movePoints.y };
              newRightPoint = { Rect.rPoint.x + movePoints.x, Rect.rPoint.y + movePoints.y };

              newAreaSum += Rect.getArea();

              arrPrimalPoints[countArrPrimalPoints - 4] = primalLeftPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 3] = primalLeftPoint.y;
              arrPrimalPoints[countArrPrimalPoints - 2] = primalRightPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 1] = primalRightPoint.y;

              arrAfterPoints[countArrAfterPoints - 4] = newLeftPoint.x;
              arrAfterPoints[countArrAfterPoints - 3] = newLeftPoint.y;
              arrAfterPoints[countArrAfterPoints - 2] = newRightPoint.x;
              arrAfterPoints[countArrAfterPoints - 1] = newRightPoint.y;

            }
            else if (sequence[i] == "SQUARE") {

              arrPrimalPoints = nikiforov::AddFourElem(arrPrimalPoints, countArrPrimalPoints);
              arrAfterPoints = nikiforov::AddFourElem(arrAfterPoints, countArrAfterPoints);

              primalLeftPoint = { SqParam[countSqParam++] ,SqParam[countSqParam++] };
              double lenth = SqParam[countSqParam++];

              
              nikiforov::Square Sq({ primalLeftPoint.x, primalLeftPoint.y }, lenth);

              primalRightPoint = { Sq.rPoint.x, Sq.rPoint.y };
              rectangle_t rectFrame = Sq.getFrameRect();

              AreaSum += Sq.getArea();
              Sq.scale(k);

              movePoints = { ((rectFrame.pos.x - scaleCenter.x) * k) - (rectFrame.pos.x - scaleCenter.x),(rectFrame.pos.y - scaleCenter.y) * k - (rectFrame.pos.y - scaleCenter.y) };
              newLeftPoint = { Sq.lPoint.x + movePoints.x, Sq.lPoint.y + movePoints.y };
              newRightPoint = { Sq.rPoint.x + movePoints.x, Sq.rPoint.y + movePoints.y };

              newAreaSum += Sq.getArea();

              arrPrimalPoints[countArrPrimalPoints - 4] = primalLeftPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 3] = primalLeftPoint.y;
              arrPrimalPoints[countArrPrimalPoints - 2] = primalRightPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 1] = primalRightPoint.y;

              arrAfterPoints[countArrAfterPoints - 4] = newLeftPoint.x;
              arrAfterPoints[countArrAfterPoints - 3] = newLeftPoint.y;
              arrAfterPoints[countArrAfterPoints - 2] = newRightPoint.x;
              arrAfterPoints[countArrAfterPoints - 1] = newRightPoint.y;
            }
            else if (sequence[i] == "ELLIPSE") {

              arrPrimalPoints = nikiforov::AddFourElem(arrPrimalPoints, countArrPrimalPoints);
              arrAfterPoints = nikiforov::AddFourElem(arrAfterPoints, countArrAfterPoints);

              point_t centerEll = { ElParam[countElParam++] ,ElParam[countElParam++] };
              double width = ElParam[countElParam++];
              double height = ElParam[countElParam++];

              
              nikiforov::Ellipse Ell({ centerEll.x, centerEll.y }, width, height);

              primalLeftPoint = { Ell.lPoint.x ,Ell.lPoint.y };
              primalRightPoint = { Ell.rPoint.x ,Ell.rPoint.y };
              rectangle_t rectFrame = Ell.getFrameRect();

              AreaSum += Ell.getArea();
              Ell.scale(k);

              movePoints = { ((rectFrame.pos.x - scaleCenter.x) * k) - (rectFrame.pos.x - scaleCenter.x),(rectFrame.pos.y - scaleCenter.y) * k - (rectFrame.pos.y - scaleCenter.y) };
              newLeftPoint = { Ell.lPoint.x + movePoints.x, Ell.lPoint.y + movePoints.y };
              newRightPoint = { Ell.rPoint.x + movePoints.x, Ell.rPoint.y + movePoints.y };

              newAreaSum += Ell.getArea();

              arrPrimalPoints[countArrPrimalPoints - 4] = primalLeftPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 3] = primalLeftPoint.y;
              arrPrimalPoints[countArrPrimalPoints - 2] = primalRightPoint.x;
              arrPrimalPoints[countArrPrimalPoints - 1] = primalRightPoint.y;

              arrAfterPoints[countArrAfterPoints - 4] = newLeftPoint.x;
              arrAfterPoints[countArrAfterPoints - 3] = newLeftPoint.y;
              arrAfterPoints[countArrAfterPoints - 2] = newRightPoint.x;
              arrAfterPoints[countArrAfterPoints - 1] = newRightPoint.y;
            }
          }
          std::cout << std::fixed << std::setprecision(1);
          std::cout << AreaSum << ' ';
          for (size_t i = 0; i < countArrPrimalPoints; i++) {
            if (countArrPrimalPoints - i == 1) {
              std::cout << arrPrimalPoints[i];
            }
            else {
              std::cout << arrPrimalPoints[i] << ' ';
            }
          }
          std::cout << '\n';

          std::cout << newAreaSum << ' ';
          for (size_t i = 0; i < countArrAfterPoints; i++) {
            if (countArrAfterPoints - i == 1) {
              std::cout << arrAfterPoints[i];
            }
            else {
              std::cout << arrAfterPoints[i] << ' ';
            }
          }
          std::cout << '\n';
        }
      }
      else
      {
        std::cerr << "Error: There is no descriptions of the supported figures!\n";
        delete[] RectParam;
        delete[] SqParam;
        delete[] ElParam;
        delete[] arrPrimalPoints;
        delete[] arrAfterPoints;
        return 1;
      }
      delete[] RectParam;
      delete[] SqParam;
      delete[] ElParam;
      delete[] arrPrimalPoints;
      delete[] arrAfterPoints;
      break;
    }
  }
  return 0;
}
