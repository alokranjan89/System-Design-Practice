# Hospital Management System

This example demonstrates a low-level design for a simple hospital management system.

## Requirements

- A hospital manages doctors.
- A hospital manages patients.
- A hospital manages appointments.
- A doctor can view appointments.
- A patient can book appointments.
- One doctor can treat many patients.
- One patient can consult multiple doctors.
- An appointment connects one doctor and one patient.

## Out of scope

- Billing
- Medicines
- Prescriptions
- Authentication
- Payments

## Classes

- `Person` - common base class for doctors and patients.
- `Doctor` - represents a doctor and their specialization.
- `Patient` - represents a patient and their age.
- `Appointment` - connects one doctor and one patient at a date/time.
- `Hospital` - manages doctors, patients, and appointments.

## Relationships

- `Doctor` is a `Person`.
- `Patient` is a `Person`.
- `Hospital` has many doctors.
- `Hospital` has many patients.
- `Hospital` has many appointments.
- `Appointment` connects a doctor and a patient.

## OOP concepts used

- Encapsulation: data is kept inside classes.
- Abstraction: `Person` represents common behavior.
- Inheritance: `Doctor` and `Patient` inherit from `Person`.
- Runtime polymorphism: `displayRole()` is overridden.
- Aggregation: hospital stores doctors, patients, and appointments.
- Association: appointment links a doctor and a patient.

## SOLID notes

- SRP: each class has one main responsibility.
- OCP: new person types like `Nurse` can be added later.
- LSP: `Person*` can point to `Doctor` or `Patient`.
- ISP: classes expose only methods they need.
- DIP: higher-level hospital logic works through related objects.

## Possible improvements

- Use `Doctor*` and `Patient*` inside `Appointment` instead of only IDs.
- Use a date/time class instead of plain strings.
- Add cancel appointment.
- Add search doctor.
- Add search patient.
- Add remove appointment.
- Use smart pointers for ownership.

## How to run

```powershell
cd "System Design\Examples\HospitalManagement"
g++ -std=c++17 -Wall -Wextra hospital.cpp -o hospital.exe
./hospital.exe
```
