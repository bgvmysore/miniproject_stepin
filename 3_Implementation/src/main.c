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

		gnuplot_ctrl *h1;
		h1 = gnuplot_init();
		gnuplot_resetplot(h1);
		gnuplot_setstyle(h1, "lines");
		gnuplot_plot_xy(h1, solve_rl.timeArr, solve_rl.solArr, solve_rl.Npoints, "RL CKT");
		getchar();
		gnuplot_close(h1);

		solverFree(&solve_rl);
		return 0;
}
