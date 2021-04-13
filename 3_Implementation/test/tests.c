#include "unity.h"

void setUp(void){}
void tearDown(void){}

void test_test(void){
    TEST_ASSERT_EQUAL_INT(1,1);
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_test);
    return UNITY_END();
}