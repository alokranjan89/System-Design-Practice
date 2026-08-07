# Hospital Management System (LLD)

## Problem Statement

Design a Hospital Management System.

### Requirements

- A hospital manages doctors.
- A hospital manages patients.
- A hospital manages appointments.
- A doctor can view appointments.
- A patient can book appointments.
- One doctor can treat many patients.
- One patient can consult multiple doctors.
- An appointment connects one doctor and one patient.

---

# Clarifying Questions

### Q1. Can one doctor treat multiple patients?

✅ Yes.

---

### Q2. Can one patient consult multiple doctors?

✅ Yes.

---

### Q3. Can a patient book multiple appointments?

✅ Yes.

---

### Q4. Can a doctor have multiple appointments?

✅ Yes.

---

### Q5. Can an appointment exist without a doctor and patient?

❌ No.

---

### Q6. Are billing, medicines and prescriptions included?

❌ No.

---

# Classes

1. Person
2. Doctor
3. Patient
4. Appointment
5. Hospital

---

# Inheritance

```
             Person
                ▲
        ┌───────┴────────┐
        │                │
     Doctor          Patient
```

Reason:

Doctor IS-A Person

Patient IS-A Person

---

# Relationships

## 1. Hospital ↔ Doctor

Relationship:

Aggregation

Reason:

- Hospital has Doctors.
- Doctor can exist without Hospital.

---

## 2. Hospital ↔ Patient

Relationship:

Aggregation

Reason:

- Hospital has Patients.
- Patient can exist without Hospital.

---

## 3. Hospital ↔ Appointment

Relationship:

Aggregation

Reason:

Hospital stores appointments.

Appointments are managed by Hospital.

---

## 4. Doctor ↔ Appointment

Relationship:

Association

Reason:

Doctor is associated with multiple appointments.

Appointment connects Doctor and Patient.

---

## 5. Patient ↔ Appointment

Relationship:

Association

Reason:

Patient books appointments.

Appointment connects Patient and Doctor.

---

# UML Diagram

```
                               +-----------------------------+
                               |          Person             |
                               +-----------------------------+
                               | - id : int                 |
                               | - name : string            |
                               +-----------------------------+
                               | + displayRole()            |
                               +-----------------------------+
                                         ▲
                         ┌───────────────┴────────────────┐
                         │                                │
       +-------------------------------+  +-------------------------------+
       |            Doctor             |  |           Patient            |
       +-------------------------------+  +-------------------------------+
       | - specialization : string     |  | - age : int                  |
       +-------------------------------+  +-------------------------------+
       | + viewAppointment()           |  | + bookAppointment()           |
       | + displayRole()               |  | + displayRole()               |
       +-------------------------------+  +-------------------------------+

Doctor ------------------------- Appointment ----------------------- Patient

Hospital <>---------------- Doctor
Hospital <>---------------- Patient
Hospital <>---------------- Appointment


       +------------------------------------------------+
       |               Appointment                      |
       +------------------------------------------------+
       | appointmentId                                  |
       | doctorId                                       |
       | patientId                                      |
       | date                                           |
       | time                                           |
       +------------------------------------------------+
       | displayAppointment()                           |
       +------------------------------------------------+

       +------------------------------------------------+
       |                 Hospital                       |
       +------------------------------------------------+
       | hospitalName                                   |
       | vector<Doctor*> doctors                        |
       | vector<Patient*> patients                      |
       | vector<Appointment*> appointments              |
       +------------------------------------------------+
       | addDoctor()                                    |
       | addPatient()                                   |
       | addAppointment()                               |
       | showDoctors()                                  |
       | showPatients()                                 |
       | showAppointments()                             |
       +------------------------------------------------+
```

---

# Coding Order

```
Person
    ↓
Doctor
    ↓
Patient
    ↓
Appointment
    ↓
Hospital
    ↓
main()
```

---

# Class Responsibilities

## Person

Attributes

- id
- name

Methods

- displayRole()

Purpose

Base class for Doctor and Patient.

---

## Doctor

Attributes

- specialization

Methods

- displayRole()
- viewAppointment()

Purpose

Represents a doctor.

---

## Patient

Attributes

- age

Methods

- displayRole()
- bookAppointment()

Purpose

Represents a patient.

---

## Appointment

Attributes

- appointmentId
- doctorId
- patientId
- date
- time

Methods

- displayAppointment()

Purpose

Represents an appointment between one doctor and one patient.

---

## Hospital

Attributes

- hospitalName
- doctors
- patients
- appointments

Methods

- addDoctor()
- addPatient()
- addAppointment()
- showDoctors()
- showPatients()
- showAppointments()

Purpose

Manages the whole hospital.

---

# OOP Concepts Used

## Encapsulation

```
private:
```

Data is hidden inside classes.

---

## Abstraction

```
Person
```

Represents common information.

Cannot instantiate directly.

---

## Inheritance

```
Doctor : Person

Patient : Person
```

---

## Runtime Polymorphism

```
virtual displayRole()

override
```

---

# SOLID Principles

## SRP

Each class has one responsibility.

- Doctor → Doctor operations
- Patient → Patient operations
- Appointment → Appointment information
- Hospital → Management

---

## OCP

New class like

```
Nurse
```

can inherit from

```
Person
```

without modifying existing classes.

---

## LSP

```
Person*
```

can point to

```
Doctor

Patient
```

---

## ISP

Classes only implement methods they require.

Doctor doesn't implement

```
bookAppointment()
```

Patient doesn't implement

```
viewAppointment()
```

---

## DIP

Hospital depends on

```
Doctor*
Patient*
Appointment*
```

instead of concrete objects.

---

# Phase 2 Improvements

Instead of

```
doctorId
patientId
```

use

```
Doctor* doctor;

Patient* patient;
```

Reason:

Objects should interact with objects.

---

Instead of

```
string date
```

Use

```
std::chrono
```

or a Date class.

---

Add

- Cancel Appointment
- Search Doctor
- Search Patient
- Remove Appointment

---

# Interview Questions

### Why Person?

To remove duplicate code.

---

### Why Aggregation?

Doctor and Patient can exist without Hospital.

---

### Why Association?

Appointment represents the relationship between Doctor and Patient.

---

### Why virtual destructor?

To ensure proper cleanup when deleting through a Person pointer.

---

### Why displayRole() is pure virtual?

Person is abstract.

Only Doctor and Patient should be instantiated.

---

# Time Complexity

| Method | Complexity |
|---------|------------|
| addDoctor() | O(1) |
| addPatient() | O(1) |
| addAppointment() | O(1) |
| showDoctors() | O(n) |
| showPatients() | O(n) |
| showAppointments() | O(n) |

---

# Overall Learning

✅ Encapsulation

✅ Abstraction

✅ Inheritance

✅ Polymorphism

✅ Aggregation

✅ Association

✅ UML

✅ SOLID

✅ Constructor Chaining

✅ Initializer List
