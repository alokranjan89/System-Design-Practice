# Proxy

Proxy provides a placeholder or substitute for another object. It presents the same interface as the real object while controlling access to it or deferring expensive work.

## Roles

| Role | Responsibility |
|---|---|
| Subject | Defines the interface used by the Client |
| RealSubject | Implements the actual work |
| Proxy | Implements Subject and controls or delegates calls to RealSubject |
| Client | Uses Subject without depending on the concrete RealSubject |

The Proxy and RealSubject usually share an interface or base class. Depending on the proxy type, the proxy may check permissions, cache results, create the real object on demand, or limit network or remote calls.

## Typical code

```cpp
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

class RealImage : public Image {
public:
    void display() override {
        // Load and display the full-resolution image.
    }
};

class ImageProxy : public Image {
private:
    RealImage* realImage = nullptr;

public:
    void display() override {
        if (realImage == nullptr) {
            realImage = new RealImage();
        }
        realImage->display();
    }

    ~ImageProxy() override {
        delete realImage;
    }
};
```

This is a virtual proxy: `RealImage` is created only when `display()` is called.

## Where to use

- Use a protection proxy to check authentication or authorization before delegating a call.
- Use a virtual proxy to delay creation or loading of an expensive object.
- Use a cache proxy to store results and avoid repeated work.
- Use a remote proxy to represent an object that exists in another process or system.
- Use a logging or monitoring proxy to observe calls without changing the real implementation.

## Advantages

- Controls access to a real object.
- Avoids expensive creation or work until it is needed.
- Keeps additional concerns, such as caching or authorization, separate from the real implementation.
- Preserves the same interface as the represented object.

## Disadvantages

- Adds another object and indirection.
- Proxy behavior can make request timing or failures less obvious.
- Cache and lazy initialization require clear invalidation, lifetime, and error rules.

Proxy stands between a client and another object. Adapter changes an incompatible interface, Facade simplifies an entire subsystem, and Decorator adds behavior while preserving the interface.
