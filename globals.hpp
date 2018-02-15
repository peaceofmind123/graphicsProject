#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include "exceptions.hpp"
namespace GraphicsProject{
    class Coord;
    class Edge;
    class Vertex;
    class Normal;
    class Surface;
    class VertexNormal;
    class SurfaceNormal;
    class Model;
    class Components;
    class BadFileException;
}
#include "Coord.hpp"
#include "Vertex.hpp"
#include "Normal.hpp"
#include "SurfaceNormal.hpp"
#include "VertexNormal.hpp"
#include "Edge.hpp"
#include "Surface.hpp"
#include "Model.hpp"
#include "Components.hpp"

using namespace std;
