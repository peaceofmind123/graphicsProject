#include "globals.hpp"
using namespace GraphicsProject;
using namespace std;

Matrix::Matrix(unsigned rows,unsigned cols,double**data)
{

    this->rows=rows;
    this->cols = cols;
    this->data = new double*[rows];


    for(int i=0;i<rows;i++)
    {
        this->data[i] = new double[cols];

        for(int j=0;j<cols;j++)
        {
            if(data!=nullptr && data[i]!=nullptr)
                this->data[i][j] = data[i][j];
        }

    }
}

Matrix::~Matrix()
{
    for(int i=0;i<this->rows;i++)
    {
        delete this->data[i];
    }
    delete this->data;
}

double* Matrix::at(unsigned row,unsigned col)
{
    if(row<rows&& col<cols)
        return &data[row][col];
    throw MatrixDimException("Matrix index out of range");


}

Matrix& Matrix::operator * (const Matrix& b)
{
    Matrix* ans=new Matrix(this->rows,b.cols);
    Eigen::MatrixXf matA(this->rows,this->cols),
             matB(b.rows,b.cols),
             matAns(this->rows,b.cols);
    for(int i=0;i<rows;i++)
    {
        for(int j =0;j<cols;j++)
        {
            matA(i,j) = data[i][j];
        }
    }
    for(int i=0;i<b.rows;i++)
    {
        for(int j=0;j<b.cols;j++)
        {
            matB(i,j) = b.data[i][j];
        }
    }
    matAns = matA*matB;
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<b.cols;j++)
            ans->data[i][j]=matAns(i,j);

    }
    return *ans;




}
