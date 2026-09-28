#include <iostream>

int main() {
    char pesan[100];
    std::cout << "Masukkan pesan teks (HURUF KAPITAL): ";
    std::cin >> pesan;

    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    char sandi[100];
    sandi[panjang] = '\0';

    for (int i = 0; i < panjang; i++) {
        if (i == 0) {
            sandi[i] = pesan[i];
        } else {
            int geser = pesan[i - 1] - 'A' + 1;
            int posisiAwal = pesan[i] - 'A';
            int posisiBaru = (posisiAwal + geser) % 26;

            sandi[i] = 'A' + posisiBaru;
        }
    }

    std::cout << "Pesan sandi: " << sandi << std::endl;

    return 0;
}