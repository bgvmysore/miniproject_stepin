#include "FirstOrderLinearODE.h"

FirstOrderLinearODE FOLODE_init(double _A, double _B, double (*_input_funct)(double _t) ){
    FirstOrderLinearODE retvar;
    retvar.m_A = _A;
    retvar.m_B = _B;
    retvar.m_input_funct = _input_funct;
    return retvar;
}