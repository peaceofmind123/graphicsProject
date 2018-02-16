//
// Created by Satan on 2/13/2018.
//

#include "globals.hpp"

using namespace GraphicsProject;
using namespace std;
Model* Components::loadModel(const string& path )
{
    ifstream file;
    stringstream fileBuffer;
    Model*model=new Model();



    file.open(path.c_str());
    if(!file)
    {
        throw FileNotFoundException();
    }
    fileBuffer<<file.rdbuf();
    file.close();
    string line;
    vector<string> lines;
    vector<vector<string> > tokens;
    while(std::getline(fileBuffer,line))
    {
        lines.push_back(line);

    }
    for(unsigned i=0;i<lines.size();i++)
    {
        line=lines.at(i);
        vector<string> ts; //ts shorthand for tokens, tokens used elsewhere
        int spacePos = line.find(' ');
        string token;
        while(spacePos!=string::npos)
        {
             token = line.substr(0,spacePos);
            ts.push_back(token);
            line=line.substr(spacePos+1);
            spacePos=line.find(' ');
        }
        ts.push_back(line);
        tokens.push_back(ts);

    }
    for(unsigned i=0;i<tokens.size();i++)
    {
        vector<string> ts = tokens.at(i);

            if(ts.at(0)=="v")
            {

                Vertex* v = Components::parseVertex(ts);
                //todo define parseVertex
                model->vertices.push_back(*v);
            }
            else if(ts.at(0)=="vn")
            {
                VertexNormal *vn = Components::parseNormal(ts);
                model->vertexNormals.push_back(*vn);
            }
            else if (ts.at(0)=="f")
            {

                Surface *s = Components::parseSurface(ts,model);
                model->surfaces.push_back(*s);

            }
            else
            {
                throw BadFileException();
            }

    }
    return model;
}

Vertex* Components::parseVertex(const vector<string>& tokens)
{
    Vertex* v = new Vertex();
    if(tokens.size()==4)
    {
        //xyz coordinates available
        try
        {
            v->x = std::stod(tokens.at(1).c_str());
            v->y = std::stod(tokens.at(2).c_str());
            v->z = std::stod(tokens.at(3).c_str());
        }
        catch (exception& e) //this exception can be raised if the string to double conversion cannot occur
        {
            throw BadFileException();
        }

    }
    else if(tokens.size()==3)
    {
        //only x and y coordinates available
        try
        {
            v->x = std::stod(tokens.at(1));
            v->y= std::stod(tokens.at(2));
            v->z = 0; //default value

        }
        catch (exception& e)
        {
            throw BadFileException();

        }
    }
    else
    {
        throw BadFileException();
    }
    return v;
}

VertexNormal* Components::parseNormal(const vector<string>& tokens)
{
    //parses a line of the file to a vertexnormal object.
    VertexNormal* vn=new VertexNormal();
    if(tokens.size()==4)
    {
        try
        {
                vn->x = std::stod(tokens.at(1));
                vn->y = std::stod(tokens.at(2));
                vn->z = std::stod(tokens.at(3));
        }
        catch (exception& e)
        {
            throw BadFileException();
        }

    }
    else
    {
            throw BadFileException();
    }
    return vn;
}

Surface* Components::parseSurface(const vector<string>& tokens,Model* model)
{
    Surface* s;
    for(int i=1;i<tokens.size();i++) //note: i starts from 1 cuz the first token is f
    {
        string token = tokens.at(i);
        vector<string> subTokens;
        int numSlashes=0;
        int slashPos = token.find('/');
        while(slashPos!=string::npos)
        {
            numSlashes++;
            string subToken = token.substr(0,slashPos);
            if(!subToken.empty())
                subTokens.push_back(subToken);
            token=token.substr(slashPos+1);
            slashPos=token.find('/');
        }
        int k,l;
        if(subTokens.size()==3)
        {
            k = std::stoi(subTokens[0]); //1 is omitted cuz we do not need texture coordinates
            l = std::stoi(subTokens[2]);
        }
        else if(numSlashes==2) //vertex texture coordinates may not be present at all eg: 1//3
        {
            k=std::stoi(subTokens[0]);
            l=std::stoi(subTokens[1]);

        }
        else
        {
            throw BadFileException();
        }
        try
        {
            //association between a model's vertices and its vertexnormals (one-to-one) by pointers
            model->vertices[k-1].normal = &(model->vertexNormals[l-1]);

            model->vertexNormals[l-1].vertex = &(model->vertices[k-1]);

            //adding the reference of the vertex to the surface, this way, edges can be easily resolved
            s->vertices.push_back(&(model->vertices[k-1]));
        }
        catch (exception& e) //this error is caused when the vertex referenced by the face doesn't exist in the file

        {
            throw BadFileException();
        }
        return s;
    }
}
