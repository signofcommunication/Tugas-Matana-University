import java.util.ArrayList;

public class FriendManager {
    private ArrayList<Friend> friends = new ArrayList<>();

    public void addFriend(Friend friend) {
        friends.add(friend);
    }

    public void displayFriends() {
        System.out.println("Daftar Teman:");
        for (Friend friend : friends) {
            friend.display();
        }
    }
}
