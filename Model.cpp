#include "Model.h"

namespace Model 
{

void Document::Add(const GraphicalPrimitive& thePrimitive) 
{
    myBuf.push_back(thePrimitive);
}

void Document::Remove(const GraphicalPrimitive& thePrimitive)
{
    for (auto anIt = myBuf.cbegin(); anIt != myBuf.cend(); ++anIt) {
        if (*anIt == thePrimitive) {
            myBuf.erase(anIt);
        }
    }
}

bool Document::GraphicalPrimitive::operator==(const GraphicalPrimitive& theRight) const
{
    return myCenter.X() == theRight.myCenter.X() &&
           myCenter.Y() == theRight.myCenter.Y() &&
           myCenter.Z() == theRight.myCenter.Z();
}

}