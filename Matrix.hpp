#include "globals.hpp"

using namespace std;
namespace GraphicsProject
{
    class Matrix
    {
    protected:

        //the width and height of the matrix
        unsigned rows;
        unsigned cols;

        //the actual data of the matrix
        double** data;

    public:
        Matrix(unsigned rows=4,unsigned cols=4,double**data=nullptr);
        //returns pointer to the value at [row][col]
        double* at(unsigned row,unsigned col);
        //the matrix multiplication operators
        Matrix& operator * (const Matrix& b);
        Vertex& operator * (const Vertex& v);
        inline int getRows(){return rows;}
        inline int getCols(){return cols;}
        //the inverse of the matrix
        Matrix& inv();

        //the destructor
        ~Matrix();
    };
}

