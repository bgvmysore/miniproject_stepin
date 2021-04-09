#include "primitive_funct.h"

double unit(double _t){
    	if (_t < 0)
				return 0.00;
		else if (_t == 0)
				return 0.50;
		else
				return 1.00;
}

double impulse(double _t){
    double dt = 1e-7;
    return ( unit( _t + dt ) - unit (_t ) / dt );
}