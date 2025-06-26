#pragma once


#include <string>
#include <chrono>

#ifdef WIN32
  #include <windows.h>
#endif

using namespace std;

void simd_add(const float* a, const float* b, float* result, size_t size);

float simd_sum(const float* a, const float* b, size_t size);

float simd_dot_product(const float* a, const float* b, size_t size);

float simd_dot_product_avx(const float* a, const float* b, size_t size);


 

