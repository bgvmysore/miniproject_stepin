#include "unity.h"
#include "BasicIpFunctions.h"
#include "FirstOrderLinearODE.h"
#include "MyFileIo.h"
#include "odeSolvers.h"
#include "gnuplot_i.h"

void setUp(void){
    return; 
}

void tearDown(void){
    return; 
}

void test_basicIpFunctions(void){
    // unit-step
    TEST_ASSERT_EQUAL(0, unit(-0.4598));
    TEST_ASSERT_EQUAL(0.5, unit(0.0000));
    TEST_ASSERT_EQUAL(1, unit(1.4598));

    // impulse
    TEST_ASSERT_EQUAL(0, impulse(-1.1));
    TEST_ASSERT_EQUAL(1e6, impulse(0));
    TEST_ASSERT_EQUAL(0, impulse(10.012));
    TEST_ASSERT_TRUE(impulse(0.5e-6)>0);
    TEST_ASSERT_TRUE(impulse(-0.5e-6)>0);

    // ramp
    TEST_ASSERT_EQUAL(0, ramp(-0.1));
    TEST_ASSERT_EQUAL(2.414, ramp(2.414));
    TEST_ASSERT_EQUAL(0.0, ramp(-1000));
}

void test_FOLODE_init(void){
    FirstOrderLinearODE obj;
    FOLODE_init(&obj, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    TEST_ASSERT_EQUAL(1.1, obj.m_A);
    TEST_ASSERT_EQUAL(2.2, obj.m_B);
    TEST_ASSERT_EQUAL(unit, obj.m_input_funct);
    TEST_ASSERT_EQUAL(1e-3, obj.m_input_time_delay);
    TEST_ASSERT_EQUAL(0.1, obj.m_init_state);
    TEST_ASSERT_EQUAL(1e3, obj.m_ip_freq);
}

void test_FOLODE_callInputFunct(void){
    FirstOrderLinearODE obj;
    FOLODE_init(&obj, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    TEST_ASSERT_EQUAL(0.5, FOLODE_callInputFunct(&obj, 0.0));
    TEST_ASSERT_EQUAL(0.0, FOLODE_callInputFunct(&obj, -12.12));
    TEST_ASSERT_EQUAL(1.0, FOLODE_callInputFunct(&obj, 12.12));
}

void test_FOLODE_callStateEquation(void){
    FirstOrderLinearODE obj;
    FOLODE_init(&obj, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);

    TEST_ASSERT_EQUAL(0.0, FOLODE_callStateEquation(&obj, 0.0, 0.0));
    TEST_ASSERT_EQUAL(1.1, FOLODE_callStateEquation(&obj, 1e-3, 0.0));
    TEST_ASSERT_EQUAL(2.2, FOLODE_callStateEquation(&obj, 10.0, 0.0));

    TEST_ASSERT_EQUAL(11, FOLODE_callStateEquation(&obj, 0.0, 10));
    TEST_ASSERT_EQUAL(12.1,FOLODE_callStateEquation(&obj, 1e-3, 10.0));
}

void test_solverInit(void){
    OdeSolverObject solobj;
    solverInit(&solobj, 0.0, 10.00, 0.5, 0.1);
    TEST_ASSERT_EQUAL(0.0, solobj.m_t0);
    TEST_ASSERT_EQUAL(10, solobj.m_tend);
    TEST_ASSERT_EQUAL(0.5, solobj.m_dt);
    TEST_ASSERT_EQUAL(20, solobj.Npoints);
    TEST_ASSERT_EQUAL(0.1, solobj.initState);
    TEST_ASSERT_TRUE(solobj.solArr != NULL && solobj.timeArr != NULL);
    solverFree(&solobj);
}

void test_solverFree(void){
    OdeSolverObject solobj;
    solverInit(&solobj, 0.0, 10.00, 0.5, 0.1);
    solverFree(&solobj);
    TEST_ASSERT_EQUAL(NULL, solobj.solArr);
    TEST_ASSERT_EQUAL(NULL, solobj.timeArr);
}

void test_solverSolveEulerForward(void){
    FirstOrderLinearODE ode;
    OdeSolverObject solver;

    FOLODE_init(&ode, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    solverInit(&solver, 0.0, 10.00F, 0.5F, 0.1);
    solverSolveEulerForward(&solver, &ode, FOLODE_callStateEquation);
    TEST_ASSERT_EQUAL(0.0, solver.timeArr[0]);
    TEST_ASSERT_EQUAL(0.0 + 3*0.5, solver.timeArr[3]);
    TEST_ASSERT_EQUAL(9.5 , solver.timeArr[solver.Npoints-1]);
    
    double tmp = 0.1 + (0.5)*(1.1 * 0.1 + 2.2 * 0.0);
    TEST_ASSERT_EQUAL(tmp, solver.solArr[0]);
    
    solverFree(&solver);
}

void test_solverSolveEulerModified(void){
    FirstOrderLinearODE ode;
    OdeSolverObject solver;

    FOLODE_init(&ode, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    solverInit(&solver, 0.0, 10.00F, 0.5F, 0.1);
    solverSolveEulerModified(&solver, &ode, FOLODE_callStateEquation);
    TEST_ASSERT_EQUAL(0.0, solver.timeArr[0]);
    TEST_ASSERT_EQUAL(0.0 + 3*0.5, solver.timeArr[3]);
    TEST_ASSERT_EQUAL(9.5 , solver.timeArr[solver.Npoints-1]);

    double tmp = 0.1 + 0.5 * (0.1 * 1.1 + 2.2 * 0.0);
    tmp = 0.1 + (0.5/2) * ( ( 1.1 *(0.1 + tmp) + 2.2 * 0.0) + (1.1 * 0.1) ) ;
    TEST_ASSERT_EQUAL(tmp, solver.solArr[0]);
    
    solverFree(&solver);
}

void test_solverSolveRungeKutta4(void){
    FirstOrderLinearODE ode;
    OdeSolverObject solver;

    FOLODE_init(&ode, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    solverInit(&solver, 0.0, 10.00F, 0.5F, 0.1);
    solverSolveRungeKutta4(&solver, &ode, FOLODE_callStateEquation);
    TEST_ASSERT_EQUAL(0.0, solver.timeArr[0]);
    TEST_ASSERT_EQUAL(0.0 + 3*0.5, solver.timeArr[3]);
    TEST_ASSERT_EQUAL(9.5 , solver.timeArr[solver.Npoints-1]);

    double k1, k2, k3, k4, tmp;
    k1 = 0.5 * (1.1 * 0.1         + 2.2 *unit(0.0        - 1e-3));
    k2 = 0.5 * (1.1 *(0.1 + k1/2) + 2.2 *unit(0.0 + 0.25 - 1e-3));
    k3 = 0.5 * (1.1 *(0.1 + k2/2) + 2.2 *unit(0.0 + 0.25 - 1e-3));
    k4 = 0.5 * (1.1 *(0.1 +   k3) + 2.2 *unit(0.0 + 0.50 - 1e-3));

    tmp = 0.1 + (k1 + 2*k2 + 2*k3 + k4)/6;

    TEST_ASSERT_EQUAL(tmp, solver.solArr[0]);
    
    solverFree(&solver);
}

void test_fileToFOLODEnSolObj(void){
    FirstOrderLinearODE ode;
    OdeSolverObject solver;
    fileToFOLODEnSolObj("test/test_inputData.txt", &ode, &solver);
    
    TEST_ASSERT_EQUAL(1.1, ode.m_A);
    TEST_ASSERT_EQUAL(2.1, ode.m_B);
    TEST_ASSERT_EQUAL(unit, ode.m_input_funct);
    TEST_ASSERT_EQUAL(0.1, ode.m_init_state);
    TEST_ASSERT_EQUAL(0.2, ode.m_input_time_delay);
    TEST_ASSERT_EQUAL(1e3, ode.m_ip_freq);
    TEST_ASSERT_EQUAL(0.0, solver.m_t0);
    TEST_ASSERT_EQUAL(10.0, solver.m_tend);
    TEST_ASSERT_EQUAL(0.5, solver.m_dt);

    solverFree(&solver);
}

void test_outputsolmethods(void){
    FirstOrderLinearODE ode;
    OdeSolverObject solver;

    FOLODE_init(&ode, 1.1, 2.2, unit, 1e-3, 0.1, 1e3);
    solverInit(&solver, 0.0, 10.00F, 0.5F, 0.1);
    TEST_ASSERT_EQUAL(1, saveSolToCsv(&solver));
    //TEST_ASSERT_EQUAL(1, dispSolAsPlot(&solver)); // does not work on remote server / container
    solverFree(&solver);
}

int main(){
    UNITY_BEGIN();

    RUN_TEST(test_basicIpFunctions);
    RUN_TEST(test_FOLODE_init);
    RUN_TEST(test_FOLODE_callInputFunct);
    RUN_TEST(test_FOLODE_callStateEquation);
    RUN_TEST(test_solverInit);
    RUN_TEST(test_solverFree);
    RUN_TEST(test_solverSolveEulerForward);
    RUN_TEST(test_solverSolveEulerModified);
    RUN_TEST(test_solverSolveRungeKutta4);
    RUN_TEST(test_fileToFOLODEnSolObj);
    RUN_TEST(test_outputsolmethods);
    
    return UNITY_END();
}