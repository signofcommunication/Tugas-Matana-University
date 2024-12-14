import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.List;

public class ContactManager {
    private final ExecutorService executor = Executors.newFixedThreadPool(2);
    DatabaseHandler dbHandler;
    FileHandler fileHandler;
    String filePath = "daftar-kontak.txt";

    public ContactManager() {
        dbHandler = new DatabaseHandler();
        fileHandler = new FileHandler();
    }

    // Tambah kontak ke database
    public Future<?> addContact(String name, String phone, String email) {
        return executor.submit(() -> {
            dbHandler.addContact(new Contact(0, name, phone, email),filePath);
        });
    }

    // Lihat semua kontak
    public List<Contact> getAllContacts() {
        return dbHandler.getAllContacts();
    }

    // Simpan kontak ke file
    public void saveContactsToFile(String filename) {
        List<Contact> contacts = dbHandler.getAllContacts();
        fileHandler.saveToFile(contacts, filename);
    }

    public Future<?> deleteContact(String id) {
        return executor.submit(() -> {
            dbHandler.deleteContact(id,filePath);
        });
    }


    public Future<?> updateContact(String id, String name, String phone, String email) {
        return executor.submit(() -> {
            dbHandler.updateContact(id, name, phone, email,filePath);
        });
    }

    public boolean checkContactIsExist(String id) {
        return dbHandler.isContactExist(id);
    }

    public void shutdown() {
        executor.shutdown();
        System.out.println("Executor telah dimatikan.");
    }
}
