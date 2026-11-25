# Adapter

Adapter lets a client use an existing class whose interface does not match what the client expects. The adapter implements the expected interface, translates the call, and delegates to the existing class.

## Roles

| Role | Responsibility |
|---|---|
| Target | Interface the client expects |
| Adaptee | Existing class with the incompatible interface |
| Adapter | Implements Target and delegates translated work to Adaptee |
| Client | Depends on Target rather than the Adaptee |

In the object-adapter approach used here, the adapter **has** an Adaptee and **is** a Target. This keeps vendor-specific calls and conversions out of client code.

## Examples

- [`adapter.cpp`](adapter.cpp): adapts an XML provider to a JSON report interface. `ReportClient` calls the Target; `XmlReportAdapter` delegates to `XmlDataProvider`.
- [`payment.cpp`](payment.cpp): adapts `RazorPay::makePayment()` to the `IPayment::pay()` interface.

Trace each example from `main()` and identify the Target, Adapter, Adaptee, and Client. The first example also prints the adapted result.

## When it helps

Use Adapter when integrating legacy or third-party code, or when multiple implementations need to fit one client interface. Skip it if the interfaces already match and a direct call is clear. Adapter translates an interface; Facade simplifies access to a subsystem, and Decorator keeps the interface while adding behavior.

## Build

Run from this directory, compiling one example at a time:

```powershell
g++ -std=c++17 -Wall -Wextra adapter.cpp -o adapter.exe
.\adapter.exe
```

Replace `adapter.cpp` with `payment.cpp` to run the payment example.
