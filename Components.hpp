#include "globals.hpp"
using namespace std;
namespace GraphicsProject
{
    class Components
    {
    public:
        /**@loadModel: parses the entire object file passed as its path as an argument
        into a model object*/

        static Model* loadModel(const string& path);

        /**@parseVertex: parses a vector of tokens into a vertex object and throws badfile exception if it cannot**/
        static Vertex* parseVertex(const vector<string>& tokens);
        /**@parseSurface: parses a vector of tokens into a surface object
        additionally, it resolves the relationships between vertices, vertexnormals, surfaces and edges**/

        static Surface* parseSurface(const vector<string>& tokens, Model* model);

    };
}

