// Common distributions
#include <math.h>
#include <stdio.h>
#ifndef PI
#define PI 3.1415926f
#endif
#define SQRT_2PI 2.50662827463f

float bell_curve(float x, float sigma, float miu)
{
    return 1.0f / (sigma * sqrt(2 * PI)) * expf(-0.5 * ((x - miu) / sigma) * ((x - miu) / sigma));
}

float bell_curve_fast(float x, float sigma, float miu)
{
    float diff = x - miu;
    float exponent = -(diff * diff) / (2.0f * sigma * sigma);
    return (1.0f / (sigma * SQRT_2PI)) * expf(exponent);
}

float uniform_dist(float x, float a, float b)
{
    if(x < a || x > b) return 0;
    return 1.0 / (b - a);
}

float exp_dist(float x, float l)
{
    if(x < 0) return 0;
    return l * expf(-l * x);
}