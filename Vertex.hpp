#include "globals.hpp"
using namespace std;
namespace GraphicsProject
{
    class Vertex:public Coord
    {
    public:

        vector<Edge*> edges;
        vector<Surface*> surfaces;



    };
}
