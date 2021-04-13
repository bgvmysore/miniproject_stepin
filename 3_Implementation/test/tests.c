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
    return ; 
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

    TEST_ASSERT_EQUAL(111, FOLODE_callStateEquation(&obj, 0.0, 10));
    TEST_ASSERT_EQUAL(12.1,FOLODE_callStateEquation(&obj, 1e-3, 10.0));
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_basicIpFunctions);
    RUN_TEST(test_FOLODE_init);
    RUN_TEST(test_FOLODE_callInputFunct);
    RUN_TEST(test_FOLODE_callStateEquation);
    return UNITY_END();
}