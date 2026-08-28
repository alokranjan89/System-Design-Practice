# Adapter Design Pattern

Adapter is a structural design pattern used when existing code expects one interface, but an old class or third-party class provides a different interface.

In simple words:

> Adapter means: wrap an incompatible class and make it usable through the interface the client expects.

## Problem It Solves

Client code may expect this:

```cpp
printer->print();
```

But the existing class may provide this:

```cpp
oldPrinter.printDocument();
```

Changing the old class may be risky or impossible, especially if it is legacy code or a third-party API.

## Main Idea

Create an adapter class that implements the target interface and internally calls the old class.

```text
Client code
    calls target interface
Adapter
    translates the call
Old or third-party class
    performs the real work
```

## Files In This Folder

| File | Scenario | Target Interface | Existing Class |
|---|---|---|---|
| [Old-Printer-Integration.cpp](Old-Printer-Integration.cpp) | Old printer integration | `Printer::print()` | `OldPrinter::printDocument()` |
| [Weather-api.cpp](Weather-api.cpp) | Third-party weather API | `WeatherService::getTemp()` | `ThirdPartyWeatherAPI::fetchTemperature()` |
| [payment-gateway.cpp](payment-gateway.cpp) | Old payment gateway | `Payment::pay()` | `OldPaymentGateway::makePayment()` |
| [Legacy-Audio-Player.cpp](Legacy-Audio-Player.cpp) | Legacy audio player | `Player::play()` | `LegacyAudioPlayer::playAudio()` |

## When To Use

- existing class has useful behavior but wrong interface
- third-party API cannot be changed
- old code must work with new client code
- client code should depend on a clean abstraction

## When Not To Use

- both interfaces can be changed directly
- the mismatch is tiny and does not repeat
- adding an adapter makes the code harder to understand

## OOP Concepts Used

- abstraction: client depends on an interface such as `Printer`
- composition: adapter stores a reference to the old object
- polymorphism: client works through the target interface
- encapsulation: translation logic stays inside the adapter

## Interview Explanation

Adapter allows incompatible interfaces to work together. The client depends on a target interface, while the adapter wraps the old or third-party class and translates calls to the method that class already supports.

## Quick Revision

```text
Pattern:
Adapter

Type:
Structural Design Pattern

Intent:
Make incompatible interfaces work together.

Main Components:
1. Target interface
2. Adapter
3. Adaptee or old class
4. Client

Example:
PrinterAdapter converts Printer::print() into OldPrinter::printDocument().

Other examples in this folder use the same idea for weather, payment, and audio-player integration.

Memory:
Adapter = compatible wrapper
```

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Structural\Adapter"
g++ -std=c++17 -Wall -Wextra Old-Printer-Integration.cpp -o printer_adapter.exe
./printer_adapter.exe
```
