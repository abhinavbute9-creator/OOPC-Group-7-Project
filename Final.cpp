#include<iostream>
#include<fstream>
#include<stdexcept>
#include<cstdlib>
using namespace std;

class Account {
private:
    string name, email;
    long long int phone;
    int age;
    bool firstTime;

public:
    Account() {
        firstTime = true;
    }

    void input() {
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        if(age <= 0 || age > 120)
            throw invalid_argument("Invalid age!");

        cout << "Enter Phone: ";
        cin >> phone;

        cin.ignore();

        cout << "Enter Email: ";
        getline(cin, email);

        saveUser();
    }

    void saveUser() {
        ofstream file(name + "_UserData.txt", ios::app);

        file << "Name: " << name << endl;
        file << "Email: " << email << endl;
        file << "Phone: " << phone << endl;
        file << "--------------------------" << endl;

        file.close();
    }

    string getName() {
        return name;
    }

    bool isFirstTime() {
        return firstTime;
    }

    void setOldUser() {
        firstTime = false;
    }
};

class Service {
public:
    virtual void show() = 0;
};

class MSRTC : public Service {
public:
    void show() {

        cout << "\n=========== MSRTC BUSES ===========\n";

        cout << "\n------ Pune <-> Mumbai ------\n";
        cout << "MH01  Pune -> Mumbai      Fare: 450   Seats: 40\n";
        cout << "MH05  Mumbai -> Pune      Fare: 450   Seats: 40\n";

        cout << "\n------ Pune <-> Nashik ------\n";
        cout << "MH02  Pune -> Nashik      Fare: 400   Seats: 40\n";
        cout << "MH06  Nashik -> Pune      Fare: 400   Seats: 40\n";

        cout << "\n------ Pune <-> Nagpur ------\n";
        cout << "MH03  Pune -> Nagpur      Fare: 1500  Seats: 40\n";
        cout << "MH07  Nagpur -> Pune      Fare: 1500  Seats: 40\n";

        cout << "\n------ Mumbai <-> Nagpur ------\n";
        cout << "MH04  Mumbai -> Nagpur    Fare: 1750  Seats: 40\n";
        cout << "MH08  Nagpur -> Mumbai    Fare: 1750  Seats: 40\n";

        cout << "\n------ Pune -> Aurangabad ------\n";
        cout << "MH09  Pune -> Aurangabad  Fare: 600   Seats: 40\n";

        cout << "\n------ Aurangabad -> Mumbai ------\n";
        cout << "MH10  Aurangabad -> Mumbai Fare: 700  Seats: 40\n";
    }

    int getFare(string id) {

        if(id=="MH01" || id=="MH05")
            return 450;

        if(id=="MH02" || id=="MH06")
            return 400;

        if(id=="MH03" || id=="MH07")
            return 1500;

        if(id=="MH04" || id=="MH08")
            return 1750;

        if(id=="MH09")
            return 600;

        if(id=="MH10")
            return 700;

        throw invalid_argument("Invalid Bus ID!");
    }
};

class PrivateBus : public Service {
public:
    void show() {

        cout << "\n=========== PRIVATE BUSES ===========\n";

        cout << "\n------ Pune -> Mumbai ------\n";
        cout << "01  Purple      Fare: 650   Seats: 40\n";
        cout << "02  InterCity   Fare: 550   Seats: 40\n";
        cout << "03  DNR         Fare: 700   Seats: 40\n";

        cout << "\n------ Pune -> Nagpur ------\n";
        cout << "11  Purple      Fare: 2600  Seats: 40\n";
        cout << "12  InterCity   Fare: 2500  Seats: 40\n";
        cout << "13  Saini       Fare: 1800  Seats: 40\n";

        cout << "\n------ Mumbai -> Nagpur ------\n";
        cout << "21  Purple      Fare: 3200  Seats: 40\n";
        cout << "22  InterCity   Fare: 3600  Seats: 40\n";
        cout << "23  DNR         Fare: 3900  Seats: 40\n";

        cout << "\n------ Pune -> Nashik ------\n";
        cout << "31  Purple      Fare: 900   Seats: 40\n";
        cout << "32  InterCity   Fare: 850   Seats: 40\n";
        cout << "33  Saini       Fare: 800   Seats: 40\n";

        cout << "\n------ Mumbai -> Nashik ------\n";
        cout << "41  Purple      Fare: 1000  Seats: 40\n";
        cout << "42  InterCity   Fare: 950   Seats: 40\n";
        cout << "43  Saini       Fare: 900   Seats: 40\n";
    }

    int getFare(int id) {

        if(id>=1 && id<=3)
            return 650;

        if(id>=11 && id<=13)
            return 2500;

        if(id>=21 && id<=23)
            return 3500;

        if(id>=31 && id<=33)
            return 850;

        if(id>=41 && id<=43)
            return 950;

        throw invalid_argument("Invalid Bus Code!");
    }
};

class Ticket {
private:
    string name, busID, date;
    int seat, ticketID, fare;

public:

    void book(Account &a, string id, int s, string d, int baseFare) {

        name = a.getName();
        busID = id;
        seat = s;
        date = d;
        fare = baseFare;

        ticketID = rand()%9000 + 1000;
    }

