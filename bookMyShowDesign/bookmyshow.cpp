#include <iostream>
#include <vector>
#include <map>
#include <thread>
#include <mutex>
#include <unordered_map>

using namespace std;

// ========================== GLOBAL MUTEX FOR THREAD SAFETY ==========================
mutex seatMutex;

// ========================== CLASS: SHOW ==========================
class Show {
public:
    string showId;
    string movieTitle;
    int totalSeats;
    map<int, bool> seatAvailability; // SeatID -> isBooked

    Show(string id, string title, int seats) : showId(id), movieTitle(title), totalSeats(seats) {
        for (int i = 1; i <= seats; i++) {
            seatAvailability[i] = false; // Initially all seats are unbooked
        }
    }

    void displaySeats();
    bool bookSeats(vector<int>& seats);
};

// ========================== DISPLAY SEATS ==========================
void Show::displaySeats() {
    cout << "\n🔹 Seat Availability for Show (" << showId << ") - " << movieTitle << endl;
    for (auto& seat : seatAvailability) {
        cout << "Seat " << seat.first << " -> " << (seat.second ? "Booked" : "Available") << endl;
    }
}

// ========================== BOOK SEATS WITH THREAD SAFETY ==========================
bool Show::bookSeats(vector<int>& seats) {
    lock_guard<mutex> lock(seatMutex); // Ensures thread safety

    // Check seat availability first
    for (int seat : seats) {
        if (seatAvailability[seat]) {
            cout << "❌ Seat " << seat << " is already booked! Booking failed.\n";
            return false;
        }
    }

    // Book the seats
    for (int seat : seats) {
        seatAvailability[seat] = true;
    }

    cout << "✅ Booking Successful for Seats: ";
    for (int seat : seats) cout << seat << " ";
    cout << endl;

    return true;
}

// ========================== CLASS: USER ==========================
class User {
public:
    string userId;
    string userName;

    User(string id, string name) : userId(id), userName(name) {}

    void bookShowSeats(Show& show, vector<int> seats) {
        if (!show.bookSeats(seats)) {
            cout << "⚠️ " << userName << " couldn't book seats: ";
            for (int seat : seats) cout << seat << " ";
            cout << endl;
        } else {
            cout << "🎟️ " << userName << " successfully booked seats: ";
            for (int seat : seats) cout << seat << " ";
            cout << endl;
        }
    }
};

// ========================== CLASS: BOOKMYSHOW SYSTEM ==========================
class BookMyShowSystem {
public:
    unordered_map<string, Show> shows; // ShowID -> Show Object

    void addShow(string showId, string title, int seats) {
        shows[showId] = Show(showId, title, seats);
    }

    Show& getShow(string showId) {
        return shows[showId];
    }
};

// ========================== SIMULATE MULTI-USER BOOKINGS ==========================
void simulateBooking(User& user, Show& show, vector<int> seats) {
    user.bookShowSeats(show, seats);
}

// ========================== MAIN FUNCTION ==========================
int main() {
    BookMyShowSystem system;

    // Add a movie show
    system.addShow("S301", "Avengers: Endgame", 10);
    Show& show1 = system.getShow("S301");

    // Display seats before booking
    show1.displaySeats();

    // Create users
    User user1("U101", "Alice");
    User user2("U102", "Bob");
    User user3("U103", "Charlie");

    // Simulate multiple users booking seats at the same time
    thread t1(simulateBooking, ref(user1), ref(show1), vector<int>{2, 4, 6});
    thread t2(simulateBooking, ref(user2), ref(show1), vector<int>{4, 5, 6});
    thread t3(simulateBooking, ref(user3), ref(show1), vector<int>{1, 2, 3});

    // Join threads to wait for execution
    t1.join();
    t2.join();
    t3.join();

    // Display available seats after booking
    show1.displaySeats();

    return 0;
}
