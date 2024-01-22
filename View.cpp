#include "View.h"
#include <iostream>

using namespace std;

namespace View 
{

void UI::ShowMainMenu() const
{
    cout << "1: Create new document" << endl;
    cout << "2: Import document from file" << endl;
    cout << "3: Export document to file" << endl;
    cout << "4: Create graphical primitive" << endl;
    cout << "5: Delete graphical primitive" << endl;
}

int UI::GetInput() const
{
    int aNumber;
    cin >> aNumber;
    return aNumber;
}

Model::Point3D UI::GetPoint() const
{
    return Model::Point3D();
}

const Model::Document::GraphicalPrimitive UI::GetGraphicalPrimitive (const Model::Point3D & aPoint) const
{
    return Model::Document::GraphicalPrimitive (aPoint);
}

std::string UI::EnterPath() const
{
    string aPath = ReturnPath();
    return aPath;
}

std::string UI::ReturnPath() const
{ 
    return string(); 
}

}