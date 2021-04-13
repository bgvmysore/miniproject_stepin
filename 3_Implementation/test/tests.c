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

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_basicIpFunctions);
    return UNITY_END();
}