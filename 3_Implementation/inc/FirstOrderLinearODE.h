#ifndef FOLODE_H
#define FOLODE_H

#include<stdlib.h>
#include<stdio.h>

typedef struct _FOLODE{
    double m_A;
    double m_B;
    double m_input_time_delay;
    double (*m_input_funct)(double _t);
}FirstOrderLinearODE;

void FOLODE_init(FirstOrderLinearODE * _folode_obj, double _A, double _B, double (*_input_funct)(double _t), double _ipTimeDelay);

double FOLODE_getA(FirstOrderLinearODE const* _folode_obj);

double FOLODE_getB(FirstOrderLinearODE const* _folode_obj);

double FOLODE_callInputFunct(FirstOrderLinearODE const* _folode_obj, double _t);

double FOLODE_callStateEquation(void const* _folode_obj, double _t, double _prevState);

#endif //FOLO_H