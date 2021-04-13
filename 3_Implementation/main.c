#include <stdio.h>
#include "FirstOrderLinearODE.h"
#include "BasicIpFunctions.h"
#include "odeSolvers.h"
#include "MyFileIo.h"
#include "gnuplot_i.h"

int main(int argn, char** argv){

	FirstOrderLinearODE RL_ckt;
	OdeSolverObject solve_rl; 

	fileToFOLODEnSolObj("inputData.txt", &RL_ckt, &solve_rl);
	solverSolveRungeKutta4(&solve_rl, &RL_ckt, FOLODE_callStateEquation);
	saveSolToCsv(&solve_rl);

	saveSolToCsv(&solve_rl);
	dispSolAsPlot(&solve_rl);

	solverFree(&solve_rl);
	return 0;
}
