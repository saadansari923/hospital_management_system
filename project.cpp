#include<iostream>
#include<string>
#include<vector>
using namespace std;


////////////////////////////////////
// Person Class
////////////////////////////////////
class Person{
    protected:
        string name, address, phone;
        int age;
        string gender;
    public:
    Person(){
        name = "";
        age = 0;
        gender = "";
        address = "";
        phone = "";
    }
    Person(string n, int a, string g, string addr, string ph){
        name = n;
        age = a;
        gender = g;
        address = addr;
        phone = ph;
    }

    //getters
    string getName(){return name;}
    int getAge(){return age;}
    string getGender(){return gender;}
    string getAddress(){return address;}
    string getPhone(){return phone;}
    //setters
    void setName(string n){name = n;}
    void setAge(int a){age = a;}
    void setGender(string g){gender = g;}
    void setAddress(string addr){address = addr;}
    void setPhone(string ph){phone = ph;}

        void displayInfo(){
            cout << "--Information--" << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
        }
};


////////////////////////////////////
// Patient Class
////////////////////////////////////

class Patient: public Person {
    private:
        string disease, admitDate, dischargeDate;
        int patientId,roomNumber;
        bool isAdmitted;
    public:

        Patient() : Person(){
            patientId = 0;
            disease = "";
            admitDate = "";
            dischargeDate = "";
            roomNumber = -1;
            isAdmitted = false;
        }
        Patient(int id, string n, int a, string g, string addr, string ph, 
        string dis, string adDate, int roomNo)
        : Person(n, a, g, addr, ph){
            patientId = id;
            disease = dis;
            admitDate = adDate;
            roomNumber = roomNo;
            isAdmitted = true;
        }
        int getPatientId(){return patientId;}
        bool getStatus(){return isAdmitted;}
        int getRoomNo(){return roomNumber;}

        void dischargePatient(string disDate){
            dischargeDate = disDate;
            isAdmitted = false;
            cout << "Patient " << getName() << " discharge on " << disDate << endl;
        }
        void viewPatientDetails(){
            cout << "\n--- Patient Details ---\n";
            displayInfo();
            cout << "Patient ID: " << patientId << endl; 
            cout << "Disease: " << disease << endl; 
            cout << "Admit Date: " << admitDate << endl;
            if(!isAdmitted) cout << "Discharge Date: " << dischargeDate << endl;
            cout << "Room No: " << roomNumber << endl; 
            cout << "Status: " << (isAdmitted ? "Admitted" : "Discharged")  << endl; 
        }
};


////////////////////////////////////
// Doctor Class
////////////////////////////////////

class Doctor: public Person {
    private:
        int doctorId;
        string specialization;
        double salary;
        bool available;
    public:
        Doctor() : Person (){
            doctorId = 0;
            specialization = "";
            salary = 0.0;
            available = true;
        }
        Doctor(int id, string n, int a, string g, string addr, string ph,
           string spec, double sal, bool avail) : Person(n, a, g, addr, ph){
            doctorId = id;
            specialization = spec;
            salary = sal;
            available = avail;
           }
           int getDoctorId(){return doctorId;}
           string getSpecializition(){return specialization;}
           bool isAvailable(){return available;}
        void assignPatient(int patientId){
            if(available){
                cout << "Doctor " << getName() << " is assigned to Patient ID " << patientId << endl;
            available = false; 
            } else {
                cout << "Doctor " << getName() << " is currently not available." << endl;
            }
        }
        void setAvailability(bool avail){available = avail;}
        void viewDoctorDetails(){
            cout << "\n--- Doctor Details ---\n";
        displayInfo();
        cout << "Doctor ID: " << doctorId << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Salary: " << salary << endl;
        cout << "Availability: " << (available ? "Available" : "Busy") << endl;
        }
};

////////////////////////////////////
// Room Class
////////////////////////////////////

