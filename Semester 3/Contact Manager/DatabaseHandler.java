import java.io.BufferedWriter;
import java.io.FileWriter;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.io.IOException;

public class DatabaseHandler {
    public DatabaseHandler() {
        // Class.forName("com.mysql.cj.jdbc.Driver");
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb?useSSL=false", "root",
                "")) {
            System.out.println("Terknoneksi ke Database");
        } catch (SQLException e) {
            System.err.println("Gagal menghubungkan ke Database: " + e.getMessage());
        }
    }

   public void syncFileWithDatabase(String filePath) {
    String query = "SELECT * FROM contacts";
    try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
         PreparedStatement stmt = conn.prepareStatement(query);
         ResultSet rs = stmt.executeQuery();
         BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
        
        // Tulis header ke file
        writer.write("id,name,phone,email");
        writer.newLine();

        // Tulis setiap baris data dari database ke file
        while (rs.next()) {
            String line = rs.getInt("id") + "," + 
                          rs.getString("name") + "," + 
                          rs.getString("phone") + "," + 
                          rs.getString("email");
            writer.write(line);
            writer.newLine();
        }
        System.out.println("File telah disinkronkan dengan database.");
    } catch (SQLException e) {
        System.err.println("Gagal menyinkronkan file karena masalah database: " + e.getMessage());
    } catch (IOException e) {
        System.err.println("Gagal menyinkronkan file karena masalah IO: " + e.getMessage());
    }
}

    public boolean isContactExist(String id) {
    String query = "SELECT COUNT(*) FROM contacts WHERE id=?";
    try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
         PreparedStatement stmt = conn.prepareStatement(query)) {
        
        // Menyiapkan parameter untuk query
        stmt.setString(1, id);
        
        // Menjalankan query dan memeriksa hasil
        try (ResultSet rs = stmt.executeQuery()) {
            if (rs.next()) {
                return rs.getInt(1) > 0; // Jika jumlahnya > 0, berarti ID ditemukan
            }
        }
    } catch (SQLException e) {
        System.err.println("Gagal Memeriksa Kontak: " + e.getMessage());
    }
    return false; // Jika ada error atau ID tidak ditemukan
}


    // Function buat Menambahkan Kontak ke database
    public void addContact(Contact contact, String filePath) {
        String query = "INSERT INTO contacts (name, phone, email) VALUES (?, ?, ?)";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, contact.getName());
            stmt.setString(2, contact.getPhone());
            stmt.setString(3, contact.getEmail());
            stmt.executeUpdate();
            System.out.println("Kontak Telah Ditambahkan ke Database.");

            syncFileWithDatabase(filePath);
        } catch (SQLException e) {
            System.err.println("Gagal Menambahkan Kontak: " + e.getMessage());
        }
    }


    public void deleteContact(String id,String filePath) {
        String query = "DELETE FROM contacts WHERE id =?";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
             PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, id);
            stmt.executeUpdate();
            System.out.println("Kontak dengan ID " + id + " telah Dihapus.");
            syncFileWithDatabase(filePath);
        } catch (SQLException e) {
            System.err.println("Gagal Menghapus Kontak: " + e.getMessage());
        }
    }

    // Function buat mendapatkan semua kontak yang ada
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
            System.err.println("Gagal Mendapatkan Kontak Dari Database: " + e.getMessage());
        }
        return contacts;
    }
    
    public void updateContact(String id, String name, String phone, String email,String filePath) {
        String query = "UPDATE contacts SET name=?, phone=?, email=? WHERE id=?";
        try (Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/contactdb", "root", "");
                PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, name);
            stmt.setString(2, phone);
            stmt.setString(3, email);
            stmt.setString(4, id);
            
            int rowAffected = stmt.executeUpdate();
            if (rowAffected > 0) {
                System.out.println("Kontak dengan ID " + id + " telah Diperbarui.");
                syncFileWithDatabase(filePath);
            } else {
                System.out.println("Kontak dengan ID " + id + " tidak ditemukan.");
            }

        } catch (SQLException e) {
            System.err.println("Gagal Memperbarui Kontak: " + e.getMessage());
        }
    }
}
