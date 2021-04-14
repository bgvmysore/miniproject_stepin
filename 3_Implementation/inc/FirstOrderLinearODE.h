#ifndef FOLODE_H
#define FOLODE_H

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/**
 * @brief This struct is used to store all the data related to First Order Linear Differential Equation.
 * x'(t) = A * x(t)  + B * u(t - s) with initial value x0 at t0
 */
typedef struct FirstOrderLinearODE{
    double m_A;
    double m_B;
    double m_input_time_delay;
    double m_init_state;
    double (*m_input_funct)(double _t);
    double m_ip_freq;
}FirstOrderLinearODE;

/**
 * @brief This function is used to initialize the first order linear ODE object.
 * x'(t) = A * x(t)  + B * u(t - s) with initial value x0 at t0
 * 
 * @param _folode_obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param _A (double) Value of A in ODE
 * @param _B (double) Value of B in ODE
 * @param _input_funct ( function pointer ) Input function for the ODE
 * @param _ipTimeDelay (double) time shift of the input function
 * @param _init_state (double) Initial state of state variable x at t0
 * @param _freq (double) frequency of input function if input function is sin
 */
void FOLODE_init(
                    FirstOrderLinearODE * _folode_obj, 
                    double _A, 
                    double _B, 
                    double (*_input_funct)(double _t), 
                    double _ipTimeDelay, 
                    double _init_state, 
                    double _freq
                );

/**
 * @brief Call input function of the ODE Equation.
 * ODE : x'(t) = A * x(t)  + B * u(t - s) with initial value x0 at t0
 * call u(t - s) at given t
 * @param _folode_obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param _t (double) value of input variable (usually time)
 * @return double value of input function
 */
double FOLODE_callInputFunct(FirstOrderLinearODE const* _folode_obj, double _t);

/**
 * @brief This function returns the value of x'(t) at t in the ODE eqation.
 * ie x'(t) = A * x(t_prev) + B * u(t - s) at t
 * 
 * @param _folode_obj (FirstOrderLinearODE *) pointer to first order linear ODE object
 * @param _t (double) value of independent variable of ODE (usually time)
 * @param _prevState the value of state variable x(t) at privious t ie., t = t-dt
 * @return double value of x'(t) at given t
 */
double FOLODE_callStateEquation(void const* _folode_obj, double _t, double _prevState);

#endif //FOLO_H