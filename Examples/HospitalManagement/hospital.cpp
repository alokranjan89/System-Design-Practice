#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    Person(int id, string name)
        : id(id), name(name)
    {
    }

    virtual void displayRole() = 0;

    virtual ~Person() = default;
};

class Doctor : public Person
{
private:
    string specialization;

public:
    Doctor(int id, string name, string specialization)
        : Person(id, name), specialization(specialization)
    {
    }
    void displayRole() override
    {
        cout << "Role : Doctor" << endl;
    }

    void viewAppointment()
    {
        cout << name << "is Viewing Appointment" << endl;
    }
};

class Patient : public Person
{
private:
    int age;

public:
    Patient(int id, string name, int age)
        : Person(id, name), age(age)
    {
    }

    void displayRole() override
    {
        cout << "Role : Patient" << endl;
    }

    void bookAppointment()
    {
        cout << name << " is booking an appointment." << endl;
    }
};

class Appointment
{
private:
    int appointmentId;
    int doctorId;
    int patientId;
    string date;
    string time;

public:
    Appointment(int appointmentId,
                int doctorId,
                int patientId,
                string date,
                string time)
        : appointmentId(appointmentId),
          doctorId(doctorId),
          patientId(patientId),
          date(date),
          time(time)
    {
    }

    void displayAppointment()
    {
        cout << "Appointment ID : " << appointmentId << endl;
        cout << "Doctor ID      : " << doctorId << endl;
        cout << "Patient ID     : " << patientId << endl;
        cout << "Date           : " << date << endl;
        cout << "Time           : " << time << endl;
    }
};

class Hospital
{
private:
    string hospitalName;

    vector<Doctor *> doctors;
    vector<Patient *> patients;
    vector<Appointment *> appointments;

public:
    Hospital(string hospitalName)
        : hospitalName(hospitalName)
    {
    }

    void addDoctor(Doctor *doctor)
    {
        doctors.push_back(doctor);
    }

    void addPatient(Patient *patient)
    {
        patients.push_back(patient);
    }

    void addAppointment(Appointment *appointment)
    {
        appointments.push_back(appointment);
    }

    void showDoctors()
    {
        for (Doctor *doctor : doctors)
        {
            doctor->displayRole();
        }
    }

    void showPatients()
    {
        for (Patient *patient : patients)
        {
            patient->displayRole();
        }
    }

    void showAppointments()
    {
        for (Appointment *appointment : appointments)
        {
            appointment->displayAppointment();
        }
    }
};

int main()
{
    // Create Hospital
    Hospital hospital("City Hospital");

    // Create Doctors
    Doctor* doctor1 = new Doctor(101, "Dr. Sharma", "Cardiologist");
    Doctor* doctor2 = new Doctor(102, "Dr. Mehta", "Neurologist");

    // Create Patients
    Patient* patient1 = new Patient(201, "Alok", 22);
    Patient* patient2 = new Patient(202, "Rahul", 25);

    // Create Appointments
    Appointment* appointment1 =
        new Appointment(1, 101, 201, "08-08-2026", "10:00 AM");

    Appointment* appointment2 =
        new Appointment(2, 102, 202, "08-08-2026", "11:30 AM");

    // Add Doctors
    hospital.addDoctor(doctor1);
    hospital.addDoctor(doctor2);

    // Add Patients
    hospital.addPatient(patient1);
    hospital.addPatient(patient2);

    // Add Appointments
    hospital.addAppointment(appointment1);
    hospital.addAppointment(appointment2);

    cout << "\n========== Doctors ==========\n";
    hospital.showDoctors();

    cout << "\n========== Patients ==========\n";
    hospital.showPatients();

    cout << "\n========== Appointments ==========\n";
    hospital.showAppointments();

    cout << "\n========== Operations ==========\n";

    doctor1->viewAppointment();

    patient1->bookAppointment();

    return 0;
}