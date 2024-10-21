import java.util.InputMismatchException;
import java.util.Scanner;

public class KalkulatorDenganErrorHandling {

    public static int pilihOperasi(Scanner scanner) throws IllegalArgumentException, InputMismatchException {
        System.out.println("\nPilih operasi:");
        System.out.println("1. Perkalian");
        System.out.println("2. Pembagian");
        System.out.print("Pilihan Anda: ");
        int pilihan = scanner.nextInt();

        if (pilihan < 1 || pilihan > 2) {
            throw new IllegalArgumentException("Pilihan tidak valid. Pilih 1 atau 2.");
        }

        return pilihan;
    }

    public static int inputAngka(Scanner scanner, String pesan) throws InputMismatchException {
        System.out.print(pesan);
        return scanner.nextInt();
    }

    public static int hitungPerkalian(int angka1, int angka2) {
        return angka1 * angka2;
    }

    public static int hitungPembagian(int angka1, int angka2) throws ArithmeticException {
        if (angka2 == 0) {
            throw new ArithmeticException("Pembagian dengan nol tidak diperbolehkan.");
        }
        return angka1 / angka2;
    }

    public static void tampilkanHasil(int hasil, String operasi) {
        System.out.println("Hasil " + operasi + ": " + hasil);
    }

    public static boolean tanyaLanjut(Scanner scanner) {
        System.out.print("Ingin mengulang? (1: Ya, 2: Tidak): ");
        int pilihanLanjut = scanner.nextInt();
        return pilihanLanjut == 1; // True jika pengguna memilih untuk melanjutkan
    }

    public static void jalankanKalkulator() {
        Scanner scanner = new Scanner(System.in);
        boolean lanjut = true;

        while (lanjut) {
            try {
                int pilihan = pilihOperasi(scanner);
                int angka1 = inputAngka(scanner, "Masukkan angka pertama: ");
                int angka2 = inputAngka(scanner, "Masukkan angka kedua: ");
                int hasil;

                if (pilihan == 1) {
                    hasil = hitungPerkalian(angka1, angka2);
                    tampilkanHasil(hasil, "perkalian");
                } else if (pilihan == 2) {
                    hasil = hitungPembagian(angka1, angka2);
                    tampilkanHasil(hasil, "pembagian");
                }

                lanjut = tanyaLanjut(scanner);

            } catch (IllegalArgumentException | InputMismatchException e) {
                System.out.println("Error: " + e.getMessage());
                scanner.nextLine(); // Membersihkan buffer input
            }
        }
        scanner.close(); // Tutup scanner setelah selesai
    }
}
