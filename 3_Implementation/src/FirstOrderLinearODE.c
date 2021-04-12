#include "FirstOrderLinearODE.h"

void FOLODE_init(FirstOrderLinearODE * _folode_obj, double _A, double _B, double (*_input_funct)(double _t), double _ipTimeDelay, double _init_state, double _freq){
    _folode_obj->m_A = _A;
    _folode_obj->m_B = _B;
    _folode_obj->m_input_funct = _input_funct;
    _folode_obj->m_input_time_delay = _ipTimeDelay;
    _folode_obj->m_init_state = _init_state;
    _folode_obj->m_ip_freq = _freq;
}

double FOLODE_getA(FirstOrderLinearODE const* _folode_obj){
    return _folode_obj->m_A;
}

double FOLODE_getB(FirstOrderLinearODE const* _folode_obj){
    return _folode_obj->m_B;
}

double FOLODE_getInitState(FirstOrderLinearODE const* _folode_obj){
    return _folode_obj->m_init_state;
}

double FOLODE_callInputFunct(FirstOrderLinearODE const* _folode_obj, double _t){
    if( _folode_obj->m_input_funct == sin){
        _t = 2 * 3.14159 * _folode_obj->m_ip_freq * ( (_t < _folode_obj->m_input_time_delay)? 0 : _t);
    }
    return _folode_obj->m_input_funct(_t - _folode_obj->m_input_time_delay);
}

double FOLODE_callStateEquation(void const* _folode_obj, double _t, double _prevState){
    // xdot = A * x + B * u
    return FOLODE_getA((FirstOrderLinearODE*)_folode_obj)*_prevState + 
    FOLODE_getB((FirstOrderLinearODE*)_folode_obj) * 
    FOLODE_callInputFunct((FirstOrderLinearODE*)_folode_obj, _t);
}