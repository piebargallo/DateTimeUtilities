#include <iostream>
#include <format>

// Función iterativa para calcular el factorial
unsigned long long factorial_iterative(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    // Llamar a la función iterativa
    unsigned int n = 4;
    unsigned long long result = factorial_iterative(n);

    // Detener el cronómetro
    auto end = std::chrono::high_resolution_clock::now();

    // Calcular el tiempo transcurrido en microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << std::format("Factorial de {} es {} ", n, result) << std::endl;
    std::cout << std::format("Tiempo de ejecucion {} microsegundos", duration) << std::endl;

    return 0;
}
