 #include "CuboidList.h"
int main() {
   
    //
    CuboidList cuboidList;

    int count;
    cout << "Enter the number of Cuboids to add: ";
    cin >> count;

    cuboidList.readFromKeyboard(count);

    cout << "Sorted List of Cuboids:\n";
    cuboidList.display();

    Cuboid searchCuboid;
    cout << "Enter the Cuboid you want to search for (length, width, height): ";
    cin >> searchCuboid;

    if (cuboidList.search(searchCuboid)) {
        cout << "Cuboid found in the list.\n";
    }
    else {
        cout << "Cuboid not found in the list.\n";
    }

    double averageVolume = cuboidList.findAverageVolume();
    cout << "Average volume of all Cuboids: " << averageVolume << "\n";
    return 0;
}
