public class Contact {
    private int id;
    private String name;
    private String phone;
    private String email;

    public Contact(int id, String name, String phone, String email) {
        this.id = id;
        this.name = name;
        this.phone = phone;
        this.email = email;
    }

    // Getter untuk semua properti
    public int getId() { return id; }
    public String getName() { return name; }
    public String getPhone() { return phone; }
    public String getEmail() { return email; }

    // Method untuk menampilkan data sebagai String
    @Override
    public String toString() {
        return "ID: " + id + ", Name: " + name + ", Phone: " + phone + ", Email: " + email;
    }
}
