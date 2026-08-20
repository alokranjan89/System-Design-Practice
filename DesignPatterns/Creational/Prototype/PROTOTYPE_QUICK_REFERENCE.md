# Prototype Pattern - Quick Reference Card

## 🎯 Pattern at a Glance
```
WHAT: Create objects by cloning existing prototypes
WHY: Cloning is faster than expensive object creation
WHEN: Object initialization is expensive or complex
HOW: Implement clone() using copy constructor
```

---

## 💡 Key Concepts

| Concept | Meaning |
|---------|---------|
| **Prototype** | Template object to be cloned |
| **Clone** | Create copy instead of new object |
| **Shallow Copy** | Copy pointers (not data) |
| **Deep Copy** | Copy pointers AND data |
| **Polymorphic Clone** | Clone through base class pointer |

---

## 📊 Shallow vs Deep Copy

```
SHALLOW COPY:
┌──────────┐     ┌──────────┐
│ Original │     │   Clone  │
├─ ptr ───┬┘     ├─ ptr ───┬┘
│         │      │         │
│    ┌────┴──────┴────┐     │
│    │   SHARED DATA  │◄────┘
│    └────────────────┘
│
✗ Problem: Modifying data affects both
✓ Solution: Use when fields are safe

DEEP COPY:
┌──────────┐                ┌──────────┐
│ Original │                │   Clone  │
├─ ptr ───┬┘                ├─ ptr ───┬┘
│         │                 │         │
│    ┌────┴───┐              │    ┌───┴────┐
│    │ DATA 1 │◄──────┐      │    │ DATA 2 │
│    └────────┘       │      │    └────────┘
│                     │      │
│  Original owns      │  Clone owns its own copy
```

---

## 💻 Code Pattern

```cpp
// Interface
class Cloneable {
public:
    virtual Cloneable* clone() const = 0;
    virtual ~Cloneable() {}
};

// Concrete Prototype
class NPC : public Cloneable {
private:
    string name;
    int health;
    
public:
    // Expensive constructor
    NPC(const string& name, int health) { }
    
    // Copy constructor (cheap)
    NPC(const NPC& other) { }
    
    // Clone method
    Cloneable* clone() const override {
        return new NPC(*this);
    }
};

// Usage
NPC* template = new NPC("Alien", 30);
NPC* clone1 = (NPC*)template->clone();  // Cheap!
NPC* clone2 = (NPC*)template->clone();  // Cheap!
```

---

## ✅ When to Use

- ✓ Object creation is expensive (DB, network, calculations)
- ✓ Need to create similar objects repeatedly
- ✓ Object types unknown at compile time
- ✓ Need independent customizable copies
- ✓ Performance is critical

## ❌ When NOT to Use

- ✗ Simple objects (no performance benefit)
- ✗ Deep copy is complex (many pointer levels)
- ✗ Objects change frequently
- ✗ Memory overhead not justified

---

## 🔄 Shallow Copy Implementation

```cpp
// Good for: Primitives + managed types (string)
NPC(const NPC& other) {
    name = other.name;      // string deep copies itself
    health = other.health;  // primitive copy
}
```

---

## 🔒 Deep Copy Implementation

```cpp
// Required for: Pointers to mutable data
class Game {
private:
    int* data;
    
public:
    Game(const Game& other) {
        if (other.data) {
            data = new int[size];
            memcpy(data, other.data, size);  // Deep copy
        }
    }
};
```

---

## 📈 Performance Comparison

| Operation | Expensive Constructor | Copy Constructor |
|-----------|----------------------|------------------|
| Database calls | Yes | No |
| Calculations | Yes | No |
| File I/O | Yes | No |
| Memory alloc | Yes | Yes (small) |
| **Time** | 1000ms | 1ms |

**Prototype is 1000x faster for expensive objects!**

---

## 🎓 Interview Q&A

| Q | A |
|---|---|
| What is Prototype? | Clone existing objects instead of creating from scratch |
| Shallow vs Deep? | Shallow: Copy pointers; Deep: Copy data too |
| When use Prototype? | Expensive object creation (DB, network) |
| Prototype vs Factory? | Factory creates, Prototype copies |
| How polymorphic clone? | Return base class pointer from clone() |
| Memory management? | clone() allocates with new, client deletes |

---

## 🐛 Common Mistakes

❌ **Forgetting to implement clone()**
```cpp
class NPC { /* no clone() */ };  // Can't be cloned!
```

✓ **Implement clone() with copy constructor**
```cpp
class NPC {
    Cloneable* clone() const override {
        return new NPC(*this);
    }
};
```

---

❌ **Shallow copy when deep needed**
```cpp
NPC(const NPC& other) {
    pData = other.pData;  // Shares memory!
}
```

✓ **Deep copy for pointers**
```cpp
NPC(const NPC& other) {
    pData = new Data(*other.pData);  // Independent copy
}
```

---

## 🚀 Real-World Examples

1. **Game Development** - Clone enemy templates for levels
2. **Document Systems** - Clone templates for new documents
3. **Configuration** - Clone default config and customize
4. **UI Components** - Clone button/widget templates
5. **Database** - Clone table schemas for new tables
6. **Caching** - Clone cached objects for distribution
7. **History/Undo** - Clone state snapshots

---

## ⏱️ Time Complexity

- Constructor: **O(n)** where n = complex operations
- Clone (copy constructor): **O(k)** where k = data size (usually O(1))
- **Speedup: 1000x+ for expensive objects**

---

## 📊 Comparison with Other Patterns

```
PROTOTYPE: How to copy objects (cheap cloning)
FACTORY: What objects to create
BUILDER: How to build single object
SINGLETON: One instance only

Use Prototype for: Fast repeated object creation
Use Factory for: Choosing which type to create
Use Builder for: Complex step-by-step creation
Use Singleton for: Single shared instance
```

---

## ✓ Revision Checklist

- [ ] Understand expensive vs cheap creation
- [ ] Know shallow vs deep copy
- [ ] Can implement clone() method
- [ ] Understand copy constructor role
- [ ] Know polymorphic cloning
- [ ] Can choose shallow or deep copy
- [ ] Know when to use Prototype
- [ ] Understand prototype vs other patterns
- [ ] Can answer interview questions

---

**Status:** Ready for Interview ✓  
**Complexity:** Intermediate  
**Usage:** Very Common in Practice
