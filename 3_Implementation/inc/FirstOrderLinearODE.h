#ifndef FOLODE_H
#define FOLODE_H

typedef struct _FOLODE{
    double m_A;
    double m_B;
    double (*m_input_funct)(double _t);
}FirstOrderLinearODE;

FirstOrderLinearODE FOLODE_init(double _A, double _B, double (*_input_funct)(double _t) );

#endif //FOLO_H