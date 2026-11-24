# Adapter Design Pattern

## 1. Definition

- The Adapter design pattern converts the interface of one class into the interface expected by a client.
- It allows incompatible classes to work together without changing their existing source code.
- It acts as a wrapper that translates client requests into calls understood by an existing class.
- The adapter usually uses composition and runtime polymorphism.

**Simple language:** An adapter is a translator that lets a new part of the system use an old or third-party part.

## 2. Problem It Solves

- **Problem:** A client expects interface `A`, but an existing/adapted class provides interface `B`.
- **Why needed:** Client code should not contain format conversion or vendor-specific method calls.
- **If not used:** The client becomes tightly coupled to every external API, and developers may need duplicate conversion code or modify working third-party code.

## 3. Real-World Example

A reporting service expects JSON data through `IReportProvider::getJson()`. An existing `XmlDataProvider` has only `getXml(name, id)` and cannot return JSON.

**Problem:** The report client cannot use XML directly, and changing `XmlDataProvider` is not desirable.

**Solution:** `XmlReportAdapter` implements `IReportProvider`, calls `XmlDataProvider::getXml()`, extracts the fields, and converts them into JSON. The client sees only the target interface.

## 4. Structure and Components

| Participant | Responsibility | C++ relationship |
|---|---|---|
| **Target** (`IReportProvider`) | Interface expected by the client | Abstract class |
| **Adaptee** (`XmlDataProvider`) | Existing class with an incompatible interface | Independent concrete class |
| **Adapter** (`XmlReportAdapter`) | Converts `IReportProvider` calls to `XmlDataProvider` calls | Inherits Target (IS-A); stores Adaptee (HAS-A) |
| **Client** (`ReportClient`) | Uses only the Target interface | Depends on Target, not on Adaptee |

```text
ReportClient
    |
    | uses
    v
IReportProvider  <---------------- XmlReportAdapter
  + getJson()                 IS-A          |
                                           | HAS-A
                                           v
                                      XmlDataProvider
                                      + getXml()
```

This is an object adapter. The adapter wraps an Adaptee object and delegates work to it.

## 5. C++ Implementation

The example below uses:

- an abstract **Target** interface;
- an existing **Adaptee** that returns XML;
- an **Adapter** that converts XML to JSON;
- a **Client** that depends only on the Target interface.

```cpp
#include <iostream>
#include <string>

// Target: interface expected by the client.
class IReportProvider {
public:
    virtual std::string getJson(const std::string& name,
                                const std::string& id) const = 0;
    virtual ~IReportProvider() = default;
};

// Adaptee: existing class with an incompatible interface.
class XmlDataProvider {
public:
    std::string getXml(const std::string& name,
                       const std::string& id) const {
        return "<user><name>" + name +
               "</name><id>" + id + "</id></user>";
    }
};

// Adapter: IS-A IReportProvider and HAS-A XmlDataProvider.
class XmlReportAdapter : public IReportProvider {
private:
    const XmlDataProvider& provider;

    static std::string readTag(const std::string& xml,
                               const std::string& tag) {
        const std::string open = "<" + tag + ">";
        const std::string close = "</" + tag + ">";

        const size_t start = xml.find(open);
        if (start == std::string::npos) {
            return "";
        }

        const size_t valueStart = start + open.size();
        const size_t end = xml.find(close, valueStart);
        if (end == std::string::npos) {
            return "";
        }

        return xml.substr(valueStart, end - valueStart);
    }

public:
    explicit XmlReportAdapter(const XmlDataProvider& adaptee)
        : provider(adaptee) {}

    std::string getJson(const std::string& name,
                        const std::string& id) const override {
        const std::string xml = provider.getXml(name, id);
        const std::string xmlName = readTag(xml, "name");
        const std::string xmlId = readTag(xml, "id");

        return "{\"name\":\"" + xmlName +
               "\",\"id\":\"" + xmlId + "\"}";
    }
};

// Client: depends on the Target abstraction.
class ReportClient {
public:
    void printReport(const IReportProvider& provider,
                     const std::string& name,
                     const std::string& id) const {
        std::cout << provider.getJson(name, id) << '\n';
    }
};

int main() {
    XmlDataProvider xmlProvider;
    XmlReportAdapter adapter(xmlProvider);
    ReportClient client;

    client.printReport(adapter, "Alok", "101");
}
```

**Class explanation**

- `IReportProvider` is the Target contract required by the client.
- `XmlDataProvider` is the Adaptee with XML-specific behavior.
- `XmlReportAdapter` translates the JSON request and delegates XML generation to the provider.
- `ReportClient` is decoupled from XML and uses only `IReportProvider`.

**Execution flow**

