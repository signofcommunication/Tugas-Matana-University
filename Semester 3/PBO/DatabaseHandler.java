import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class DatabaseHandler {
    
    public DatabaseHandler() {
        // Class.forName("com.mysql.cj.jdbc.Driver");
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb?useSSL=false", "root", "")) {
            System.out.println("Connected to the database.");
        } catch (SQLException e) {
            System.err.println("Database connection failed: " + e.getMessage());
        }
    }

    public void addContact(Contact contact) {
        String query = "INSERT INTO contacts (name, phone, email) VALUES (?, ?, ?)";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
             PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, contact.getName());
            stmt.setString(2, contact.getPhone());
            stmt.setString(3, contact.getEmail());
            stmt.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Failed to add contact: " + e.getMessage());
        }
    }

    public List<Contact> getAllContacts() {
        List<Contact> contacts = new ArrayList<>();
        String query = "SELECT * FROM contacts";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                contacts.add(new Contact(rs.getInt("id"), rs.getString("name"),
                        rs.getString("phone"), rs.getString("email")));
            }
        } catch (SQLException e) {
            System.err.println("Failed to fetch contacts: " + e.getMessage());
        }
        return contacts;
    }
}
