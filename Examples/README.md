# LLD Examples

This folder contains small low-level design examples. Use these after you have studied the principles and design patterns.

## Recommended Order

1. [Animal Management](AnimalManagement/README.md)
2. [Employee Management](EmployeeManagement/README.md)
3. [Bank Management](BankManagement/README.md)
4. [ATM Card](AtmCard/README.md)
5. [Vehicle Management](VehicleManagement/README.md)
6. [Library Management](LibraryManagement/README.md)
7. [Hospital Management](HospitalManagement/README.md)
8. [Parking Lot](ParkingLot/README.md)

## What To Practice

For each example, identify:

- entities/classes
- attributes
- methods
- relationships between classes
- where inheritance or abstraction is used
- what can be improved later

## How To Run

Open a folder, compile its `.cpp` file, then run the executable:

```powershell
g++ -std=c++17 -Wall -Wextra file_name.cpp -o file_name.exe
./file_name.exe
```

If a folder has more than one source file, read its README to know which one to start with.
