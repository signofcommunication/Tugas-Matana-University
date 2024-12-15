import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        FriendManager manager = new FriendManager();

        // Input data dinamis
        while (true) {
            System.out.print("Masukkan nama teman: ");
            String name = scanner.nextLine();

            System.out.print("Apakah teman ini close friend? (y/t): ");
            String isClose = scanner.nextLine();

            if (isClose.equalsIgnoreCase("y")) {
                System.out.print("Masukkan nomor telepon: ");
                String phoneNumber = scanner.nextLine();
                manager.addFriend(new CloseFriend(name, phoneNumber));
            } else {
                manager.addFriend(new Friend(name));
            }

            System.out.print("Tambah nama lagi? (y/t): ");
            String lagi = scanner.nextLine();
            if (!lagi.equalsIgnoreCase("y")) {
                break;
            }
        }

        // Tampilkan data
        manager.displayFriends();
        scanner.close();
    }
}
