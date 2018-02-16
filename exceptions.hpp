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
};
