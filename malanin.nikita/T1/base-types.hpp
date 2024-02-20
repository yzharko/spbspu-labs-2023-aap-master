#ifndef BASE_STRUCT_HPP
#define BASE_STRUCT_HPP

namespace malanin
{
    struct point_t
    {
        double x = 0.0; // положение по x
        double y = 0.0; // положение по y
    };

    struct rectangle_t
    {
        double width = 0.0; // высота
        double height = 0.0; // ширина
        point_t pos;
    };
}

#endif