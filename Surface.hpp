#include "globals.hpp"
using namespace std;
namespace GraphicsProject
{
    class Surface
    {
    public:

        vector<Vertex*> vertices;
        //the vertices of the surface in order
        SurfaceNormal normal;
    };
}
