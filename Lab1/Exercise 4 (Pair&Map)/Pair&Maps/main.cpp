#include <iostream>
#include "pair_map.h"
#include"gameCase.h"

using namespace std;

void displayMenu() {
    cout << "menu:" << endl;
    cout << "1. add a new pair" << endl;
    cout << "2. update an existing pair" << endl;
    cout << "3. search for a value by key" << endl;
    cout << "4. delete a pair by key" << endl;
    cout << "5. print map contents" << endl;
    cout << "6. exit" << endl;
    cout << "7. Creature map contents" << endl;
    cout << "enter your choice: ";
}

int main() {
    /////////////// for Game Case
    cout << "Game Case. " << endl;
    Monster monster("Goblin");
    Dragon dragon("Smaug");
    Soldier soldier("Legolas");
    Player player("Aragorn");

    // Create a map to associate creatures with positions
    myMap<Creature, Position> creatureMap;

    // Add creatures to the map with their positions
    creatureMap.addPair(monster, Position(10, 20));
    creatureMap.addPair(dragon, Position(50, 60));
    creatureMap.addPair(soldier, Position(30, 40));
    creatureMap.addPair(player, Position(0, 0));
    ////////////////

    myMap<int, string> myMapObj;
    int choice;
    int key;
    string value;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Add a new pair
            cout << "Enter key (integer): ";
            cin >> key;
            cout << "Enter value (string): ";
            cin >> value;
            if (myMapObj.addPair(key, value)) {
                cout << "Pair added successfully!" << endl;
            }
            else {
                cout << "Failed to add pair (map is full)." << endl;
            }
            break;

        case 2: // Update an existing pair
            cout << "Enter key (integer): ";
            cin >> key;
            cout << "Enter new value (string): ";
            cin >> value;
            if (myMapObj.updateValue(key, value)) {
                cout << "Pair updated successfully!" << endl;
            }
            else {
                cout << "Key not found." << endl;
            }
            break;

        case 3: // Search for a value by key
            cout << "Enter key (integer): ";
            cin >> key;
            try {
                value = myMapObj.getValue(key);
                cout << "Value: " << value << endl;
            }
            catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
            break;

        case 4: // Delete a pair by key
            cout << "Enter key (integer): ";
            cin >> key;
            if (myMapObj.deletePair(key)) {
                cout << "Pair deleted successfully!" << endl;
            }
            else {
                cout << "Key not found." << endl;
            }
            break;

        case 5: // Print map contents
            cout << "Map contents:" << endl;
            myMapObj.displayMap();
            break;

        case 6: // Exit
            cout << "Exiting program." << endl;
            return 0;

        case 7:
            creatureMap.displayMap();

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    
    return 0;
}
