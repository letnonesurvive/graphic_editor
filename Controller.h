#pragma once
#include "Model.h"
#include "View.h"
#include <string>

//Everything in business logic related
namespace Controller
{
using namespace std;

class Importer
{
public:
    void Import (const string& thePath, Model::Document* theDocument);

private:
    void DoImport (const string& thePath, Model::Document* theDocument);

};

class Exporter
{
public:
    void Export (const string& thePath, Model::Document* theDocument);

private:
    void DoExport (const string& thePath, Model::Document* theDocument);

};

class Logic
{

public:
    Logic (View::UI* theUI, Model::Document* theDocument);

private:
    void DoLogic();

    void DoRequestedFunctional (int theInput);

private:
    View::UI* myUI;
    Model::Document* myDocument;
};

};