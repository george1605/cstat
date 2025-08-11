// Central Limit Theorem demonstration

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float data[200];
float* group_means;

void fill_data(char* filename)
{
    FILE* f = fopen(filename, "r");
    fread(data, sizeof(float), 200, f);
    fclose(f);
}

unsigned long long key = 0xC0FF13377357;

void generate_groups(size_t group_size)
{
    size_t size = ceil(200 / group_size);
    group_means = (float*)malloc(sizeof(float) * size);
    float sum = 0.0;
    key = key | time(NULL);
    for(int i = 0;i < size;i++)
    {
        sum = 0.0;
        for(int j = 0;j < group_size;j++)
        {
            sum += data[rand() % 200];
            key |= (j << 3);
            srand(key++);
        }
        sum /= group_size;
        group_means[i] = sum;
    }
}

double stddev(size_t sz, float* v)
{
    size_t i;
    double m = 0.0, s = 0.0;

    for(i = 0;i < sz;i++)
    {
        m += v[i];
    }
    m /= sz;
    for(i = 0;i < sz;i++)
    {
        s += (v[i] - m) * (v[i] - m);
    }
    return sqrt(s / (sz - 1));
}

int main()
{
    fill_data("data.bin");
    double f1 = stddev(200, data);
    printf("First stddev: %lf\n", f1);
    generate_groups(20);
    double f2 = stddev(10, group_means);
    printf("Second stddev: %lf\n", f2);
    printf("Sqrt of 20: %lf\n", sqrt(20));
    printf("Raport: %lf\n", f1 / f2);
    free(group_means);
}