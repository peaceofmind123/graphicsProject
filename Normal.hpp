#include "globals.hpp"
using namespace std;
namespace GraphicsProject
{
    class Normal: public Coord
    {
    public:
        bool isNormalized() const;
        Normal& normalize(); //normalizes the normal
    };
}
