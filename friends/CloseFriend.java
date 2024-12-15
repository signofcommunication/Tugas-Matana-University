class CloseFriend extends Friend {
    private String phoneNumber;

    public CloseFriend(String name, String phoneNumber) {
        super(name);
        this.phoneNumber = phoneNumber;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("No. Telepon: " + phoneNumber);
    }
}
