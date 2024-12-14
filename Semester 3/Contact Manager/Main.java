import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ContactManager manager = new ContactManager();
        Scanner scanner = new Scanner(System.in);
        String id,name,email,phone;

        while (true) {
            System.out.println("\n=== Daftar Kontak ===");
            System.out.println("1. Tambahkan Kontak");
            System.out.println("2. Lihat Semua Kontak");
            System.out.println("3. Hapus Kontak");
            System.out.println("4. Update Kontak");
            System.out.println("5. Exit");
            System.out.print("Pilih Opsi: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Buat Next Line Ketika Input

            switch (choice) {
                case 1:
                    System.out.print("Nama: ");
                    name = scanner.nextLine();
                    System.out.print("Nomor Telp: ");
                    phone = scanner.nextLine();
                    System.out.print("Email: ");
                    email = scanner.nextLine();
                    try {
                        manager.addContact(name, phone, email).get(); // Tunggu hingga selesai
                    } catch (Exception e) {
                        System.err.println("Error: " + e.getMessage());
                    }
                    break;
                case 2:
                    manager.getAllContacts().forEach(System.out::println);
                    break;
                case 3:
                    System.out.print("ID Kontak yang Ingin Dihapus: ");
                    id = scanner.nextLine();
                    
                    if (manager.checkContactIsExist(id)) {
                        try {
                            manager.deleteContact(id).get(); // Tunggu hingga selesai
                        } catch (Exception e) {
                            System.err.println("Error: " + e.getMessage());
                        }
                    } else {
                        System.out.println("Kontak dengan ID " + id + " tidak ditemukan.");
                    }
                    break;
                case 4:
                    System.out.print("ID Kontak yang Ingin di update: ");
                    id = scanner.nextLine();

                    if (manager.checkContactIsExist(id)) {
                        try {
                            System.out.print("Nama: ");
                        name = scanner.nextLine();
                        
                        System.out.print("Nomor Telp: ");
                        phone = scanner.nextLine();
    
                        System.out.print("Email: ");
                        email = scanner.nextLine();
    
                        manager.updateContact(id, name, phone, email).get();
                    } catch (Exception e) {
                            System.err.println("Error: " + e.getMessage());
                        }
                    }   else {
                        System.out.println("Kontak dengan ID " + id + " tidak ditemukan.");
                    }
                    
                    break;
                case 5:
                    System.out.println("Keluar...");
                    manager.shutdown();
                    scanner.close();
                    return;
                default:
                    System.out.println("Tidak ada Opsi " + choice + ". Pilih Opsi Lain yang ada");
            }
        }
    }
}
