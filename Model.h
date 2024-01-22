#pragma once

#include <list>

//Everything that in storage related
namespace Model
{

//Probably this class should be in controller? 
class Point3D
{
public:

    Point3D (int _x = 0, int _y = 0, int _z = 0) : x (_x), y (_y), z (_z) {}
    
    int X() const { return x; }
    int Y() const { return y; }
    int Z() const { return z; }

private: 
    int x;
    int y;
    int z;

};

class Document
{
public:
    class GraphicalPrimitive;

public:
    Document() {}

    void Add (const GraphicalPrimitive& thePrimitive);

    void Remove (const GraphicalPrimitive& thePrimitive);

    class GraphicalPrimitive
    {
    public:
        GraphicalPrimitive (Point3D thePoint) : myCenter(thePoint) {}

        bool operator == (const GraphicalPrimitive& theRight) const;

    private:
        Point3D myCenter;
    };

private:
    std::list<GraphicalPrimitive> myBuf;
};

};
