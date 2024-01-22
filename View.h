#pragma once
#include "Model.h"

//Everything UI related
namespace View
{

class UI
{
public:
    void ShowMainMenu() const;

    int GetInput() const;


    Model::Point3D GetPoint() const; // from mouse click for example

    void ShowDocument (const Model::Document* theDocument) {} const

    // from mouse click
    Model::Document::GraphicalPrimitive GetGraphicalPrimitive (const Model::Point3D& aPoint) const;

    std::string EnterPath() const;

private:
    void ShowGraphicalPrimitive (const Model::Document::GraphicalPrimitive* thePrimitive) {}

    std::string ReturnPath() const;
};

};