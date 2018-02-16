#include "globals.hpp"

using namespace std;
using namespace GraphicsProject;

int main()
{
    Model* model = Components::loadModel("new.obj");
    for(int i=0;i<model->vertices.size();i++)
    {
        Vertex v = model->vertices.at(i);
        cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
    }
    return 0;

}