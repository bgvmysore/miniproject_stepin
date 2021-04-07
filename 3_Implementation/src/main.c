#include <stdio.h>
#include "FirstOrderLinearODE.h"

double unit_step(double t){
    if (t < 0)
        return 0.00;
    else if (t == 0)
        return 0.50;
    else
        return 1.00;
}

int main(){
    FirstOrderLinearODE RL_ckt = FOLODE_init(-1e4, 1e3, unit_step);
    
    printf("A: %lf \t B: %lf \nu(t): t=-1 %lf, t=0 %lf, t=1 %lf\n", 
    RL_ckt.m_A, RL_ckt.m_B,
    RL_ckt.m_input_funct(-1.00),
    RL_ckt.m_input_funct( 0.00),
    RL_ckt.m_input_funct( 1.00)
    );
    
    return 0;
}
