#include <stdio.h>
#include "FirstOrderLinearODE.h"
#include "primitive_funct.h"
#include "odeSolvers.h"

int main(void){

		FirstOrderLinearODE RL_ckt; 
		FOLODE_init(&RL_ckt, -1e4, 1e3, unit, 1e-3);

		OdeSolverObject solve_rl;
		solverInit(&solve_rl, 0.00, 3e-3, 10e-6, 0.00);

		solverSolveEulerForward(&solve_rl, &RL_ckt, FOLODE_callStateEquation);
		for(int i=0; i<solve_rl.Npoints; i++){
			printf("%lf\n", solve_rl.solArr[i]);
		}

		solverFree(&solve_rl);
		return 0;
}
