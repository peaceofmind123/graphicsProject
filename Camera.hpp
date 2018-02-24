#include "globals.hpp"

using namespace GraphicsProject;
using namespace std;

class Camera
{
public:
    Coord position;
    Coord viewDir; //the view direction in world coordinates
    Coord viewUp;   //the viewup vector in world coordinates
    Coord viewRight; //the third axis of the view coordinates, in world coordinates

    //the view matrix is the transformation matrix that transforms the world
    //coordinates to view coordinates
    Matrix viewMatrix;

    Camera& lookAt(const Coord& point);

    //called when view matrix evaluation is needed before getting it
    Matrix getViewMatrix();





};
