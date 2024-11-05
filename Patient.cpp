#include <iostream>
#include <string>

using namespace std;

class Patient {
protected:
    static int totalPatientCount; 
public:
    static int getTotalPatientCount() {
        return totalPatientCount;
    }
};


int Patient::totalPatientCount = 0;

class Inpatient : public Patient {
private:
    static int inpatientCount; 

public:
    Inpatient() {
        totalPatientCount++;
        inpatientCount++;
    }

    static int getInpatientCount() {
        return inpatientCount;
    }
};

int Inpatient::inpatientCount = 0;

class Outpatient : public Patient {
private:
    static int outpatientCount;

public:
    Outpatient() {
        totalPatientCount++;
        outpatientCount++;
    }


    static int getOutpatientCount() {
        return outpatientCount;
    }
};

int Outpatient::outpatientCount = 0;

class CriticalCarePatient : public Patient {
private:
    static int criticalCareCount; 

public:
    CriticalCarePatient() {
        totalPatientCount++;
        criticalCareCount++;
    }

    static int getCriticalCareCount() {
        return criticalCareCount;
    }
};

int CriticalCarePatient::criticalCareCount = 0;

int main() {
    int choice;
    do{
    cout << "\nPatient Management System\n";
    cout << "1. Add Inpatient\n";
    cout << "2. Add Outpatient\n";
    cout << "3. Add Critical Care Patient\n";
    cin >> choice;

    switch (choice) {
        case 1: {
            Inpatient ip;
            break;
        }
        case 2: {
            Outpatient op;
            break;
        }
        case 3: {
            CriticalCarePatient ccp;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    cout<<"Total InPatients: "<<Inpatient::getInpatientCount()<<endl;
    cout<<"Total OutPatients: "<<Outpatient::getOutpatientCount()<<endl;
    cout<<"Total Critical Care Patients: "<<CriticalCarePatient::getCriticalCareCount()<<endl;
    cout<<"Total Patients: "<<Patient::getTotalPatientCount()<<endl;

    }while(choice<4);

    return 0;
}