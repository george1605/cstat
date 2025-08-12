// Chebyshev inequality

#include <math.h>
#include <stdio.h>
#include <stdint.h>

float prob_outside(float* x, size_t size, float mean, float k)
{
    size_t occ = 0;
    for(size_t i = 0;i < size;i++)
    {
        if(fabs(x[i] - mean) >= k)
            occ++;
    }
    return (float)occ / size;
}

int check_chebyshev(float* x, size_t size, float k, float sigma)
{
    float mean = 0.0;
    for(size_t i = 0;i < size;i++)
    {
        mean += x[i];
    }
    mean /= size;
    float p1 = prob_outside(x, size, mean, k);
    float p2 = ((sigma * sigma) / (k * k));
    printf("prob = %f, smaller than %lf\n", p1, p2);
    return p1 < p2;
}

int main()
{
    float x[] = { 105, 90, 80, 120, 112, 99 };
    (void)check_chebyshev(x, 6, 20, 13.31);
    return 0;
}