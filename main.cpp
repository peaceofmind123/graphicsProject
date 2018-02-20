#include "globals.hpp"

using namespace std;
using namespace GraphicsProject;

int main()
{
    Model* model = Components::loadModel("1.obj");
    for(int i =0;i<model->surfaces.size();i++)
    {
        Surface s = model->surfaces.at(i);
        for(int j =0; j<s.vertices.size();j++)
        {
            Vertex* v = s.vertices.at(j);
            cout<<v->x<<" "<<v->y<<" "<<v->z<<endl;
        }
    }

    return 0;

}