    void addAmenities() {

        int choice;

        while(true) {

            cout << "\n=========== AMENITIES ===========\n";
            cout << "1. AC (+200)\n";
            cout << "2. Pillow (+50)\n";
            cout << "3. Blanket (+100)\n";
            cout << "4. Charging Port (+80)\n";
            cout << "5. Water Bottle (+30)\n";
            cout << "6. Snacks (+120)\n";
            cout << "7. Finish Selection\n";

            cout << "Enter Choice: ";
            cin >> choice;

            if(choice == 1) {
                fare += 200;
                cout << "AC Added!\n";
            }

            else if(choice == 2) {
                fare += 50;
                cout << "Pillow Added!\n";
            }

            else if(choice == 3) {
                fare += 100;
                cout << "Blanket Added!\n";
            }

            else if(choice == 4) {
                fare += 80;
                cout << "Charging Port Added!\n";
            }

            else if(choice == 5) {
                fare += 30;
                cout << "Water Bottle Added!\n";
            }

            else if(choice == 6) {
                fare += 120;
                cout << "Snacks Added!\n";
            }

            else if(choice == 7) {
                break;
            }

            else {
                cout << "Invalid Choice!\n";
            }
        }
    }

    void applyCoupon(Account &a) {

        if(a.isFirstTime()) {

            string code;

            cout << "Enter Coupon Code (FIRST50): ";
            cin >> code;

            if(code == "FIRST50") {

                fare -= 50;

                cout << "Coupon Applied Successfully!\n";

                a.setOldUser();
            }

            else {
                cout << "Invalid Coupon!\n";
            }
        }
    }

    void generate() {

        ofstream file(name + "_ticket.txt");

        if(!file)
            throw runtime_error("File error!");

        file << "=========== BUS TICKET ===========\n";
        file << "Ticket ID : " << ticketID << endl;
        file << "Passenger : " << name << endl;
        file << "Bus ID    : " << busID << endl;
        file << "Seat No   : " << seat << endl;
        file << "Journey   : " << date << endl;
        file << "Final Fare: " << fare << endl;
        file << "==================================\n";

        file.close();

        ofstream hist(name + "_tickets.txt", ios::app);

        hist << ticketID << " "
             << name << " "
             << busID << " "
             << seat << " "
             << date << " "
             << fare << endl;

        hist.close();

        cout << "\nTicket Successfully Booked!\n";
        cout << "Your Ticket ID is: " << ticketID << endl;
    }

    static void history(string username) {

        ifstream file(username + "_tickets.txt");

        if(!file) {
            cout << "No Booking History Found!\n";
            return;
        }

        int id, seat, fare;
        string name, bus, date;

        cout << "\n=========== BOOKING HISTORY ===========\n";

        while(file >> id >> name >> bus >> seat >> date >> fare) {

            cout << "\nTicket ID : " << id << endl;
            cout << "Name      : " << name << endl;
            cout << "Bus ID    : " << bus << endl;
            cout << "Seat No   : " << seat << endl;
            cout << "Date      : " << date << endl;
            cout << "Fare      : " << fare << endl;
            cout << "--------------------------------------\n";
        }

        file.close();
    }

    static void cancel(int cid, string username) {

        ifstream file(username + "_tickets.txt");
        ofstream temp("temp.txt");

        int id, seat, fare;
        string name, bus, date;

        bool found = false;

        while(file >> id >> name >> bus >> seat >> date >> fare) {

            if(id == cid) {
                found = true;
                continue;
            }

            temp << id << " "
                 << name << " "
                 << bus << " "
                 << seat << " "
                 << date << " "
                 << fare << endl;
        }

        file.close();
        temp.close();

        remove((username + "_tickets.txt").c_str());
        rename("temp.txt", (username + "_tickets.txt").c_str());

        if(found)
            cout << "Ticket Cancelled Successfully!\n";

        else
            cout << "Ticket ID Not Found!\n";
    }
};

int main() {

    int choice;

    while(true) {

        cout << "\n=========== BUS BOOKING SYSTEM ===========\n";
        cout << "1. Register User\n";
        cout << "2. Book Ticket\n";
        cout << "3. View History\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        try {

            if(choice == 1) {

                Account a;

                a.input();

                cout << "\nUser Registered Successfully!\n";
            }

            else if(choice == 2) {

                Account a;

                a.input();

                string date, busID;
                int seat, type;

                cout << "Enter Journey Date: ";
                cin >> date;

                cout << "\n1. MSRTC Bus\n";
                cout << "2. Private Bus\n";

                cout << "Enter Choice: ";
                cin >> type;

                Ticket t;

                if(type == 1) {

                    MSRTC m;

                    m.show();

                    cout << "\nEnter Bus ID: ";
                    cin >> busID;

                    cout << "Enter Seat Number: ";
                    cin >> seat;

                    int fare = m.getFare(busID);

                    t.book(a, busID, seat, date, fare);
                }

                else if(type == 2) {

                    PrivateBus p;

                    p.show();

                    int id;

                    cout << "\nEnter Bus Code: ";
                    cin >> id;

                    cout << "Enter Seat Number: ";
                    cin >> seat;

                    int fare = p.getFare(id);

                    t.book(a, to_string(id), seat, date, fare);
                }

                else {
                    throw invalid_argument("Invalid Bus Type!");
                }

                t.addAmenities();

                t.applyCoupon(a);

                t.generate();
            }

            else if(choice == 3) {

                string username;

                cout << "Enter Username: ";
                cin >> username;

                Ticket::history(username);
            }

            else if(choice == 4) {

                int id;
                string username;

                cout << "Enter Username: ";
                cin >> username;

                cout << "Enter Ticket ID: ";
                cin >> id;

                Ticket::cancel(id, username);
            }

            else if(choice == 5) {

                cout << "Thank You For Using The System!\n";

                break;
            }

            else {

                cout << "Invalid Choice!\n";
            }

        }

        catch(exception &e) {

            cout << "\nError: " << e.what() << endl;
        }
    }

    return 0;
}

