#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Item {
public:
    string name;
    int magic_number;
    Item(string n, int mn) : name(n), magic_number(mn) {}
};

class Player {
public:
    string name;
    int health;
    int attack;
    int defense;
    vector<Item> inventory;

    Player(string n) : name(n), health(100), attack(10), defense(5) {}

    void take_damage(int dmg) {
        int damage_taken = max(dmg - defense, 0);
        health = max(health - damage_taken, 0);
        cout << name << " took " << damage_taken << " damage! Health: " << health << endl;
    }

    void attack_enemy(int &enemy_health) {
        cout << name << " attacked the enemy! ";
        enemy_health = max(enemy_health - attack, 0);
        cout << "Enemy health: " << enemy_health << endl;
    }
};

class Enemy {
public:
    string type;
    int health;
    int attack;
    int defense;

    Enemy(string t, int hp, int atk, int def) : type(t), health(hp), attack(atk), defense(def) {}

    void take_damage(int dmg) {
        int damage_taken = max(dmg - defense, 0);
        health = max(health - damage_taken, 0);
        cout << type << " took " << damage_taken << " damage! Health: " << health << endl;
    }

    void attack_player(Player &player) {
        int damage_dealt = max(attack - player.defense, 0);
        player.take_damage(damage_dealt);
        cout << type << " attacked " << player.name << " for " << damage_dealt << " damage!" << endl;
    }
};


// Κλάση Section που αναπαριστά κάθε τμήμα ενός δωματίου
class Section {
public:
    string description;
    vector<string> enemies;
    vector<string> items;

    // Προεπιλεγμένος κατασκευαστής
    Section() : description("Empty section") {}


    Section(string desc) : description(desc) {}

    void display() {
        cout << description << endl;
        if (!enemies.empty()) {
            cout << "Enemies: ";
            for (const auto& enemy : enemies) {
                cout << enemy << " ";
            }
            cout << endl;
        }
        if (!items.empty()) {
            cout << "Items: ";
            for (const auto& item : items) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

// Κλάση Room που περιέχει Sections και εξόδους
class Room {
public:
    string name;
    string description;
    unordered_map<string, Room*> exits; // Συνδέσεις με άλλα δωμάτια
    unordered_map<string, Section> sections; // Τμήματα μέσα στο δωμάτιο

    Room(string n, string desc) : name(n), description(desc) {}

    // Προσθήκη section στο δωμάτιο
    void add_section(const string& section_name, const Section& section) {
        sections[section_name] = section;
    }

    // Προσθήκη εξόδου προς άλλο δωμάτιο
    void addExit(const string& direction, Room* room) {
        exits[direction] = room;
    }

    // Εξερεύνηση κατεύθυνσης για άλλα δωμάτια
    Room* explore(const string& direction) {
        if (exits.find(direction) != exits.end()) {
            return exits[direction];
        } else {
            cout << "There is no exit in that direction!" << endl;
            return nullptr;
        }
    }

    // Εξερεύνηση section μέσα στο δωμάτιο
    void explore_section(const string& section_name) {
        if (sections.find(section_name) != sections.end()) {
            sections[section_name].display();
        } else {
            cout << "No such section found!" << endl;
        }
    }

    // Εμφάνιση πληροφοριών για το δωμάτιο
    void display() const {
        cout << "You are in: " << name << endl;
        cout << description << endl;
        cout << "Exits: ";
        for (const auto& exit : exits) {
            cout << exit.first << " ";
        }
        cout << endl;
    }
};

void print_with_delay(const string &message, int delayMicroseconds) {
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::microseconds(delayMicroseconds));
    }
    cout << endl;
}

int main() {
    string message = "Welcome to my game!";
    int sleep = 50000; // 0.05 seconds

    print_with_delay(message, sleep);

     // Δημιουργία δωματίων
    Room* entrance = new Room("Entrance", "A dark and damp entrance with cobwebs.");
    Room* cave = new Room("Cave", "A large cave with stalactites.");

    // Δημιουργία sections μέσα στο δωμάτιο
    Section secretRoom("A hidden room with a treasure chest.");
    secretRoom.items.push_back("Gold Coin");
    entrance->add_section("secret", secretRoom);

    Section crystalRoom("A room filled with glowing crystals.");
    crystalRoom.enemies.push_back("Goblin");
    cave->add_section("crystal", crystalRoom);

    // Προσθήκη εξόδων μεταξύ δωματίων
    entrance->addExit("north", cave);
    cave->addExit("south", entrance);

    // Εξερεύνηση δωματίων και sections
    Room* currentRoom = entrance;
    string direction;
    string section;

    while (true) {
        currentRoom->display();
        cout << "Which direction would you like to go? (or type 'explore' to explore a section): ";
        cin >> direction;

        if (direction == "explore") {
            cout << "Enter the section name to explore: ";
            cin >> section;
            currentRoom->explore_section(section);
        } else {
            Room* nextRoom = currentRoom->explore(direction);
            if (nextRoom != nullptr) {
                currentRoom = nextRoom;
            }
        }
    }

    // Απελευθέρωση μνήμης
    delete entrance;
    delete cave;

    return 0;
}
