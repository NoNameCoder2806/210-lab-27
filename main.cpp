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
const int MAX_CHOICE = 6;

// Function implementations
void displayMenu();
void addVillager(map<string, tuple<int, string, string>>& villagers);
void deleteVillager(map<string, tuple<int, string, string>>& villagers);
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
            // Add Villager
            case 1:
            {
                // Call the addVillager() function
                addVillager(villagers);

                break;
            }

            // Delete Villager
            case 2:
            {
                // Call the deleteVillager() function
                deleteVillager(villagers);

                break;
            }

            // Increase Friendship
            case 3:
            {
                // Call the increaseFriendship() function
                increaseFriendship(villagers);

                break;
            }

            // Decrease Friendship
            case 4:
            {
                // Call the decreaseFriendship() function
                decreaseFriendship(villagers);

                break;
            }

            // Search for Villager
            case 5:
            {
                // Call the searchForVillager() function
                searchForVillager(villagers);

                break;
            }

            // Exit
            case 6:
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
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
}

void addVillager(map<string, tuple<int, string, string>>& villagers)
{
    // Declare variables to store the villager's information
    string name;
    int friendshipLevel;
    string species;
    string catchphrase;

    // Prompt user to enter villager's name
    cout << " - Villager's name: ";
    getline(cin, name);
    cin.ignore(1000, 10);

    // Validate the input
    while (name.length() == 0)
    {
        // Display an error message
        cout << " --- Error! The name cannot be empty! --- " << endl;

        // Prompt the user to enter a new name
        cout << " - Please enter a new name: ";
        getline(cin, name);
        cin.ignore(1000, 10);
    }

    // Prompt the user to enter the villager's friendship level
    cout << " - Friendship level: ";
    cin >> friendshipLevel;
    cin.ignore(1000, 10);

    // Validate the input
    while (friendshipLevel < MIN_FRIENDSHIP_LEVEL || friendshipLevel > MAX_FRIENDSHIP_LEVEL)
    {
        // Display an error message
        cout << " --- Error! The friendship level must be from 0-10! --- " << endl;

        // Prompt the user to enter a new friendship level
        cout << " - Please enter a new friendship level: ";
        cin >> friendshipLevel;
        cin.ignore(1000, 10);
    }

    // Prompt the user to enter the villager's species
    cout << " - Species: ";
    getline(cin, species);
    cin.ignore(1000, 10);

    // Validate the input
    while (species.length() == 0)
    {
        // Display an error message
        cout << " --- Error! The species cannot be empty! --- " << endl;

        // Prompt the user to enter a new species
        cout << " - Please enter a new species: ";
        getline(cin, species);
        cin.ignore(1000, 10);
    }

    // Prompt the user to enter the villager's catchphrase
    cout << " - Catchphrase: ";
    getline(cin, catchphrase);
    cin.ignore(1000, 10);

    // Validate the input
    while (catchphrase.length() == 0)
    {
        // Display an error message
        cout << " --- Error! The catchphrase cannot be empty! --- " << endl;

        // Prompt the user to enter a new catchphrase
        cout << " - Please enter a new catchphrase: ";
        getline(cin, catchphrase);
        cin.ignore(1000, 10);
    }

    // Insert the data into the map
    villagers.insert({name, make_tuple(friendshipLevel, species, catchphrase)});

    // Display a message
    cout << " --- " << name << " is added! --- " << endl;
    
    // Enter a new line
    cout << endl;
}

void deleteVillager(map<string, tuple<int, string, string>>& villagers)
{
    // Declare a variable to store the villager's name
    string name;

    // Prompt the user to enter the villager's name
    cout << " - Please enter the name of the Villager: ";
    cin >> name;
    cin.ignore(1000, 10);

    // Declare an iterator and use find() to search for the villager
    auto it = villagers.find(name);

    // Check if the name exists
    if (it != villagers.end())
    {
        // Erase the villager from the map
        villagers.erase(name);

        // Display a message
        cout << " --- " << it->first << " is deleted! --- " << endl;
    }
    else
    {
        // Display a message
        cout << " --- Villager not found! --- " << endl;
    }

    // Enter a new line
    cout << endl;
}

void increaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    // Declare a variable to store the villager's name
    string name = "";

    // Prompt the user to enter the villager's name
    cout << " - Please enter the name of the Villager: ";
    cin >> name;
    cin.ignore(1000, 10);

    // Declare an iterator and use find() to search for the villager
    auto it = villagers.find(name);

    // Check if the name exists
    if (it != villagers.end())
    {
        // Check if the friendship level is maxed or not (level 10)
        if (get<0>(it->second) < MAX_FRIENDSHIP_LEVEL)
        {
            // Increase the friendship level
            get<0>(it->second)++;
        }

        // Display a message
        cout << " --- " << it->first << " friendship level increased! --- " << endl;
    }
    else
    {
        // Display a message
        cout << " --- Villager not found! --- " << endl;
    }

    // Enter a new line
    cout << endl;
}

void decreaseFriendship(map<string, tuple<int, string, string>>& villagers)
{
    // Declare a variable to store the villager's name
    string name = "";

    // Prompt the user to enter the villager's name
    cout << " - Please enter the name of the Villager: ";
    cin >> name;
    cin.ignore(1000, 10);

    // Declare an iterator and use find() to search for the villager
    auto it = villagers.find(name);

    // Check if the name exists
    if (it != villagers.end())
    {
        // Check if the friendship level is positive or not (> level 0)
        if (get<0>(it->second) > MIN_FRIENDSHIP_LEVEL)
        {
            // Decrease the friendship level
            get<0>(it->second)--;
        }

        // Display a message
        cout << " --- " << it->first << " friendship level decreased! --- " << endl;
    }
    else
    {
        // Display a message
        cout << " --- Villager not found! --- " << endl;
    }

    // Enter a new line
    cout << endl;
}

void searchForVillager(const map<string, tuple<int, string, string>>& villagers)
{
    // Declare a variable to store the villager's name
    string name = "";

    // Prompt the user to enter the villager's name
    cout << " - Please enter the name of the Villager: ";
    cin >> name;
    cin.ignore(1000, 10);

    // Declare an iterator and use find() to search for the villager
    auto it = villagers.find(name);

    // Check if the name exists
    if (it != villagers.end())
    {
        // Display a message
        cout << " --- Villager found! --- " << endl;

        // Display the villager's name
        cout << it->first << " [";

        // Display the villager's other details
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second) << "]";
    }
    else
    {
        // Display a message
        cout << " --- Villager not found! --- " << endl;
    }

    // Enter a new line
    cout << endl;
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

    // Enter a new line
    cout << endl;
}