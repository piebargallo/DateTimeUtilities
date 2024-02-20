#include <iostream>
#include <format>
#include <chrono>

// Función recursiva para calcular el factorial
unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    // Llamar a la función recursiva
    unsigned int n = 4;
    unsigned long long result = factorial(n);

    // Detener el cronómetro
    auto end = std::chrono::high_resolution_clock::now();

    // Calcular el tiempo transcurrido en microsegundos
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << std::format("Factorial de {} es {} ", n, result) << std::endl;
    std::cout << std::format("Tiempo de ejecucion {} microsegundos", duration) << std::endl;

    return 0;
}
