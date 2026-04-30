#include<bits/stdc++.h>
using namespace std;

    class Passenger{

    public : 

    string name;
    int age;
    long int phone_number;
};

class Bus{

    public :

    string bus_number;
    int numberofSeats;
    // string route;
    string Boarding_point;
    string droping_point;
    
    void features(){
        cout << "+ Bus features" << endl;
        cout << "+ Pillow" << endl;
        cout << "+ Blankets" << endl;
        cout << "+ Charging Point" << endl;
        cout << "+ Bed Sheet" << endl;
        cout << "+ Reading Light" << endl;
    }
};

class Ticket : public Bus,public Passenger{

    public : 

    int seat_number;
    float prize;

    void printticket(){

        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Phone number : " << phone_number << endl;
        cout << "Boarding point : " << Boarding_point << endl;
        cout << "Droping point : " << droping_point << endl;
    }
};
class BusBookingSystem : public Bus,public Passenger{

    public :

    string date;
    void journeyinfo(){
        cout << "----------------------------------------" << endl;
        cout << "Enter Boarding point and Droping point details" << endl;
        cout << "----------------------------------------" << endl;

        cout << "From : ";
        cin >> Boarding_point;
        cout << "To : ";
        cin >> droping_point;
        cout << "----------------------------------------" << endl;

        cout << "Enter date : ";
        cin >> date;

    }

    
    void busInfo(){

         bus_number = "MH14LL8961";

         cout << "Enter number of seats : ";
         cin >> numberofSeats;
        

    }
    void passengerinfo(){
        cout << "----------------------------------------" << endl;
        cout << "Enter your personal details" << endl;
        cout << "----------------------------------------" << endl;

        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter your age : ";
        cin >> age;
        cout << "Enter your phone number : ";
        cin >> phone_number;

        cout << "----------------------------------------" << endl;

    }

    

};




int main(){
    cout << "----------------------------------------" << endl;
    cout << "Wecome" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1-Book bus" << endl;
    cout << "2-See ticket" << endl;
    cout << "3-Exit" << endl;
    cout << "----------------------------------------" << endl;

    int options;

    cout << "Enter option number : ";
    cin >> options;

    switch(options){

        case 1: cout << "Book bus" << endl;
       
        break;
        
        case 2: cout << "See ticket" << endl;

        
        break;

        case 3: cout << "Exit";
        break;
        
    }

     BusBookingSystem s1;
        s1.journeyinfo();
        s1.passengerinfo();
        s1.busInfo();

        Bus b1;
        b1.features();

        Ticket t1;
        t1.printticket();


    return 0;
}
