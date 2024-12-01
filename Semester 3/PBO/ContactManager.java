import java.util.List;

public class ContactManager {
    private DatabaseHandler dbHandler;
    private FileHandler fileHandler;

    public ContactManager() {
        dbHandler = new DatabaseHandler();
        fileHandler = new FileHandler();
    }

    // Tambah kontak ke database
    public void addContact(String name, String phone, String email) {
        dbHandler.addContact(new Contact(0, name, phone, email));
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
}
