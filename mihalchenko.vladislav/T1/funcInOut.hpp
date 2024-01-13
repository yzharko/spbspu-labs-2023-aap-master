#ifndef FUNCINOUT_HPP
#define FUNCINOUT_HPP
#include <string>
#include "shape.hpp"

namespace mihalchenko
{
    bool isPoligon();

    Shape **resizeArrayOfShapes(Shape **arrayGeomShapes, size_t sizeOfArrShapes);

    void delDinStorage(Shape **arrayGeomShapes, size_t shapeCounter);

    size_t recordingArrayOfShapes(Shape **arrayGeomShapes, size_t shapeCounter, size_t markerGeomShape);

    size_t processingAndOut(Shape **arrayGeomShapes, size_t shapeCounter);
}
#endif
