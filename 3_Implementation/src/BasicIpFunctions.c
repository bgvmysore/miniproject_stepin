#include "BasicIpFunctions.h"

double unit(double _t){
    	if (_t < 0)
				return 0.00;
		else if (_t == 0)
				return 0.50;
		else
				return 1.00;
}

double impulse(double _t){
    double dt = 1e-6;
    if(_t == 0)
        return (1/dt);
    else if( _t > -dt && _t < dt)
        return (1/(4 * dt));
    else
        return 0;  
}

double ramp(double _t){
	if(_t <= 0)
		return 0.0;
	else
		return _t;
}