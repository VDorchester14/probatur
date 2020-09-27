#ifndef TEST_CLASS_H
#define TEST_CLASS_H

#include <stdio.h>
#include <iostream>
#include <math.h>

class TestClass{
public:
    TestClass(){
        tests_performed = 0;
    }

    template <typename T>
    static void AssertEquals(T a, T b){
        if(a == b){
            printf(".");
        }else{
            std::cout<<"\nAssertEquals failed: "<<a<<" != "<<b<<"\n";
        }
        return;
    }

    template <typename T>
    static void AssertAlmostEquals(T a, T b, double eps = 1.0e-7){
        double diff = abs(a - b);
        if(diff > eps){
            std::cout<<"\nAssertAlmostEquals failed: "<<a<<" - "<<b<<" = "<<diff<<" > "<<eps<<"\n";
        }else{
            printf(".");
        }
    }

    template <typename T>
    static void AssertNotEquals(T a, T b){
        if(a == b){
            std::cout<<"\nAssertNotEquals failed: "<<a<<" == "<<b<<"\n";
        }else{
            printf(".");
        }
    }
private:
    int tests_performed;
};

#endif
