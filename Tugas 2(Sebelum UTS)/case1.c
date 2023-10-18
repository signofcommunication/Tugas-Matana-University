#include <stdio.h>

int main() {
    int d, s, t;
    
    // Membaca anggaran belanja untuk daging, sayur, dan telur
    scanf("%d %d %d", &d, &s, &t);

    int anggaran_tertinggi, anggaran_terendah, anggaran_tengah;

    // Menentukan anggaran tertinggi, tengah, dan terendah
    if (d >= s && d >= t) {
        anggaran_tertinggi = d;
        anggaran_tengah = (s >= t) ? s : t;
        anggaran_terendah = (s <= t) ? s : t;
    } else if (s >= d && s >= t) {
        anggaran_tertinggi = s;
        anggaran_tengah = (d >= t) ? d : t;
        anggaran_terendah = (d <= t) ? d : t;
    } else {
        anggaran_tertinggi = t;
        anggaran_tengah = (d >= s) ? d : s;
        anggaran_terendah = (d <= s) ? d : s;
    }

    // Menampilkan urutan belanja
    printf("%s\n", (d == anggaran_tertinggi) ? "Daging" : (s == anggaran_tertinggi) ? "Sayur" : "Telur");
    printf("%s\n", (d == anggaran_tengah) ? "Daging" : (s == anggaran_tengah) ? "Sayur" : "Telur");
    printf("%s\n", (d == anggaran_terendah) ? "Daging" : (s == anggaran_terendah) ? "Sayur" : "Telur");

    return 0;
}

