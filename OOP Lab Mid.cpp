#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#include <vector>

class reservation {
private:
    string name;
    string timeSlot;

public:
    reservation(string n, string ts) : name(n), timeSlot(ts) {}

    string getName() const {
        return name;
    }

    string getTimeSlot() const {
        return timeSlot;
    }
};

class restaurant {
private:
    vector<string> slotsAvailable;
    vector<reservation> reservations;

public:
    void initializeTimeSlots() {

        slotsAvailable.push_back("\t\t\t11:00 PM");
        slotsAvailable.push_back("\t\t\t12:00 PM");
        slotsAvailable.push_back("\t\t\t1:00 PM");
        slotsAvailable.push_back("\t\t\t2:00 PM");
        slotsAvailable.push_back("\t\t\t3:00 PM");
        slotsAvailable.push_back("\t\t\t4:00 PM");
        slotsAvailable.push_back("\t\t\t5:00 PM");
        slotsAvailable.push_back("\t\t\t6:00 PM");
    }

    void showAvailableslots() {
        cout << "Available Time Slots: " << endl;
        for (const auto& slot : slotsAvailable) {
            cout << slot << endl;
        }
    }

    bool makeReservation(string name, string timeSlot) {

        for (const auto& reservation : reservations) {
            if (reservation.getTimeSlot() == timeSlot) {
                return false;
            }
        }

        reservations.push_back(reservation(name, timeSlot));

        for (auto count = slotsAvailable.begin(); count != slotsAvailable.end(); ++count) {
            if (*count == timeSlot) {
                slotsAvailable.erase(count);
                break;
            }
        }
        return true;
    }

    void displayReservations() {
        cout << "\nReservations:" << endl;
        for (const auto& reservation : reservations) {
            cout << "\nName: " << reservation.getName() << "\n Time slot: " << reservation.getTimeSlot() << endl;
        }
    }
};

int main() {

    restaurant r1;

    r1.initializeTimeSlots();

    r1.showAvailableslots();

    string name, timeSlot;
    cout << "enter your name: ";
    getline(cin, name);
    cout << "Enter preferred time slot: ";
    getline(cin, timeSlot);

    bool success = r1.makeReservation(name, timeSlot);

    if (success) {
        cout << "Reservation successful!" << endl;
    }
    else {
        cout << "Sorry, the selected time slot is not available." << endl;
    }

   
    r1.displayReservations();
    
    return 0;
}