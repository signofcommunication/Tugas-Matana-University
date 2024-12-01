import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class FileHandler {

    public void saveToFile(List<Contact> contacts, String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename))) {
            for (Contact contact : contacts) {
                writer.write(contact.getId() + "," + contact.getName() + "," +
                        contact.getPhone() + "," + contact.getEmail());
                writer.newLine();
            }
            System.out.println("Contacts saved to file.");
        } catch (IOException e) {
            System.err.println("Failed to save contacts to file: " + e.getMessage());
        }
    }
}