1. `main()` creates an `XmlDataProvider`.
2. `XmlReportAdapter` wraps the provider.
3. The client calls `printReport()` with the adapter.
4. Virtual dispatch calls `XmlReportAdapter::getJson()`.
5. The adapter calls `XmlDataProvider::getXml()`.
6. The adapter extracts XML fields and returns a JSON string.

**Expected output**

```text
{"name":"Alok","id":"101"}
```

**Important OOP concept:** `IReportProvider&`/pointer enables runtime polymorphism. At runtime, a virtual call uses the implementation of the actual object (`XmlReportAdapter`) rather than the base interface implementation.

## 6. Advantages

- **Reuses existing code:** No need to rewrite or modify third-party classes.
- **Reduces coupling:** Client code depends on the Target interface, not vendor-specific APIs.
- **Improves interoperability:** Makes different interfaces work together.
- **Supports separation of concerns:** Conversion logic stays inside the adapter.
- **Easy replacement:** Another provider can use another adapter with the same Target interface.

## 7. Disadvantages

- **Extra class:** Adds an adapter layer and maintenance cost.
- **Conversion overhead:** Translating data or calls may cost CPU or memory.
- **Complexity:** Multiple incompatible interfaces can require many adapters.
- **Debugging:** Call flow is indirect because the client does not call the Adaptee directly.

## 8. SOLID Principles

- **Liskov Substitution Principle (LSP):** The adapter is substitutable wherever the Target interface is accepted.
- **Open-Closed Principle (OCP):** A new Adaptee can be supported by adding an adapter, usually without changing the client.
- **Dependency Inversion Principle (DIP):** The client depends on the abstraction `IReportProvider`, not on a concrete XML or vendor class.
- **Interface Segmentation/SRP are supportive, not automatic:** They help a good adapter design, but splitting interfaces or assigning responsibilities still depends on the implementation.

## 9. When to Use / When Not to Use

**Use it when**

- Integrating legacy code or a third-party library with a different API.
- Supporting several payment, logging, database, or reporting providers behind one interface.
- Migrating an old system to a new interface while retaining old components.
- Conversion is needed but should not leak into client code.

**Do not use it when**

- The classes already have compatible interfaces.
- Direct call or a small private helper is simpler.
- The main problem is object creation; consider a Factory instead.
- The main problem is hiding a subsystem behind a simpler API; consider a Facade instead.

## 10. Common Interview Questions

**1. What is the Adapter pattern?**  
It converts one interface into another interface that a client can use.

**2. Why is an adapter needed?**  
Because existing code cannot be modified or because changing each client for each vendor API would create coupling and duplication.

**3. What is the difference between Target, Adapter, and Adaptee?**  
Target is the interface required by the client, Adapter implements that interface and translates calls, and Adaptee is the existing incompatible class.

**4. What is the difference between object and class adapters?**

- Object adapter uses composition/aggregation and is common in C++.
- Class adapter uses multiple inheritance. It combines the Target and Adaptee, but C++ multiple inheritance can add complexity.

**5. Is Adapter used only for data conversion?**  
No. It can adapt method names, parameter types, return types, ownership behavior, and other API differences.

**6. How does runtime polymorphism work here?**  
The client stores or receives an `IReportProvider*` or reference. A virtual `getJson()` call dispatches to `XmlReportAdapter::getJson()` at runtime.

**7. Adapter vs Facade?**  
Adapter reconciles one incompatible interface. Facade provides a simpler interface over a larger subsystem.

**8. Adapter vs Decorator?**  
Adapter changes or translates interface behavior. Decorator keeps the interface and adds responsibilities.

## 11. Common Mistakes

- Implementing the adapter as a client-specific function instead of a reusable interface.
- Making the client include XML/vendor details.
- Forgetting a virtual destructor in the Target base class.
- Using inheritance from the Adaptee instead of composition when object adapter behavior is intended.
- Changing the Adaptee unnecessarily when the adapter can wrap it.
- Throwing away conversion errors or returning empty values silently.
- Using an adapter even when both APIs are already compatible.
- Confusing Adapter with Decorator or Facade.

## 12. Quick Revision

- **Definition:** Adapter converts an incompatible interface into the interface expected by a client.
- **Intent:** Enable reuse and integration without changing existing code.
- **Key components:** Target, Adapter, Adaptee, and Client.
- **Relationships:** Adapter IS-A Target and HAS-A/Aggregates Adaptee.
- **Advantages:** Reuse, decoupling, interoperability, easy provider replacement.
- **Disadvantages:** Extra classes, conversion overhead, indirect call flow.
- **Interview takeaway:** The client depends on the Target abstraction; the adapter translates and delegates to the Adaptee.

## How to Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System-Design-Practice\DesignPatterns\Structural\Adapter"
g++ -std=c++17 -Wall -Wextra adapter.cpp -o adapter.exe
.\adapter.exe
```
