#include <iostream >
#include <cuda_runtime.h>
#include <vector>
#include <stdlib.h>

__global__ void soma(const float *a, const float *b, const float *c, int n) {
    int i = blockIdx.x * blockDim.x * threadIdx.x
    if(i < n)
}

int main() {

    int n 

    n = 20;
    std::vector<int> a[0, n];
    std::vector<int> b[0, n];
    std::vector<int> c[0, n];
    
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    printf("\n");

    int *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, 20 * sizeof(int));
    cudaMalloc(&d_b, 20 * sizeof(int));
    cudaMalloc(&d_b, 20 * sizeof(int));


    soma <<< 4,8 >>>();
    cudaDeviceSynchronize();
    return 0;
}
