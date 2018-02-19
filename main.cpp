#include "globals.hpp"

using namespace std;
using namespace GraphicsProject;

int main()
{
    Model* model = Components::loadModel("1.obj");
    for(int i =0;i<model->vertices.size();i++)
    {
            Vertex v=model->vertices.at(i);
            cout<<v.x<<" "<<v.y<<" "<<v.z<<endl;
            if(v.normal != nullptr)
                cout<<v.normal->x<<" "<<v.normal->y<<" "<<v.normal->z<<endl;

    }

    return 0;

}
