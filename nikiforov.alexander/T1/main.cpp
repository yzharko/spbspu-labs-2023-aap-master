#include <iomanip>
#include <string>
#include <vector>
#include "rectangle.hpp"
#include "square.hpp"
#include "ellipse.hpp"
#include "addSizeParam.hpp"

int main()
{
  std::string nameFigure = "";
  double* arrRP = new double[4] {};
  double* arrSP = new double[3] {};
  double* arrEP = new double[4] {};

  size_t countRP = 4;
  size_t countSP = 3;
  size_t countEP = 4;

  std::vector<std::string> sequence;

  while (std::cin >> nameFigure)
  {
    if (nameFigure == "RECTANGLE")
    {
      if (countRP != 4)
      {
        countRP += 4;
        double* ArrElem = new double[countRP] {};
        for (size_t i = 0; i < countRP; i++)
        {
          ArrElem[i] = arrRP[i];
        }
        delete[] arrRP;
        arrRP = ArrElem;
      }

      if (std::cin >> arrRP[countRP - 4] >> arrRP[countRP - 3] >> arrRP[countRP - 2] >> arrRP[countRP - 1])
      {
        sequence.push_back(nameFigure);
      }
      else
      {

      }
    }
    else if (nameFigure == "SQUARE")
    {
      nikiforov::AddThreeElem(arrSP, countSP);
      if (std::cin >> arrSP[countSP - 3] >> arrSP[countSP - 2] >> arrSP[countSP - 1])
      {
        sequence.push_back(nameFigure);
      }
      else
      {

      }
    }
    else if (nameFigure == "ELLIPSE")
    {
      nikiforov::AddFourElem(arrEP, countEP);
      if (std::cin >> arrEP[countEP - 4] >> arrEP[countEP - 3] >> arrEP[countEP - 2] >> arrEP[countEP - 1])
      {
        sequence.push_back(nameFigure);
      }
      else
      {

      }
    }
    else if (nameFigure == "SCALE")
    {

      double x_c = 0.0;
      double y_c = 0.0;
      double k = 0.0;
      countRP = 0;
      countSP = 0;
      countEP = 0;

      double AreaSum = 0.0;
      double newAreaSum = 0.0;

      nikiforov::point_t primalLeftPoint = { 0, 0 };
      nikiforov::point_t primalRightPoint = { 0, 0 };
      nikiforov::point_t newLeftPoint = { 0, 0 };
      nikiforov::point_t newRightPoint = { 0, 0 };
      nikiforov::point_t movePoints = { 0, 0 };

      size_t countArrPrimalPoints = 4;
      size_t countArrAfterPoints = 4;

      if (sequence.size() > 0)
      {
        if ((std::cin >> x_c >> y_c >> k) && (k > 0))
        {
          double* arrPrimalPoints = new double[4] {};
          double* arrAfterPoints = new double[4] {};
          nikiforov::point_t sCen = { x_c , y_c };
          countRP = 0;

          for (size_t i = 0; i < sequence.size(); i++)
          {
            if (sequence[i] == "RECTANGLE")
            {
              if (countArrPrimalPoints != 4)
              {
                countArrPrimalPoints += 4;
                double* ArrElemPrimal = new double[countArrPrimalPoints] {};
                for (size_t i = 0; i < countArrPrimalPoints; i++)
                {
                  ArrElemPrimal[i] = arrPrimalPoints[i];
                }
                delete[] arrPrimalPoints;
                arrPrimalPoints = ArrElemPrimal;
              }
              if (countArrAfterPoints != 4)
              {
                countArrAfterPoints += 4;
                double* ArrElemAfter = new double[countArrAfterPoints] {};
                for (size_t i = 0; i < countArrAfterPoints; i++)
                {
                  ArrElemAfter[i] = arrAfterPoints[i];
                }
                delete[] arrAfterPoints;
                arrAfterPoints = ArrElemAfter;
              }
              primalLeftPoint = { arrRP[countRP++] ,arrRP[countRP++] };
              primalRightPoint = { arrRP[countRP++] ,arrRP[countRP++] };
              nikiforov::Rectangle Rect({ primalLeftPoint.x, primalLeftPoint.y }, { primalRightPoint.x, primalRightPoint.y });
              nikiforov::rectangle_t frame = Rect.getFrameRect();

              AreaSum += Rect.getArea();
              Rect.scale(k);

              movePoints = { ((frame.pos.x - sCen.x) * k) - (frame.pos.x - sCen.x),(frame.pos.y - sCen.y) * k - (frame.pos.y - sCen.y) };
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

              nikiforov::AddFourElem(arrPrimalPoints, countArrPrimalPoints);
              nikiforov::AddFourElem(arrAfterPoints, countArrAfterPoints);

              primalLeftPoint = { arrSP[countSP++] ,arrSP[countSP++] };
              double lenth = arrSP[countSP++];

              nikiforov::Square Sq({ primalLeftPoint.x, primalLeftPoint.y }, lenth);

              primalRightPoint = { Sq.rPoint.x, Sq.rPoint.y };
              nikiforov::rectangle_t frame = Sq.getFrameRect();

              AreaSum += Sq.getArea();
              Sq.scale(k);

              movePoints = { ((frame.pos.x - sCen.x) * k) - (frame.pos.x - sCen.x),(frame.pos.y - sCen.y) * k - (frame.pos.y - sCen.y) };
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

              nikiforov::AddFourElem(arrPrimalPoints, countArrPrimalPoints);
              nikiforov::AddFourElem(arrAfterPoints, countArrAfterPoints);

              nikiforov::point_t centerEll = { arrEP[countEP++] ,arrEP[countEP++] };
              double width = arrEP[countEP++];
              double height = arrEP[countEP++];

              nikiforov::Ellipse Ell({ centerEll.x, centerEll.y }, width, height);

              primalLeftPoint = { Ell.lPoint.x ,Ell.lPoint.y };
              primalRightPoint = { Ell.rPoint.x ,Ell.rPoint.y };
              nikiforov::rectangle_t frame = Ell.getFrameRect();

              AreaSum += Ell.getArea();
              Ell.scale(k);

              movePoints = { ((frame.pos.x - sCen.x) * k) - (frame.pos.x - sCen.x),(frame.pos.y - sCen.y) * k - (frame.pos.y - sCen.y) };
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
          delete[] arrPrimalPoints;
          delete[] arrAfterPoints;
        }
      }
      else
      {
        std::cerr << "Error: There is no descriptions of the supported figures!\n";
        delete[] arrRP;
        delete[] arrSP;
        delete[] arrEP;
        return 1;
      }
    }
  }
  delete[] arrRP;
  delete[] arrSP;
  delete[] arrEP;
  return 0;
}
