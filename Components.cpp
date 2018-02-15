//
// Created by Satan on 2/13/2018.
//

#include "globals.hpp"

using namespace GraphicsProject;

static Model& Component::loadModel(const string& path )
{
    ifstream file;
    stringstream fileBuffer;
    Model model;
    Surface s;
    Vertex v;
    VertexNormal vn;
    SurfaceNormal sn;
    Edge e;
    file.open(path);
    if(!file)
    {
        throw FileNotFoundException();
    }
    fileBuffer<<file.rdbuf();
    string line;
    while(std::getline(fileBuffer,line))
    {
        vector<string> tokens;
        size_t spacePos = line.find(' ');
        while(spacePos!=string::npos)
        {
            string token = line.substr(0,spacepos);
            tokens.push_back(token);
            line = line.substr(spacePos+1);
            spacePos=line.find(' ');
        }
        if(tokens.at(0)=="v")
        {

            try
            {
                double x = std::stod(tokens.at(1));
                double y = std::stod(tokens.at(2));
                double z = std::stod(tokens.at(3));
                v.x = x;
                v.y = y;
                v.z = z;
                model.vertices.push_back(v);
            }
            catch(exception& e)
            {
                #todo: handle the exceptions properly
                cerr<<e.what();

            }


        }
        else if(tokens.at(0)=="vn") //vertex normals
        {
            try
            {
                double x = std::stod(tokens.at(1));
                double y = std::stod(tokens.at(2));
                double z = std::stod(tokens.at(3));
                vn.x = x;
                vn.y = y;
                vn.z = z;
                #todo: find a way to assign normal to the correct vertex
            }
            catch(exception& e)
            {
                #todo: handle the exceptions properly
                cerr<<e.what();

            }
        }
    }
}
