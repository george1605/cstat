// Shanon Entropy Calculator
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <memory.h>

uint8_t data[100];
uint32_t freq[256] = {0};

float entropy(uint8_t* data, size_t size)
{
    memset(freq, 0, 256 * sizeof(uint32_t));
    size_t total = size;
    float p, H = 0;
    for(size_t i = 0;i < size;i++)
    {
        freq[data[i]]++;
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

void entropy_window(uint8_t* data, size_t size, size_t win_size, size_t step)
{
    if (win_size > size) {
        printf("Window size larger than data size!\n");
        return;
    }

    for (size_t i = 0; i + win_size <= size; i += step) {
        float h = entropy(&data[i], win_size);
        printf("Window [%u - %u): %.6f\n", i, i + win_size, h);
    }
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
    entropy_window(data, 100, 10, 10);
}