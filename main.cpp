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

// Main function
int main()
{
    // Declare a map to store villagers
    map<string, tuple<int, string, string>> villagers;

    // Insert elements into the map, use make_tuple() to turn the data into tuples
    villagers["Audie"] = make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "Yellow", "Red");
    villagers["Raymond"] = make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "Gray", "White");
    villagers.insert({"Marshal", make_tuple(DEFAULT_FRIENDSHIP_LEVEL, "White", "Black")});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors)
    {
        cout << pair.first << ": ";
        for (auto color : pair.second)
        {
            cout << color << " ";
        }
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it)
    {
        cout << it->first << ": ";
        for (auto color : it->second)
        {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end())    // the iterator points to beyond the end of the map
                                       // if searchKey is not found
    {
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
        {
            cout << color << " ";
        }
        cout << endl;
    }
    else
    {
        cout << endl << searchKey << " not found." << endl;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
