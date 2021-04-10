#ifndef _MYFILEIO_H_
#define _MYFILEIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "FirstOrderLinearODE.h"
#include "odeSolvers.h"
#include "BasicIpFunctions.h"

void fileToFOLODEnSolObj(FILE **_data_file, FirstOrderLinearODE* _FOLODE_Obj, OdeSolverObject* _solObj);

#endif // _MYFILEIO_H_