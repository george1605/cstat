// Shanon Entropy Calculator
#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint8_t data[100];
uint32_t freq[256] = {0};

float entropy(uint8_t* data, size_t size)
{
    size_t total = 0;
    float p, H = 0;
    for(size_t i = 0;i < size;i++)
    {
        freq[data[i]]++;
        total++;
    }

    for(size_t i = 0;i < 256;i++)
    {
        p = (float)freq[i] / total;
        if(p == 0) continue;
        H += p * log2(p);
    }
    H = -H;
    return H;
}

void fill_data(char* filename)
{
    FILE* f = fopen(filename, "r");
    fread(data, sizeof(float), 100, f);
    fclose(f);
}

int main()
{
    fill_data("data.bin");
    printf("Entropy: %lf", entropy(data, 100));
}