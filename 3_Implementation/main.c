#include <stdio.h>
#include "FirstOrderLinearODE.h"
#include "BasicIpFunctions.h"
#include "odeSolvers.h"
#include "MyFileIo.h"
#include "gnuplot_i.h"

int main(int argn, char** argv){

	FirstOrderLinearODE odeSys;
	OdeSolverObject solveSys; 

	fileToFOLODEnSolObj("inputData.txt", &odeSys, &solveSys);

	// Display given
	printf("\nGiven Ode Eqn:\n");
	char somec = '0';
	if( odeSys.m_input_funct == sin)
		 somec = 's';
	else if(odeSys.m_input_funct == impulse)
		somec = 'i';
	else if(odeSys.m_input_funct == ramp)
		somec = 'r';
	else
		somec = 'u';
	printf("\n \t x'(t) = %lf * x(t) + %lf * %c(t - %lf)\n",
	odeSys.m_A, odeSys.m_B, somec, odeSys.m_input_time_delay);
	if(somec == 's'){
		printf("\n [*] s: sine wave of frequency f = %lf & t = (2 * pi * f * t )\n", odeSys.m_ip_freq);
	}
	
	printf("\n [*] Solution limits:  t1 = %lf \t t2 = %lf \t dt = %lf\n", solveSys.m_t0, solveSys.m_tend, solveSys.m_dt);

	printf("\n [*] intial state x(t1): %lf\n", odeSys.m_init_state);


	// ask for solver choice
	short solverChoice = 0;
	printf("\n\n Following Numerical Methods are available to solve your ODE,\n");
	printf("   1. Euler Forward Method\n   2. Modified Euler Method \n   3. Runge Kutta 4 Method\n");
	printf("\nEnter your preferred solver [default: 3]: ");
	scanf("%hd", &solverChoice);
	
	switch (solverChoice)
	{
	case 1:
		solverSolveEulerForward(&solveSys, &odeSys, FOLODE_callStateEquation);
		break;
	case 2:
		solverSolveEulerModified(&solveSys, &odeSys, FOLODE_callStateEquation);
		break;
	case 3:
		solverSolveRungeKutta4(&solveSys, &odeSys, FOLODE_callStateEquation);
		break;
	default:
		printf("\n[ ! ] Unknown Option entered...Using the default RK4 Method to solve ODE\n\n");
		solverSolveRungeKutta4(&solveSys, &odeSys, FOLODE_callStateEquation);
		break;
	}
	
	saveSolToCsv(&solveSys);
	//dispSolAsPlot(&solveSys);

	solverFree(&solveSys);
	return 0;
}
