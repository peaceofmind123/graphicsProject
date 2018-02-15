#include <exception>
namespace GraphicsProject
{
    class BadFileException:public exception
    {
        virtual const char* what() const
        {
            return "Invalid file found!!";
        }
    };
    class FileNotFoundException: public exception
    {
        virtual const char* what() const
        {
            return "File not found!!";
        }
    };
}