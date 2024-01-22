#include "Controller.h"
#include <iostream>

namespace Controller
{

void Importer::Import (const string& thePath, Model::Document* theDocument)
{
    DoImport (thePath, theDocument);
}

void Importer::DoImport (const string& thePath, Model::Document* theDocument)
{
    //importing document
}

void Exporter::Export (const string& thePath, Model::Document* theDocument)
{
    DoExport(thePath, theDocument);
}

void Exporter::DoExport (const string& thePath, Model::Document* theDocument)
{
    //exporting document
}

Logic::Logic (View::UI* theUI, Model::Document* theDocument) 
{
    myUI = theUI;
    myDocument = theDocument;

    DoLogic();
}

void Logic::DoLogic()
{
    // ask user to choose the menu section's
    myUI->ShowMainMenu();

    // get from user requested section
    int anInput;
    anInput = myUI->GetInput();

    DoRequestedFunctional (anInput);

    // rendering
    myUI->ShowDocument (myDocument);
}

void Logic::DoRequestedFunctional (int theInput)
{
    if (theInput == 1) { // replace to switch
        myDocument = new Model::Document();
        cout << "New document created" << endl;
    }
    else if (theInput == 2) {
        Importer anImporter;
        anImporter.Import (myUI->EnterPath(), myDocument);
        cout << "The document has been imported" << endl;
    }
    else if (theInput == 3) {
        Exporter anExporter;
        anExporter.Export (myUI->EnterPath(), myDocument);
        cout << "The document has been exported" << endl;
    }
    else if (theInput == 4) {
        Model::Point3D aPoint = myUI->GetPoint();
        Model::Document::GraphicalPrimitive aPrimitive(aPoint);
        myDocument->Add (aPrimitive);
        cout << "New primitive was added on the document" << endl;
    }
    else if (theInput == 5) {
        Model::Point3D aPoint = myUI->GetPoint();
        auto aPrimitive = myUI->GetGraphicalPrimitive (aPoint);
        myDocument->Remove (aPrimitive);
        cout << "Primitive has been removed from the document" << endl;
    }
}

}