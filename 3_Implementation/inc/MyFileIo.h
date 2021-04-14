#ifndef _MYFILEIO_H_
#define _MYFILEIO_H_

#include <stdio.h>
#include <stdlib.h>
#include "FirstOrderLinearODE.h"
#include "odeSolvers.h"
#include "BasicIpFunctions.h"
#include "gnuplot_i.h"

/**
 * @brief This function takes in a text-file of specfied format and reads the information regarding the
 * ODE and solution limits and stores the same in the FirstOrderLinearODE and OdeSolverObject
 * The format of text file:
 * 
 * A(double)
 * B(double)
 * input_function(char:u,i,,r,s) time-shift(double) frequency(double)
 * initial-state(double)
 * t0(double) tend(double) dt(double)
 * 
 * @param _path_to_data (char*) path to file containing input data textfile
 * @param _FOLODE_Obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 */
void fileToFOLODEnSolObj(char *_path_to_data, FirstOrderLinearODE* _FOLODE_Obj,
                         OdeSolverObject* _solObj);


/**
 * @brief Saves the solution to csv file
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 */
void saveSolToCsv(OdeSolverObject* _solObj);

/**
 * @brief Display the solution as plot using gnuplot
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 */
void dispSolAsPlot(OdeSolverObject* _solObj);

#endif // _MYFILEIO_H_