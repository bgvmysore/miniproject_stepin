#ifndef FOLO_H
#define FOLO_H

typedef struct _FOLO{
    double m_A;
    double m_B;
    double (*m_input_funct)(double _t);
}FirstOrderLinearODE;

FirstOrderLinearODE FOLO_init(double _A, double _B, double (*_input_funct)(double _t) );

#endif //FOLO_H