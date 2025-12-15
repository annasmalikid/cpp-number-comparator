#include <iostream>
#include <limits>
#include <string>

namespace app {

// Membaca integer dengan validasi (handle input non-angka)
int readInt(const std::string& prompt) {
    int value = 0;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            return value; // input valid
        }

        // Jika input tidak valid (mis. huruf), bersihkan state dan buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input tidak valid. Masukkan angka bulat (contoh: 10, -3).\n";
    }
}

// Mengembalikan hasil perbandingan secara rapi
std::string compareTwoNumbers(int a, int b) {
    if (a > b) {
        return "Bilangan terbesar: " + std::to_string(a);
    }
    if (b > a) {
        return "Bilangan terbesar: " + std::to_string(b);
    }
    return "Kedua bilangan sama besar.";
}

} // namespace app

int main() {
    std::cout << "=== Number Comparator (C++ Console App) ===\n";

    const int firstNumber  = app::readInt("Masukkan bilangan pertama : ");
    const int secondNumber = app::readInt("Masukkan bilangan kedua   : ");

    std::cout << "\nHasil:\n" << app::compareTwoNumbers(firstNumber, secondNumber) << "\n";

    return 0;
}
