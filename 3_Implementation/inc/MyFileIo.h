#ifndef _MYFILEIO_H_
#define _MYFILEIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "FirstOrderLinearODE.h"
#include "odeSolvers.h"
#include "BasicIpFunctions.h"

void fileToFOLODEnSolObj(char *_path_to_data, FirstOrderLinearODE* _FOLODE_Obj,
                         OdeSolverObject* _solObj);

void saveSolToCsv(OdeSolverObject* _solObj);

#endif // _MYFILEIO_H_