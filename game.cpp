#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

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

    // Δημιουργία παίκτη και εχθρού
    Player player("Hero");
    Enemy enemy("Goblin", 50, 8, 3);

    // Παράδειγμα μάχης
    while (enemy.health > 0 && player.health > 0) {
        player.attack_enemy(enemy.health);
        if (enemy.health > 0) {
            enemy.attack_player(player);
        }
    }

    if (player.health > 0) {
        cout << player.name << " won the battle!" << endl;
    } else {
        cout << "The enemy defeated " << player.name << "!" << endl;
    }

    return 0;
}
