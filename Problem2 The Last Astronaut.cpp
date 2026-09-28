#include <iostream>

int main() {
    int N, K;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;

    bool aktif[1000];
    for (int i = 1; i <= N; i++) {
        aktif[i] = true;
    }

    int tersisa = N;
    int posisiSaatIni = 1;

    std::cout << "\nUrutan astronot yang dieliminasi:\n";

    while (tersisa > 1) {
        int hitungan = 0;
        while (hitungan < K) {
            if (aktif[posisiSaatIni]) {
                hitungan++;
                if (hitungan == K) {
                    break;
                }
            }
            posisiSaatIni++;
            if (posisiSaatIni > N) {
                posisiSaatIni = 1;
            }
        }

        aktif[posisiSaatIni] = false;
        std::cout << "Astronot nomor " << posisiSaatIni << " dieliminasi.\n";
        tersisa--;

        if (posisiSaatIni % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        if (tersisa > 1) {
            do {
                posisiSaatIni++;
                if (posisiSaatIni > N) {
                    posisiSaatIni = 1;
                }
            } while (!aktif[posisiSaatIni]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (aktif[i]) {
            std::cout << "\nAstronot terakhir yang bertahan adalah nomor: " << i << std::endl;
            break;
        }
    }

    return 0;
}