#include <exception>
using namespace std;
namespace GraphicsProject
{
    class BadFileException: public exception
    {

        virtual const char* what() const throw()
        {
            return "Invalid file found!!";
        }
    };

    class FileNotFoundException: public exception
    {
        virtual const char* what() const throw()
        {
            return "File not found!!";
        }
    };
    class MatrixDimException: public exception
    {
        string message;
        virtual const char* what() const throw()
        {
            return message.c_str();
        }
    public:

        MatrixDimException(string s = "Matrix dimension error!!"):exception()
        {
            message = s;
        }

    };
    class MatrixMultiplicationException: public exception
    {
        string message;
        virtual const char* what() const throw()
        {
            return message.c_str();
        }
    public:

        MatrixMultiplicationException(string s="Cannot multiply the given matrices!!"):exception()
        {
            message=s;
        }

    };
};
