#include <math.h>
#include <stdio.h>
#include <time.h>
#include <xmmintrin.h>
#include <immintrin.h>

float FastInverseSquareRoot(float number) {
    long int i;
    float x2, y;
    static const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *) &y;          // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1); // what the fuck?
    y = *(float *) &i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
    // y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, this can be removed
    return y;
}

double FastInverseSquareRootDouble(double number) {
    long long int i;
    double x2, y;
    static const double threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long long int *) &y;         // evil floating point bit level hacking
    i = 0x5fe6eb50c7b537a9 - (i >> 1); // what the fuck?
    y = *(double *) &i;
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
    // y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, this can be removed
    return y;
}

void fisr(float *a, unsigned int N) {
    clock_t before = clock();

    for (unsigned int i = 0; i < N; ++i)
        a[i] = FastInverseSquareRoot(a[i]);

    clock_t difference = clock() - before;
    printf("FastInverseSquareRoot : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

void fisrDouble(double *a, unsigned int N) {
    clock_t before = clock();

    for (unsigned int i = 0; i < N; ++i)
        a[i] = FastInverseSquareRootDouble(a[i]);

    clock_t difference = clock() - before;
    printf("FastInverseSquareRoot : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

void normal(float *a, unsigned int N) {
    clock_t before = clock();

    for (unsigned int i = 0; i < N; ++i)
        a[i] = 1.f / sqrtf(a[i]);

    clock_t difference = clock() - before;
    printf("Normal : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

void normalDouble(double *a, unsigned int N) {
    clock_t before = clock();

    for (unsigned int i = 0; i < N; ++i)
        a[i] = 1.0 / sqrt(a[i]);

    clock_t difference = clock() - before;
    printf("Normal : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

void sse(float *a, unsigned int N) {
    clock_t before = clock();

    __m128 div = {1.f, 1.f, 1.f, 1.f};

    for (unsigned int i = 0; i < N / 4; i+=4) {
        __m128 todiv = {a[i], a[i + 1], a[i + 2], a[i + 3]};
        __m128 au = _mm_sqrt_ps(todiv);
        au = _mm_div_ps(div, au);

        a[i] = au[0];
        a[i + 1] = au[1];
        a[i + 2] = au[2];
        a[i + 3] = au[3];
    }

//    for (unsigned int i = 0; i < nb_iters; ++i, ++ptr, a += 4)
//        _mm_store_ps(a, _mm_div_ps(div, _mm_sqrt_ps(*ptr)));

//         _mm_store_ps(a, _mm_invsqrt_ps(*ptr));

    clock_t difference = clock() - before;
    printf("SSE : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

void sseDouble(double *a, unsigned int N) {
    clock_t before = clock();

    __m256d div = {1.f, 1.f, 1.f, 1.f};

    for (unsigned int i = 0; i < N / 4; i+=4) {
        __m256d todiv = {a[i], a[i + 1], a[i + 2], a[i + 3]};
        __m256d au = _mm256_sqrt_pd(todiv);
        au = _mm256_div_pd(div, au);

        a[i] = au[0];
        a[i + 1] = au[1];
        a[i + 2] = au[2];
        a[i + 3] = au[3];
    }

    clock_t difference = clock() - before;
    printf("SSE : %f\n", difference * 1000.f /(float) CLOCKS_PER_SEC);
}

int main() {
    static const unsigned int N = 160000000;

    printf("\n\nFloat : allocating %lu Mb\n\n", sizeof(float) * N / 1000000);

    {
        float *a = malloc(sizeof(float) * N);

        for (unsigned int i = 0; i < N; ++i)
            a[i] = 3141592.65358f;
        normal(a, N);

        for (unsigned int i = 0; i < N; ++i) {
            // printf("%f\n", a[i]);
            a[i] = 3141592.65358f;
        }
        sse(a, N);

        for (unsigned int i = 0; i < N; ++i) {
            // printf("%f\n", a[i]);
            a[i] = 3141592.65358f;
        }
        fisr(a, N);

        // for (int i = 0; i < N; ++i)
        // printf("%f\n", a[i]);

        free(a);
    }

    printf("\nDouble : allocating %lu Mb\n\n", sizeof(double) * N / 1000000);
    {
        double *a = malloc(sizeof(double) * N);

        for (unsigned int i = 0; i < N; ++i)
            a[i] = 3141592.65358;
        normalDouble(a, N);

        for (unsigned int i = 0; i < N; ++i)
            a[i] = 3141592.65358;
        sseDouble(a, N);

        for (unsigned int i = 0; i < N; ++i)
            a[i] = 3141592.65358;
        fisrDouble(a, N);

        free(a);
    }

    return 0;
}