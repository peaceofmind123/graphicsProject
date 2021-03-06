#include "globals.hpp"

namespace GraphicsProject
{


    class Coord
    {
    public:
        double x,y,z,h;
        explicit Coord(double x=0,double y=0, double z=0, double h=1):x(x),y(y),z(z),h(h)
        {}
        Coord operator - (const Coord& point);
        Coord operator + (const Coord& point);
        Coord& normalize();
        Coord crossProduct(const Coord& b);

    };
}
