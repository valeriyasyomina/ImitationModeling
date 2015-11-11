#include "Singleton.h"
#include <stdio.h>

Singleton Singleton::instance;

Singleton::Singleton()
{
    controlProgram = new ControlProgram();
}

Singleton::~Singleton()
{
    if (controlProgram)
    {
        delete controlProgram;
        controlProgram = NULL;
    }
}

ControlProgram* Singleton::GetControlProgram()
{
    if (!controlProgram)
        controlProgram = new ControlProgram();
    return controlProgram;
}


