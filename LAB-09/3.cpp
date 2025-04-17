#include <iostream>
#include <string>
using namespace std;

class Doctor;      
class Billing;
class Receptionist;

class PatientRecord {
private:
     string name;
    int patientID;
     string dateOfBirth;

     string medicalHistory;
     string currentTreatment;
     string billingDetails;

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord (string n, int id, string dob)
        : name(n), patientID(id), dateOfBirth(dob) {}

    void getPublicData() const {
         cout << "Name: " << name << "\nID: " << patientID << "\nDOB: " << dateOfBirth << "\n";
    }

private:
    void getMedicalData() const {
         cout << "Medical History: " << medicalHistory << "\nTreatment: " << currentTreatment << "\n";
    }

    void updateMedicalHistory(const string& history) {
        medicalHistory = history;
    }

    void updateTreatment(const string& treatment) {
        currentTreatment = treatment;
    }

    void addBillingDetails(const string& billing) {
        billingDetails = billing;
    }

    void getBillingDetails() const {
         cout << "Billing Info: " << billingDetails << "\n";
    }
};

class Doctor {
public:
    void viewMedicalRecord(const PatientRecord& record) {
         cout << "\n[Doctor Accessing Medical Record]\n";
        record.getMedicalData();
    }

    void updateMedicalRecord(PatientRecord& record, const string& history, const string& treatment) {
         cout << "\n[Doctor Updating Medical Record]\n";
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
    }
};

class Billing {
public:
    void addBill(PatientRecord& record, const     string& bill) {
         cout << "\n[Billing Adding Bill]\n";
        record.addBillingDetails(bill);
    }

    void viewBill(const PatientRecord& record) {
         cout << "\n[Billing Viewing Bill]\n";
        record.getBillingDetails();
    }
};

class Receptionist {
public:
    void tryToAccess(PatientRecord& record) {
         cout << "\n[Receptionist Trying to Access Info]\n";
        record.getPublicData(); 
    }
};

int main() {
    PatientRecord patient("Sanjna", 101, "1990-05-15");

    Doctor doc;
    Billing bill;
    Receptionist recep;

    doc.updateMedicalRecord(patient, "Diabetes Type 2", "Insulin Therapy");
    doc.viewMedicalRecord(patient);

    bill.addBill(patient, "Consultation Fee: $200");
    bill.viewBill(patient);

    recep.tryToAccess(patient);

    return 0;
}
