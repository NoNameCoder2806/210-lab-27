// COMSC-210 | Lab 27 | Dat Hoang Vien
// IDE used: Visual Studio Code

// Libraries
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

// Constants
const int MIN_FRIENDSHIP_LEVEL = 0;
const int MAX_FRIENDSHIP_LEVEL = 10;
const int DEFAULT_FRIENDSHIP_LEVEL = 5;
const int MIN_CHOICE = 1;
const int MAX_CHOICE = 4;

// Function implementations
void displayMenu();
void increaseFriendship(map<string, tuple<int, string, string>>& villagers);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagers);
void searchForVillager(const map<string, tuple<int, string, string>>& villagers);
void displayVillagers(const map<string, tuple<int, string, string>>& villagers);

// Main function
int main()
{
    // Declare a map to store villagers
    map<string, tuple<int, string, string>> villagers;

    // Insert elements into the map, use make_tuple() to turn the data into tuples
    villagers["Audie"] = make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "Wolf", "Foxtrot!");
    villagers["Raymond"] = make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "Cat", "Cripes!");

    // Insert another element
    villagers.insert({"Marshal", make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "Squirrel", "Sulky!")});

    // Program loop
    while (true)
    {
        // Display the menu
        displayMenu();

        // Declare an int variable to store the user's choice
        int choice = 0;

        // Prompt user to enter their choice
        cout << " - Enter your choice: ";
        cin >> choice;
        cin.ignore(1000, 10);

        // Choice input validation
        while (choice < MIN_CHOICE || choice > MAX_CHOICE)
        {
            // Prompt user to enter a new choice
            cout << "Invalid! Please enter a valid choice (1-4): ";
            cin >> choice;
            cin.ignore(1000, 10);
        }

        // Switch case for the choice
        switch(choice)
        {
            // Increase Friendship
            case 1:
            {
                // Call the increaseFriendship() function
                increaseFriendship(villagers);

                break;
            }

            // Decrease Friendship
            case 2:
            {
                // Call the decreaseFriendship() function
                decreaseFriendship(villagers);

                break;
            }

            // Search for Villager
            case 3:
            {
                // Call the searchForVillager() function
                searchForVillager(villagers);

                break;
            }

            // Exit
            case 4:
            {
                // Display a message
                cout << "Exiting the program... Thank you for using!" << endl;

                // Exit the main function
                return 0;
            }
        }

        // Display the villagers after each operation
        displayVillagers(villagers);
    }

    // access the map using a range-based for loop
    cout << "Villagers and their information (range-based for loop):" << endl;
    for (auto pair : villagers)
    {
        cout << pair.first << " [";
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "]";
        cout << endl;
    }

    // Access the map using iterators
    cout << "\nVillagers and their information (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it)
    {
        cout << it->first << " [";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]";
        cout << endl;
    }

    // Delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end())    // the iterator points to beyond the end of the map
                                  // if searchKey is not found
    {
        cout << "\nFound " << searchKey << "'s information: " << endl;
        cout << " - Friendship level: " << get<0>(it->second) << endl;
        cout << " - Species: " << get<1>(it->second) << endl;
        cout << " - Catchphrase: " << get<2>(it->second) << endl;
        cout << endl;
    }
    else
    {
        cout << endl << searchKey << " not found." << endl;
    }

    // Report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}

// Function implementations
void displayMenu()
{
    // Display the menu
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
}

void increaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    // Declare a variable to store the villager's name
    string name = "";

    // Prompt the user to enter the villager's name
    cout << " - Please enter the name of the Villager: ";
    cin >> name;
    cin.ignore(1000, 10);

    // Check if the name exists
    if (villagers.find(name))
}

void displayVillagers(const map<string, tuple<int, string, string>>& villagers)
{
    // Display a message
    cout << "Villagers details: " << endl;

    // Iterate through the map and display all the villagers
    for (auto pair : villagers)
    {
        // Display the villagers' names
        cout << pair.first << " [";

        // Display the villagers' other details
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << "]";

        // Enter a new line
        cout << endl;
    }
}