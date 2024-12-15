import java.util.concurrent.Future;
import java.util.List;

public class ContactManager extends BaseManager{
    // private final ExecutorService executor = Executors.newFixedThreadPool(2);
    DatabaseHandler dbHandler;
    FileHandler fileHandler;
    String filePath = "daftar-kontak.txt";

    public ContactManager() {
        dbHandler = new DatabaseHandler();
        fileHandler = new FileHandler();
    }

    // Tambah kontak ke database
    public Future<?> addContact(String name, String phone, String email) {
        logAction("Menambakan Kontak");
        return submitTask(() -> {
            dbHandler.addContact(new Contact(0, name, phone, email),filePath);
        });
    }

    // Lihat semua kontak
    public List<Contact> getAllContacts() {
        logAction("Melihat Semua Kontak");
        return dbHandler.getAllContacts();
    }

    // Simpan kontak ke file
    public void saveContactsToFile(String filename) {
        List<Contact> contacts = dbHandler.getAllContacts();
        fileHandler.saveToFile(contacts, filename);
    }

    public Future<?> deleteContact(String id) {
        logAction("Menghapus kontak dengan ID: " + id);
        return submitTask(() -> {
            dbHandler.deleteContact(id,filePath);
        });
    }


    public Future<?> updateContact(String id, String name, String phone, String email) {
        logAction("Mengupdate Kontak dengan ID: "  + id);
        return submitTask(() -> {
            dbHandler.updateContact(id, name, phone, email,filePath);
        });
    }

    public boolean checkContactIsExist(String id) {
        return dbHandler.isContactExist(id);
    }

    @Override
    public void logAction(String action) {
        System.out.println("[INFO] " + action);
    }
}
