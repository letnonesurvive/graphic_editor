#include "Model.h"
#include "View.h"
#include "Controller.h"


int main()
{
    View::UI aUI;
    Model::Document aDocument;

    Controller::Logic aMainLogic (&aUI, &aDocument);
}
