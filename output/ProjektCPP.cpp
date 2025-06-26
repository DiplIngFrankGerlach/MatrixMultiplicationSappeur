#include <iostream>
#include <vector>
#include <xmmintrin.h> // SSE



void simd_add(const float* a, const float* b, float* result, size_t size) {
    size_t i = 0;

    // Process 4 floats at a time using SSE
    for (; i + 4 <= size; i += 4) {
        __m128 va = _mm_loadu_ps(a + i);    // load 4 floats from a
        __m128 vb = _mm_loadu_ps(b + i);    // load 4 floats from b
        __m128 vsum = _mm_add_ps(va, vb);   // SIMD addition
        _mm_storeu_ps(result + i, vsum);    // store the result
    }

    // Process any remaining elements
    for (; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
}


    float simd_sum(const float* a, const float* b, size_t size) 
    {
        size_t i = 0;
        __m128 total = _mm_setzero_ps();  // Initialize SIMD register to 0

        // SIMD addition and accumulation
        for (; i + 4 <= size; i += 4) {
            __m128 va = _mm_loadu_ps(a + i);   // Load 4 floats from a
            __m128 vb = _mm_loadu_ps(b + i);   // Load 4 floats from b
            __m128 vsum = _mm_add_ps(va, vb);  // Element-wise sum
            total = _mm_add_ps(total, vsum);   // Accumulate
        }

        // Horizontal add the 4 floats in the SIMD register
        float temp[4];
        _mm_storeu_ps(temp, total);
        float sum = temp[0] + temp[1] + temp[2] + temp[3];

        // Handle remaining elements
        for (; i < size; ++i) {
            sum += a[i] + b[i];
        }

        return sum;
    }

 

    float simd_dot_product(const float* a, const float* b, size_t size) {
        size_t i = 0;
        __m128 acc = _mm_setzero_ps(); // Initialize accumulator to zero

        // Process 4 floats at a time
        for (; i + 4 <= size; i += 4) {
            __m128 va = _mm_loadu_ps(a + i);   // Load 4 elements from a
            __m128 vb = _mm_loadu_ps(b + i);   // Load 4 elements from b
            __m128 prod = _mm_mul_ps(va, vb);  // Multiply element-wise
            acc = _mm_add_ps(acc, prod);       // Accumulate product
        }

        // Horizontal sum of 4 elements in acc
        float temp[4];
        _mm_storeu_ps(temp, acc);
        float sum = temp[0] + temp[1] + temp[2] + temp[3];

        // Handle remaining elements
        for (; i < size; ++i) {
            sum += a[i] * b[i];
        }

        return sum;
    }



