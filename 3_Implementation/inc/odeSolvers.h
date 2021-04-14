#ifndef ODESOLVERS_H
#define ODESOLVERS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief This object or struct is used to store information about the solution.
 * It stores information such as t0, tend, dt ie details about solution limits,
 * Npoints: total points in the solution array,
 * initial state at t0 and more
 */
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

/**
 * @brief This function initializes the OdeSolverObject.
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 * @param _t0 (double) initial point
 * @param _tend (double) final point
 * @param _dt (double) step size
 * @param _initState (double) initial value at t0
 */
void solverInit(OdeSolverObject* _solObj, double _t0, double _tend, double _dt, double _initState);

/**
 * @brief This function is used to clean-up memory and de-allocate memory which was allocated in init method.
 * This frees up memory of dynamically allocated memory. This function is used to destroy OdeSolverObject
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 */
void solverFree(OdeSolverObject* _solObj);

/**
 * @brief This function solves the ODE using Euler Forward Method.
 * This function basically modifies the solArr and timeArr attributes of OdeSolverObject.
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 * @param _ODE_Obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param callStateEqofODE function pointer to call state equation ie x'(t)
 */
void solverSolveEulerForward(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState));

/**
 * @brief This function solves the ODE using Modified Euler Method.
 * This function basically modifies the solArr and timeArr attributes of OdeSolverObject.
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 * @param _ODE_Obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param callStateEqofODE function pointer to call state equation ie x'(t)
 */
void solverSolveEulerModified(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState));

/**
 * @brief This function solves the ODE using Runge-Kutta4 Method.
 * This function basically modifies the solArr and timeArr attributes of OdeSolverObject.
 * 
 * @param _solObj (OdeSolverObject *) pointer Ode solver object
 * @param _ODE_Obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param callStateEqofODE function pointer to call state equation ie x'(t)
 */
void solverSolveRungeKutta4(OdeSolverObject* _solObj, void const* _ODE_Obj, 
double (*callStateEqofODE)(void const* _folode_obj, double _t, double _prevState));

#endif // ODESOLVER_H
