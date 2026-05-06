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
    Account() { firstTime = true; }

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
        ofstream file(name+"_ticket.txt", ios::app);
        file << name << " " << email << " " << phone << endl;
        file.close();
    }

    string getName() { return name; }
    bool isFirstTime() { return firstTime; }
    void setOldUser() { firstTime = false; }
};


class Service {
public: //Abstract class
    virtual void show() = 0;
};


class MSRTC : public Service {
public:
    void show() {
        cout << "\n------ MSRTC BUSES ------\n";
        cout << "MH01 Pune->Mumbai 450\n";
        cout << "MH02 Pune->Nashik 400\n";
        cout << "MH03 Pune->Nagpur 1500\n";
        cout << "MH04 Mumbai->Nagpur 1750\n";
        cout << "MH05 Mumbai->Pune 450\n";
        cout << "MH06 Nashik->Pune 400\n";
        cout << "MH07 Nagpur->Pune 1500\n";
        cout << "MH08 Nagpur->Mumbai 1750\n";
        cout << "MH09 Pune->Aurangabad 600\n";
        cout << "MH10 Aurangabad->Mumbai 700\n";
    }

    int getFare(string id) {
        if(id=="MH01"||id=="MH05"){
            return 450;
        }
        if(id=="MH02"||id=="MH06"){
            return 400;
        }
        if(id=="MH03"||id=="MH07"){
            return 1500;
        }
        if(id=="MH04"||id=="MH08")
        {return 1750;
        }
        if(id=="MH09"){
            return 600;}

        if(id=="MH10"){
            return 700;
        }
        else{
            throw invalid_argument("Invalid Bus ID!");
        }
    }
};


class PrivateBus : public Service {
public:
    void show() {
        cout << "\n------ PRIVATE BUSES ------\n";

        // Pune-Mumbai (3)
        cout << "01 Purple Pune->Mumbai 650\n";
        cout << "02 InterCity Pune->Mumbai 550\n";
        cout << "03 DNR Pune->Mumbai 700\n";

        // Pune-Nagpur (3)
        cout << "11 Purple Pune->Nagpur 2600\n";
        cout << "12 InterCity Pune->Nagpur 2500\n";
        cout << "13 Saini Pune->Nagpur 1800\n";

        // Mumbai-Nagpur (3)
        cout << "21 Purple Mumbai->Nagpur 3200\n";
        cout << "22 InterCity Mumbai->Nagpur 3600\n";
        cout << "23 DNR Mumbai->Nagpur 3900\n";

        // Pune-Nashik (3)
        cout << "31 Purple Pune->Nashik 900\n";
        cout << "32 InterCity Pune->Nashik 850\n";
        cout << "33 Saini Pune->Nashik 800\n";

        // Mumbai-Nashik (3)
        cout << "41 Purple Mumbai->Nashik 1000\n";
        cout << "42 InterCity Mumbai->Nashik 950\n";
        cout << "43 Saini Mumbai->Nashik 900\n";
    }

    int getFare(int id) {
        if(id>=1 && id<=3) return 650;
        if(id>=11 && id<=13) return 2500;
        if(id>=21 && id<=23) return 3500;
        if(id>=31 && id<=33) return 850;
        if(id>=41 && id<=43) return 950;
        else throw invalid_argument("Invalid Bus Code!");
    }
};

// ---------------- TICKET ----------------
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
        cout << "\nAdd Amenities:\n1. AC (+200)\n2. Pillow (+50)\n3. Blanket (+100)\n4. None\nChoice: ";
        cin >> choice;

        if(choice == 1) fare += 200;
        else if(choice == 2) fare += 50;
        else if(choice == 3) fare += 100;
    }

    void applyCoupon(Account &a) {
        if(a.isFirstTime()) {
            string code;
            cout << "Enter coupon code (FIRST50): ";
            cin >> code;

            if(code == "FIRST50") {
                fare -= 50;
                cout << "Coupon Applied!\n";
                a.setOldUser();
            }
        }
    }

    void generate() {
        ofstream file(name+"_ticket.doc");
        if(!file) throw runtime_error("File error!");

        file << "===== BUS TICKET =====\n";
        file << "Ticket ID: " << ticketID << endl;
        file << "Name: " << name << endl;
        file << "Bus: " << busID << endl;
        file << "Seat: " << seat << endl;
        file << "Date: " << date << endl;
        file << "Fare: " << fare << endl;
        file << "======================\n";
        file.close();

        ofstream hist(name+"_tickets.txt", ios::app);
        hist << ticketID << " " << name << " " << busID << " "
             << seat << " " << date << " " << fare << endl;
        hist.close();

        cout << "\nTicket Booked! ID: " << ticketID << endl;
    }

    static void history() {
        ifstream file("tickets.txt");
        if(!file) {
            cout << "No history!\n";
            return;
        }

        int id, seat, fare;
        string name, bus, date;

        while(file >> id >> name >> bus >> seat >> date >> fare) {
            cout << "\nID: " << id << " | " << name
                 << " | Bus: " << bus
                 << " | Seat: " << seat
                 << " | Date: " << date
                 << " | Fare: " << fare;
        }
        file.close();
    }

    static void cancel(int cid) {
        ifstream file("tickets.txt");
        ofstream temp("temp.txt");

        int id, seat, fare;
        string name, bus, date;
        bool found = false;

        while(file >> id >> name >> bus >> seat >> date >> fare) {
            if(id == cid) {
                found = true;
                continue;
            }
            temp << id << " " << name << " " << bus << " "
                 << seat << " " << date << " " << fare << endl;
        }

        file.close();
        temp.close();

        remove("tickets.txt");
        rename("temp.txt","tickets.txt");

        if(found) cout << "Cancelled!\n";
        else cout << "ID not found!\n";
    }
};

// ---------------- MAIN ----------------
int main() {
    int choice;

    while(true) {
        cout << "\n===== BUS SYSTEM =====\n";
        cout << "1. Register\n2. Book Ticket\n3. History\n4. Cancel\n5. Exit\n";
        cout << "Enter: ";
        cin >> choice;

        try {
            if(choice == 1) {
                Account a;
                a.input();
                cout << "Registered!\n";
            }

            else if(choice == 2) {
                Account a;
                a.input();

                string date, busID;
                int seat, type;

                cout << "Enter Date: ";
                cin >> date;

                cout << "1. MSRTC\n2. Private\nChoice: ";
                cin >> type;

                Ticket t;

                if(type == 1) {
                    MSRTC m;
                    m.show();

                    cout << "Enter Bus ID: ";
                    cin >> busID;

                    cout << "Seat: ";
                    cin >> seat;

                    int fare = m.getFare(busID);

                    t.book(a, busID, seat, date, fare);
                }
                else if(type == 2) {
                    PrivateBus p;
                    p.show();

                    int id;
                    cout << "Enter Code: ";
                    cin >> id;

                    cout << "Seat: ";
                    cin >> seat;

                    int fare = p.getFare(id);

                    t.book(a, to_string(id), seat, date, fare);
                }
                else throw invalid_argument("Invalid type!");

                t.addAmenities();
                t.applyCoupon(a);
                t.generate();
            }

            else if(choice == 3) {
                Ticket::history();
            }

            else if(choice == 4) {
                int id;
                cout << "Enter ID: ";
                cin >> id;
                Ticket::cancel(id);
            }

            else if(choice == 5) {
                break;
            }

            else {
                cout << "Invalid!\n";
            }

        } catch(exception &e) {
            cout << "\nError: " << e.what() << endl;
        }
    }

    return 0;
}