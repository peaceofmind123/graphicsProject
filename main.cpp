#include "globals.hpp"
#include <graphics.h>
using namespace std;
using namespace GraphicsProject;

int main()
{

    Matrix a(5,5),b(5,5),c(5,5);

    for(int i =0;i<a.getRows();i++)
    {
        for(int j=0;j<a.getCols();j++)
        {
            *(a.at(i,j))=i+j;
            *(b.at(i,j))=i-j;
        }
    }
    c=a*b;
    for(int i=0;i<c.getRows();i++)
    {
        for(int j=0;j<c.getCols();j++)
        {
            cout<<*(c.at(i,j))<<" ";

        }
        cout<<endl;
    }
    return 0;
}
