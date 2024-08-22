#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// Structure to represent a charging station
struct ChargingStation {
    string name;
    string location;
    string type; // Fast/Slow charging
    int availableSlots;
};

// Function to display the list of charging stations
void displayStations(const vector<ChargingStation>& stations) {
    cout << "Available Charging Stations:\n";
    for(const auto& station : stations) {
        cout << "Name: " << station.name << ", Location: " << station.location 
             << ", Type: " << station.type << ", Available Slots: " << station.availableSlots << endl;
    }
}

// Function to filter stations based on type
vector<ChargingStation> filterStations(const vector<ChargingStation>& stations, const string& filterType) {
    vector<ChargingStation> filtered;
    for(const auto& station : stations) {
        if(station.type == filterType) {
            filtered.push_back(station);
        }
    }
    return filtered;
}

// Function to book a charging slot
void bookSlot(vector<ChargingStation>& stations, const string& stationName) {
    for(auto& station : stations) {
        if(station.name == stationName) {
            if(station.availableSlots > 0) {
                station.availableSlots--;
                cout << "Slot booked successfully at " << station.name << "!\n";
            } else {
                cout << "No available slots at " << station.name << "!\n";
            }
            return;
        }
    }
    cout << "Charging station not found.\n";
}

int main() {
    vector<ChargingStation> stations = {
        {"EV Fast Charge", "Downtown", "Fast", 5},
        {"GreenCharge", "Uptown", "Slow", 2},
        {"QuickCharge", "Suburb", "Fast", 3},
        {"EcoStation", "City Center", "Slow", 4}
    };

    cout << "Welcome to the EV Charging Station Finder and Slot Booking System\n";

    while(true) {
        cout << "\nOptions:\n";
        cout << "1. Display All Stations\n";
        cout << "2. Filter Stations by Type\n";
        cout << "3. Book a Charging Slot\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        int choice;
        cin >> choice;

        if(choice == 1) {
            displayStations(stations);
        } else if(choice == 2) {
            cout << "Enter type to filter by (Fast/Slow): ";
            string type;
            cin >> type;
            vector<ChargingStation> filtered = filterStations(stations, type);
            displayStations(filtered);
        } else if(choice == 3) {
            cout << "Enter the name of the charging station to book a slot: ";
            string name;
            cin.ignore();
            getline(cin, name);
            bookSlot(stations, name);
        } else if(choice == 4) {
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
