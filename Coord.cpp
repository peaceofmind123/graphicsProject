#include "globals.hpp"

using namespace GraphicsProject;
using namespace std;

Coord Coord::operator + (const Coord& point)
{
    return Coord(x+point.x,y+point.y,z+point.z,1);
}

Coord Coord::operator - (const Coord& point)
{
    return Coord(x-point.x,y-point.y,z-point.z,1);
}

Coord& Coord::normalize()
{
    double magnitude = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    if(magnitude!=0)
    {
        x/=magnitude;
        y/=magnitude;
        z/=magnitude;
    }
    return *this;
}

Coord Coord::crossProduct(const Coord& b)
{

}
