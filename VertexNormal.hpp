#include "globals.hpp"
namespace GraphicsProject
{
    class VertexNormal:public Normal
    {
    public:
        Vertex* vertex;
        VertexNormal()
        {
            vertex = new Vertex();


        }
        ~VertexNormal()
        {
            delete vertex;
        }
    };
}
