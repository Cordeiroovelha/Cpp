#include <iostream>
#include <cuda_runtime.h>

__global__ void ola() {
    printf("Bloco %d, thread %d\n", blockIdx.x, threadIdx.x);
}

int main() {
    ola <<< 2,4 >>>();
    cudaDeviceSynchronize();
    return 0;
}

/*
    cudaDeviceSynchronize = espera o fim do processo para começar o proximo
    
*/ 