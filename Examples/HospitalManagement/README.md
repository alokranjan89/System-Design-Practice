# Hospital Management Exercise

A small LLD exercise for registering doctors and patients and connecting them through appointments. It does not model billing, prescriptions, medicines, authentication, or payments.

## Model

- `Person` is the common base class for `Doctor` and `Patient`.
- `Appointment` connects one doctor and one patient at a date and time.
- `Hospital` manages doctors, patients, and appointments.

Trace the booking flow in [`hospital.cpp`](hospital.cpp). Check how the example represents dates and object relationships; these are simplified teaching choices, not a complete hospital domain model.

## Build

From the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra Examples/HospitalManagement/hospital.cpp -o hospital.exe
.\hospital.exe
```
