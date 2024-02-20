#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <chrono>

volatile int sink;
int main()
{
    std::cout << std::fixed << std::setprecision(9) << std::left;
    for (auto size = 1ull; size < 1000'000'000ull; size *= 100) {
        // registrar tiempo de inicio
        auto start = std::chrono::steady_clock::now();
        // hacer algo de trabajo
        std::vector<int> v(size, 42);
        sink = std::accumulate(v.begin(), v.end(), 0u); // asegrarse que sea un efecto secundario
        // registrar tiempo del fin
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Tiempo de llenar e iterar sobre un vector de " << std::setw(9)
            << size << " enteros : " << diff.count() << " s\n";
    }
}