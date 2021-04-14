#ifndef _BASIC_IP_FUNCT_H_
#define _BASIC_IP_FUNCT_H_

#include <math.h>

/**
 * @brief Unit Step Function u(t)
 * This value of unit step function is 1 for t > 0 and 0 for t < 1.
 * 
 * @param _t (double) Value of the input variable (usually time)
 * @return double value of unit step function at 't'
 */
double unit(double _t);

/**
 * @brief Impulse Function i(t)
 * Ideally the value of Impulse function is infinity at t = 0, in this implementation it is 1e6 at t = 0 and 0 everywhere.
 * 
 * @param _t (double) value of the input variable (usually time)
 * @return double value of Impulse function 
 */
double impulse(double _t);

/**
 * @brief Ramp function r(t)
 * The value of ramp function is 0 for t < 0 and t for t >= 0.
 * 
 * @param _t (double) value of input variable (usually time)
 * @return double value of ramp function
 */
double ramp(double _t);

#endif // _BASIC_IP_FUNCT_H_