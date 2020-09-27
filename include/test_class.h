#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <stdio.h>
#include <iostream>
#include <math.h>

class TestClass{
public:
    TestClass(){
        tests_passed = 0;
    }

    static void Results(){
        std::cout<<"Tests Passed: "<<tests_passed<<std::endl;
    }

    template <typename T>
    static void AssertEquals(T a, T b){
        if(a == b){
            printf(".");
        }else{
            std::cout<<"\nAssertEquals failed: "<<a<<" != "<<b<<"\n";
            return;
        }
    }

    template <typename T>
    static void AssertAlmostEquals(T a, T b, double eps = 1.0e-7){
        double diff = abs(a - b);
        if(diff > eps){
            std::cout<<"\nAssertAlmostEquals failed: "<<a<<" - "<<b<<" = "<<diff<<" > "<<eps<<"\n";
            return;
        }else{
            printf(".");
        }
    }

    template <typename T>
    static void AssertNotEquals(T a, T b){
        if(a == b){
            std::cout<<"\nAssertNotEquals failed: "<<a<<" == "<<b<<"\n";
            return;
        }else{
            printf(".");
        }
    }
private:
    static int tests_passed;
};

#endif
