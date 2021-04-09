#ifndef ODESOLVERS_H
#define ODESOLVERS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct OdeSolverObject
{
    double m_t0;
    double m_tend;
    double m_dt;
    int Npoints;
    double* timeArr;
    double* solArr;
    double initState;

}OdeSolverObject;

void solverInit(OdeSolverObject* _solObj, double _t0, double _tend, double _dt, double _initState);

void solverFree(OdeSolverObject* _solObj);

void solverSolveEulerForward(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState));

#endif // ODESOLVER_H