class Room {
    private:
        int roomNumber;
        string roomType;
        bool isAvailable;
    public:
    Room(int no = 0, string type = "General"){
        roomNumber = no;
        roomType = type;
        isAvailable = true;
    }

    int getRoomNo(){return roomNumber;}
    bool getAvailability(){return isAvailable;}

        void allocateRoom(){
            if(isAvailable){
                isAvailable = false;
                cout << "Room " << roomNumber << " allocated." << endl;
            } else {
                cout << "Room " << roomNumber << " already occupied." << endl;
            }
        }
        void freeRoom(){
            isAvailable = true;
            cout << "Room " << roomNumber << " is now free." << endl;
        }
        void viewRoomDetails(){
            cout << "\n--- Room Details ---\n";
            cout << "Room Number: " << roomNumber << endl;
            cout << "Type: " << roomType << endl;
            cout << "Status: " << (isAvailable ? "Available" : "Occupied") << endl;
        }
};


////////////////////////////////////
// Hospital Class (Manager)
////////////////////////////////////

class Hospital{
    private:
        vector<Patient> patients;  //create object of vector
        vector<Doctor> doctors;
        vector<Room> rooms;
    public:
        void addPatient(Patient p){  //create object of Patient Class
            patients.push_back(p);
            cout << "Patient added successfully." << endl;
        }
        void addDoctor(Doctor d){
            doctors.push_back(d);
            cout << "Doctor added successfully." << endl;
        }
        void addRoom(Room r){
            rooms.push_back(r);
            cout << "Room added successfully." << endl;
        }
        void showAllPatients(){
            for(auto &p : patients){
                p.viewPatientDetails();
            }
        }
        void showAllDoctors(){
            for(auto &d : doctors){
                d.viewDoctorDetails();
            }
        }
        void showAllRooms(){
            for(auto &r : rooms){
                r.viewRoomDetails();
            }
        }

};



////////////////////////////////////
// Main Menu
////////////////////////////////////


int main(){
    Hospital h;

    int choice;
    do{
        cout << "\n===== Hospital Management System =====\n" ;
        cout << "1. Add Patient\n";
        cout << "2. Add Doctor\n";
        cout << "3. Add Room\n";
        cout << "4. Show All Patients\n";
        cout << "5. Show All Doctors\n";
        cout << "6. Show All Rooms\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        if(choice == 1){
            int id, age, roomNo;
            string n, g, addr, ph, dis, adDate;
            cout << "Enter Patient Id: "; cin >> id;
            cout << "Enter Name: "; cin >> n;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Gender: "; cin >> g;
            cout << "Enter Address: "; cin >> addr;
            cout << "Enter Phone: "; cin >> ph;
            cout << "Enter Disease: "; cin >> dis;
            cout << "Enter Admit Date: "; cin >> adDate;
            cout << "Enter Room Number: "; cin >> roomNo;

            Patient p(id, n, age, g, addr, ph, dis, adDate, roomNo);
            h.addPatient(p);
        } else if(choice == 2){
            int id, age;
            string n, g, addr, ph, spec;
            double sal;
            cout << "Enter Doctor Id: "; cin >> id;
            cout << "Enter Name: "; cin >> n;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Gender: "; cin >> g;
            cout << "Enter Address: "; cin >> addr;
            cout << "Enter Phone: "; cin >> ph;
            cout << "Enter Specialization: "; cin >> spec;
            cout << "Enter Salary: "; cin >> sal;

            Doctor d(id, n, age, g, addr, ph, spec, sal, true);
            h.addDoctor(d);
        } else if(choice == 3){
            int no;
            string type;
            cout << "Enter Room Number: "; cin >> no;
            cout << "Enter Room Type: "; cin >> type;
            Room r(no, type);
            h.addRoom(r);
        } else if(choice == 4){
            h.showAllPatients();
        } else if(choice == 5){
            h.showAllDoctors();
        } else if(choice == 6){
            h.showAllRooms();
        }
    } while (choice != 7);
    cout << "Exiting System... Good Bye\n";
    
    return 0;
}