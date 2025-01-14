#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

class Item {
public:
    string name;
    int magic_number;
    string type;

    Item(string n, int mn, string t) : name(n), magic_number(mn), type(t) {}
};

class Player {
public:
    string name;
    int health;
    int base_attack;
    int attack;
    int defense;
    bool has_shield;
    vector<Item> inventory;
    Item* equipped_weapon;

    Player(string n) : name(n), health(100), base_attack(10), attack(10), defense(10), has_shield(false), equipped_weapon(nullptr) {}

    void take_damage(int dmg) {
        int damage_taken = max(dmg - defense, 1); // Ελάχιστο damage 1
        health = max(health - damage_taken, 0);
        cout << name << " took " << damage_taken << " damage! Health: " << health << endl;
    }

    void attack_enemy(int &enemy_health, int enemy_defense) {
        int damage_dealt = max(attack - enemy_defense, 1); // Ελάχιστο damage 1
        enemy_health = max(enemy_health - damage_dealt, 0);
        cout << name << " attacked the enemy for " << damage_dealt << " damage! Enemy health: " << enemy_health << endl;
    }

    void equip_item() {
        if (inventory.empty()) {
            cout << "No items in inventory!" << endl;
            return;
        }

        cout << "Choose a weapon to equip:\n";
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].type == "weapon") {
                cout << i + 1 << ". " << inventory[i].name << " (+" << inventory[i].magic_number << " attack)" << endl;
            }
        }
        cout << "0. Go Back" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            return; // Επιστροφή χωρίς αλλαγή όπλου
        }
        if (choice < 1 || choice > inventory.size() || inventory[choice - 1].type != "weapon") {
            cout << "Invalid choice!" << endl;
            return;
        }

        if (equipped_weapon != nullptr) {
            attack = base_attack;
        }

        equipped_weapon = &inventory[choice - 1];
        attack = base_attack + equipped_weapon->magic_number;
        cout << "Equipped " << equipped_weapon->name << "! Attack is now " << attack << "." << endl;
    }

    void use_item() {
        cout << "Choose an item to use:\n";
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i].type == "healing") {
                cout << i + 1 << ". " << inventory[i].name << " (+" << inventory[i].magic_number << " health)" << endl;
            }
        }
        cout << "0. Go Back" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            return; // Επιστροφή χωρίς χρήση αντικειμένου
        }

        if (choice < 1 || choice > inventory.size() || inventory[choice - 1].type != "healing") {
            cout << "Invalid choice!" << endl;
            return;
        }

        Item &selected_item = inventory[choice - 1];
        health = min(health + selected_item.magic_number, 100);
        cout << "Used " << selected_item.name << ". Health restored to " << health << "." << endl;
        
        inventory.erase(inventory.begin() + (choice - 1));
    }
};

class Enemy {
public:
    string type;
    int health;
    int attack;
    int defense;

    Enemy(string t, int hp, int atk, int def) : type(t), health(hp), attack(atk), defense(def) {}

    void attack_player(Player &player) {
        int base_damage = max(attack - player.defense, 1);
        if (player.has_shield) {
            base_damage /= 2; // Μείωση damage αν ο παίκτης έχει ασπίδα
        }
        int damage_dealt = base_damage;
        player.take_damage(damage_dealt);
        cout << type << " attacked " << player.name << " for " << damage_dealt << " damage!" << endl;
    }
};

// Λειτουργία για turn-based μάχη
void battle(Player &player, Enemy &enemy) {
    bool player_turn = true;

    while (player.health > 0 && enemy.health > 0) {
        if (player_turn) {
            cout << "\nChoose an action:\n";
            cout << "1. Attack\n2. Defend\n3. Equip Weapon\n4. Use Item\n5. Run Away\n";
            int choice;
            cin >> choice;

            if (choice == 1) {
                player.attack_enemy(enemy.health, enemy.defense);
            } else if (choice == 2) {
                cout << player.name << " is defending!" << endl;
                player.defense += 5;
                player_turn = false;
            } else if (choice == 3) {
                player.equip_item();
            } else if (choice == 4) {
                player.use_item();
            } else if (choice == 5) {
                cout << player.name << " tries to run away!" << endl;
                if (rand() % 2 == 0) {
                    cout << "Successfully escaped!" << endl;
                    return;
                } else {
                    cout << "Failed to escape!" << endl;
                }
            } else {
                cout << "Invalid choice!" << endl;
            }
        } else {
            enemy.attack_player(player);
            player_turn = true;
        }

        if (enemy.health <= 0) {
            cout << "You defeated the " << enemy.type << "!" << endl;
        }
    }

    if (player.health <= 0) {
        cout << "Game Over! " << player.name << " has been defeated." << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Player player("Hero");
    player.inventory.push_back(Item("Iron Sword", 5, "weapon"));
    player.inventory.push_back(Item("Blunt Mace", 7, "weapon"));
    player.inventory.push_back(Item("Shield", 0, "weapon"));
    player.inventory.push_back(Item("Magic Potion", 20, "healing"));

    Enemy skeleton("Skeleton", 50, 8, 5);

    cout << "\nA wild " << skeleton.type << " appears!\n";
    battle(player, skeleton);

    return 0;
}
