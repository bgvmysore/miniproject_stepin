#include <stdio.h>
#include "FirstOrderLinearODE.h"
#include "primitive_funct.h"

int main(){
		FirstOrderLinearODE* RL_ckt = malloc(sizeof(FirstOrderLinearODE)); 
		FOLODE_init(RL_ckt, -1e4, 1e3, unit, 0.0);

		printf("A: %lf \t B: %lf \nu(t): t=-1 %lf, t=0 %lf, t=1 %lf\n", 
		FOLODE_getA(RL_ckt), FOLODE_getB(RL_ckt),
		FOLODE_callInputFunct(RL_ckt, -1.00),
		FOLODE_callInputFunct(RL_ckt,  0.00),
		FOLODE_callInputFunct(RL_ckt,  1.00)
		);

		free(RL_ckt);		    
		return 0;
}
