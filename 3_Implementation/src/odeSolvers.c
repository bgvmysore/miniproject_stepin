#include "odeSolvers.h"

void solverFree(OdeSolverObject* _solObj);

void solverInit(OdeSolverObject* _solObj, double _t0, double _tend, double _dt, double _initState){
    _solObj->m_t0 = _t0;
    _solObj->m_tend = _tend;
    _solObj->m_dt = _dt;
    _solObj->Npoints = (int) ( (_tend - _t0)/_dt );
    _solObj->solArr = calloc(_solObj->Npoints, sizeof(double));
    _solObj->timeArr = calloc(_solObj->Npoints, sizeof(double));
    _solObj->initState = _initState;
    if(_solObj->solArr == NULL || _solObj->timeArr == NULL){
        fprintf(stderr, "\n[ERR]: Could Not allocate memory!\n");
        exit(EXIT_FAILURE);
    }
}

void solverFree(OdeSolverObject* _solObj){
    free(_solObj->solArr);
    free(_solObj->timeArr);
    _solObj->timeArr = NULL;
    _solObj->solArr = NULL;
}

void solverSolveEulerForward(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState)){
    double X0 = _solObj->initState;
    for(int i=0; i<_solObj->Npoints; i++){
        _solObj->timeArr[i] = _solObj->m_t0 + _solObj->m_dt * i;
        _solObj->solArr[i] = X0 + _solObj->m_dt * callStateEqofODE(_ODE_Obj, _solObj->timeArr[i], X0);
        X0 = _solObj->solArr[i];
    }
}

void solverSolveEulerModified(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState)){
    double X0 = _solObj->initState;
    for(int i=0; i<_solObj->Npoints; i++){
        _solObj->timeArr[i] = _solObj->m_t0 + _solObj->m_dt * i;
        
        double _tmp1 = X0 + _solObj->m_dt * callStateEqofODE(_ODE_Obj, _solObj->timeArr[i], X0);

        _solObj->solArr[i] = X0 + (_solObj->m_dt/2) * (callStateEqofODE(_ODE_Obj, _solObj->timeArr[i], X0) + 
        callStateEqofODE(_ODE_Obj, _solObj->timeArr[i] + _solObj->m_dt, _tmp1));
        
        X0 = _solObj->solArr[i];
    }
}

void solverSolveRungeKutta4(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState)){
    double X0 = _solObj->initState;
    for(int i=0; i<_solObj->Npoints; i++){
        _solObj->timeArr[i] = _solObj->m_t0 + _solObj->m_dt * i;

        double dt2 = (_solObj->m_dt/2 );
        double k1 = _solObj->m_dt * callStateEqofODE(_ODE_Obj, _solObj->timeArr[i], X0);
        double k2 = _solObj->m_dt * callStateEqofODE(_ODE_Obj, (_solObj->timeArr[i] + dt2), (X0 + k1*0.5));
        double k3 = _solObj->m_dt * callStateEqofODE(_ODE_Obj, (_solObj->timeArr[i] + dt2), (X0 + k2*0.5));
        double k4 = _solObj->m_dt * callStateEqofODE(_ODE_Obj, (_solObj->timeArr[i] + _solObj->m_dt), (X0 + k3));

        _solObj->solArr[i] = X0 + ( (k1 + 2 * k2 + 2 * k3 + k4) / 6 );

        X0 = _solObj->solArr[i];
    }
}