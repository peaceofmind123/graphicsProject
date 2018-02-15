#include "globals.hpp"
namespace GraphicsProject
{
    class Vertex:public Coord
    {
    public:

        vector<Edge*> edges;
        vector<Surface*> surfaces;
        VertexNormal* normal;
    };
}
