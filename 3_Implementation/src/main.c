#include <stdio.h>
#include "FirstOrderLinearODE.h"
#include "primitive_funct.h"
#include "odeSolvers.h"
#include "gnuplot_i.h"

int main(void){

		FirstOrderLinearODE RL_ckt; 
		FOLODE_init(&RL_ckt, -1e4, 1e3, unit, 1e-3);

		OdeSolverObject solve_rl;
		solverInit(&solve_rl, 0.00, 3e-3, 20e-6, 0.00);

		solverSolveEulerForward(&solve_rl, &RL_ckt, FOLODE_callStateEquation);
		for(int i=0; i<solve_rl.Npoints; i++){
			printf("%lf\n", solve_rl.solArr[i]);
		}

		gnuplot_ctrl *h1;
		h1 = gnuplot_init();
		gnuplot_resetplot(h1);
		gnuplot_setstyle(h1, "lines");
		gnuplot_plot_xy(h1, solve_rl.timeArr, solve_rl.solArr, solve_rl.Npoints, "RL CKT");
		getchar();
		solverFree(&solve_rl);
		return 0;
}
