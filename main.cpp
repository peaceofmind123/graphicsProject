#include "globals.hpp"
#include <graphics.h>
using namespace std;
using namespace GraphicsProject;

int main()
{
    int gd=DETECT, gm;
    Model* model = Components::loadModel("pandamale.obj");
    initwindow(640,480);
    double xMax=-1000,yMax=-1000,xMin=4000,yMin=4000,xVal,yVal;
    for(int i=0;i<model->vertices.size();i++)
    {

            Vertex v = model->vertices[i];

            xVal = v.x;
            yVal = v.y;

            if(xVal>xMax)
                xMax=xVal;
            if(xVal<xMin)
                xMin=xVal;
            if(yVal>yMax)
                yMax=yVal;
            if(yVal<yMin)
                yMin=yVal;
        }



    double xScale = 640/(xMax-xMin);
    double yScale = 480/(yMax-yMin);
    double x1Val,x2Val,y1Val,y2Val;
    for(int i=0;i<model->surfaces.size();i++)
    {
        Surface s = model->surfaces[i];
        for(int j =1;j<s.vertices.size();j++)
        {
            Vertex* v1 = (s.vertices[j-1]);
            Vertex* v2 = (s.vertices[j]);
            x1Val = (v1->x-xMin)*xScale;
            x2Val = (v2->x-xMin)*xScale;
            y1Val = (v1->y-yMin)*yScale;
            y2Val = (v2->y-yMin)*yScale;
            line(x1Val,y1Val,x2Val,y2Val);
        }


    }
    getch();
    closegraph();
    return 0;

}
