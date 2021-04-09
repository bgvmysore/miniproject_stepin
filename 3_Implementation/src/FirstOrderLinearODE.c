#include "FirstOrderLinearODE.h"

void FOLODE_init(FirstOrderLinearODE * _folode_obj, double _A, double _B, double (*_input_funct)(double _t) ){
    if(_folode_obj == NULL)
        fprintf(stderr,"FOLODE OBJECT POINTING TO NULL\n");
    _folode_obj->m_A = _A;
    _folode_obj->m_B = _B;
    _folode_obj->m_input_funct = _input_funct;
}

double FOLODE_getA(FirstOrderLinearODE const* _folode_obj){
    return _folode_obj->m_A;
}

double FOLODE_getB(FirstOrderLinearODE const* _folode_obj){
    return _folode_obj->m_B;
}

double FOLODE_callInputFunct(FirstOrderLinearODE const* _folode_obj, double _t){
    return _folode_obj->m_input_funct(_t);
}