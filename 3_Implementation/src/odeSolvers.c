#include "odeSolvers.h"

void solverFree(OdeSolverObject* _solObj);

void solverInit(OdeSolverObject* _solObj, double _t0, double _tend, double _dt, double _initState){
    _solObj->m_t0 = _t0;
    _solObj->m_t0 = _tend;
    _solObj->m_dt = _dt;
    _solObj->Npoints = (int) (_tend - _t0)/_dt;
    _solObj->solArr = calloc(_solObj->Npoints, sizeof(double));
    _solObj->timeArr = calloc(_solObj->Npoints, sizeof(double));
    _solObj->initState = _initState;
}

void solverFree(OdeSolverObject* _solObj){
    free(_solObj->solArr);
    free(_solObj->timeArr);
}

void solverSolveEulerForward(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState)){
    double X0 = _solObj->initState;
    for(int i=0; i<_solObj->Npoints; i++){
        _solObj->solArr[i] = X0 + _solObj->m_dt * callStateEqofODE(_ODE_Obj, _solObj->timeArr[i], X0);
        X0 = _solObj->solArr[i];
    }
}