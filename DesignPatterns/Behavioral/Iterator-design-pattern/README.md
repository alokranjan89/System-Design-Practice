# Iterator Design Pattern

## 📋 Table of Contents
1. [Definition](#definition)
2. [Problem Statement](#problem-statement)
3. [Solution](#solution)
4. [Key Components](#key-components)
5. [Advantages & Disadvantages](#advantages--disadvantages)
6. [Implementation Details](#implementation-details)
7. [Real-World Examples](#real-world-examples)
8. [Use Cases](#use-cases)
9. [When to Use](#when-to-use)
10. [Related Patterns](#related-patterns)

---

## Definition

The **Iterator Design Pattern** is a Behavioral Design Pattern that provides a way to access elements of a collection sequentially without exposing its underlying representation.

It defines an interface for creating an object that traverses through the elements in a collection in a sequential manner, without needing to know the internal structure of the collection.

---

## Problem Statement

### Challenges Without Iterator Pattern:

1. **Tight Coupling**: Direct access to collection internals creates tight coupling between client code and collection implementation.

2. **Multiple Ways to Traverse**: Different collections may have different internal structures (array, linked list, tree, etc.), requiring different traversal logic.

3. **Code Duplication**: Clients need to implement traversal logic for each type of collection.

4. **Breaking Encapsulation**: Exposing collection internals compromises encapsulation.

5. **Complexity**: Managing index/pointer manually for each collection type is error-prone and complex.

### Example Problem:
```cpp
// Without Iterator - Tightly Coupled
for(int i = 0; i < books.size(); i++) {
    cout << books[i] << endl;
}
// What if we need to traverse differently?
// What if the internal structure changes?
```

---

## Solution

The Iterator Pattern solves this by:

1. **Defining an Iterator Interface**: Abstract interface for iteration operations.

2. **Creating Concrete Iterators**: Specific implementations for different collection types.

3. **Encapsulating Traversal Logic**: Hides the internal representation and traversal details.

4. **Separating Concerns**: Collection and iteration logic are separated.

5. **Providing Uniform Access**: Single way to access elements regardless of collection type.

---

## Key Components

### 1. **Iterator Interface (Abstract Iterator)**
```cpp
class Iterator {
public:
    virtual bool hasNext() = 0;      // Check if more elements exist
    virtual string next() = 0;        // Get next element
    virtual ~Iterator() {}
};
```
- Declares methods for traversal
- Provides contract for concrete iterators

### 2. **Concrete Iterator**
```cpp
class BookIterator : public Iterator {
private:
    BookCollection& collection;
    int index;
    
public:
    BookIterator(BookCollection& collection)
        : collection(collection), index(0) {}
    
    bool hasNext() override {
        return index < collection.size();
    }
    
    string next() override {
        return collection.getBook(index++);
    }
};
```
- Implements the Iterator interface
- Maintains traversal state (index)
- Knows how to traverse specific collection

### 3. **Collection Interface (Abstract)**
```cpp
class Collection {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Collection() {}
};
```
- Defines interface for creating iterators

### 4. **Concrete Collection**
```cpp
class BookCollection {
private:
    vector<string> books;
    
public:
    void addBook(string book) {
        books.push_back(book);
    }
    
    string getBook(int index) {
        return books[index];
    }
    
    int size() {
        return books.size();
    }
};
```
- Stores actual data
- Provides methods to access elements by index

---

## Class Diagram

```
┌─────────────────────────┐
│     <<interface>>       │
│      Iterator          │
├─────────────────────────┤
│ + hasNext(): bool       │
│ + next(): Element       │
└─────────────────────────┘
         ▲
         │
         │
┌─────────────────────────┐
│  BookIterator           │
├─────────────────────────┤
│ - collection: BookColl  │
│ - index: int            │
├─────────────────────────┤
│ + hasNext(): bool       │
│ + next(): string        │
└─────────────────────────┘

┌──────────────────────────┐
│ BookCollection           │
├──────────────────────────┤
│ - books: vector<string>  │
├──────────────────────────┤
│ + addBook(book)          │
│ + getBook(index)         │
│ + size()                 │
└──────────────────────────┘
```

---

## Advantages & Disadvantages

### ✅ Advantages

1. **Encapsulation**: Collection internals are hidden from clients.
   - Reduces coupling between client and collection

2. **Uniform Interface**: Same interface for iterating different collections.
   - Cleaner, more maintainable code

3. **Single Responsibility**: Each class has one clear responsibility.
   - Iterator handles traversal logic
   - Collection handles data storage

4. **Flexibility**: Easy to add new collection types.
   - Just create a new concrete iterator

5. **Abstraction**: Decouples algorithm from object structure.
   - Changes to internal structure don't affect client code

6. **Multiple Iterators**: Can have multiple iterators on same collection.
   - Independent traversal of same data

### ❌ Disadvantages

1. **Overhead**: Additional classes and memory for simple collections.
   - May be overkill for small collections

2. **Complexity**: More code to write and maintain.
   - Extra abstraction layers

3. **Performance**: Small performance overhead compared to direct access.
   - Extra method calls for each element

4. **Thread Safety**: Iterators are not thread-safe by default.
   - Concurrent modification issues

---

## Implementation Details

### Method Breakdown:

#### **hasNext()**
- **Purpose**: Check if there are more elements to traverse
- **Returns**: `true` if more elements exist, `false` otherwise
- **Usage**: Loop condition control

```cpp
bool hasNext() override {
    return index < collection.size();
}
```

#### **next()**
- **Purpose**: Return the next element and advance the iterator
- **Returns**: Next element in the sequence
- **Usage**: Get current element and move to next

```cpp
string next() override {
    return collection.getBook(index++);  // Post-increment
}
```

### Traversal Pattern:
```cpp
while(iterator.hasNext()) {
    cout << iterator.next() << endl;
}
```

1. Check if more elements exist: `hasNext()`
2. Get next element: `next()`
3. Process element
4. Repeat

---

## Real-World Examples

### 1. **STL Iterators (C++)**
```cpp
vector<int> vec = {1, 2, 3, 4, 5};

for(auto it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << endl;
}
```

### 2. **Java Collections**
```java
List<String> list = new ArrayList<>();
Iterator<String> iterator = list.iterator();

while(iterator.hasNext()) {
    System.out.println(iterator.next());
}
```

### 3. **File System Traversal**
```cpp
// Iterator through files in directory
DirectoryIterator iterator(folder);
while(iterator.hasNext()) {
    File file = iterator.next();
    process(file);
}
```

### 4. **Database Query Results**
```cpp
// Iterator through database records
ResultIterator results = database.query("SELECT * FROM users");
while(results.hasNext()) {
    Record record = results.next();
    processRecord(record);
}
```

### 5. **GUI Components**
```cpp
// Iterator through UI elements
ComponentIterator iterator(container);
while(iterator.hasNext()) {
    Component comp = iterator.next();
    render(comp);
}
```

---

## Use Cases

### 1. **Collection Access**
   - Accessing elements in arrays, lists, sets
   - Traversing data structures

### 2. **Aggregation Objects**
   - Objects that contain other objects
   - Composite structures

### 3. **Multiple Traversal Algorithms**
   - Forward iteration
   - Reverse iteration
   - Level-order traversal
   - Depth-first traversal

### 4. **Uniform Interface**
   - Different collection types (array, linked list, tree)
   - Same traversal interface

### 5. **Menu Systems**
   - Traversing menu items
   - File browsers

### 6. **Database Operations**
   - Iterating through query results
   - Cursor operations

### 7. **Streaming Data**
   - Processing elements one by one
   - Memory-efficient processing

---

## When to Use

### ✓ Use Iterator When:

1. **Multiple Collection Types**: Need to traverse different data structures uniformly.
   ```cpp
   // Same code works for array, list, tree
   while(iterator.hasNext()) {
       process(iterator.next());
   }
   ```

2. **Hidden Internal Structure**: Don't want to expose collection internals.
   ```cpp
   // Clients don't know about index, pointer, or recursion
   ```

3. **Sequential Access**: Need to access elements sequentially.
   ```cpp
   // One element at a time, in order
   ```

4. **Multiple Simultaneous Iterations**: Need multiple independent iterators.
   ```cpp
   BookIterator iter1(collection);
   BookIterator iter2(collection);
   // Both can traverse independently
   ```

5. **Separate Traversal Logic**: Want to decouple traversal from collection.
   ```cpp
   // Collection doesn't know how it's traversed
   ```

### ✗ Don't Use When:

1. **Simple Collections**: Small collections where overhead isn't justified.
2. **Random Access**: Need quick random access to elements.
3. **Simple Code**: Overkill for straightforward problems.
4. **Performance Critical**: Can't afford extra method call overhead.

---

## Iterator Types

### 1. **Bidirectional Iterator**
- Can traverse forward and backward
- Methods: `next()`, `previous()`, `hasNext()`, `hasPrevious()`

```cpp
class BidirectionalIterator {
public:
    virtual bool hasNext() = 0;
    virtual bool hasPrevious() = 0;
    virtual string next() = 0;
    virtual string previous() = 0;
};
```

### 2. **Filtering Iterator**
- Only returns elements matching a condition

```cpp
class FilteringIterator {
private:
    Iterator* wrapped;
    bool (*predicate)(string);
    
public:
    string next() override {
        while(wrapped->hasNext()) {
            string element = wrapped->next();
            if(predicate(element)) return element;
        }
    }
};
```

### 3. **Lazy Iterator**
- Computes elements on demand
- Useful for large/infinite sequences

```cpp
class LazyIterator {
public:
    string next() override {
        // Compute element only when requested
        return generateNextElement();
    }
};
```

---

## Code Example Walkthrough

```cpp
// 1. Create collection
BookCollection collection;

// 2. Add elements
collection.addBook("C++");
collection.addBook("Java");
collection.addBook("Python");

// 3. Create iterator
BookIterator iterator(collection);

// 4. Traverse using iterator
while(iterator.hasNext()) {
    cout << iterator.next() << endl;
}

/* Output:
C++
Java
Python
*/
```

### Step-by-Step:

| Step | Action | State |
|------|--------|-------|
| 1 | Create BookCollection | books = [] |
| 2 | addBook("C++") | books = ["C++"] |
| 3 | addBook("Java") | books = ["C++", "Java"] |
| 4 | addBook("Python") | books = ["C++", "Java", "Python"] |
| 5 | Create BookIterator | index = 0 |
| 6 | hasNext() → true | index = 0, size = 3 |
| 7 | next() → "C++" | index = 1 |
| 8 | hasNext() → true | index = 1, size = 3 |
| 9 | next() → "Java" | index = 2 |
| 10 | hasNext() → true | index = 2, size = 3 |
| 11 | next() → "Python" | index = 3 |
| 12 | hasNext() → false | index = 3, size = 3 |
| 13 | Loop ends | Complete |

---

## Comparison with Other Patterns

| Pattern | Purpose | Key Difference |
|---------|---------|-----------------|
| **Iterator** | Access elements sequentially | Separates traversal from collection |
| **Composite** | Tree-like structures | Focuses on hierarchy |
| **Visitor** | Operations on structures | Focuses on operations |
| **Strategy** | Algorithm selection | Selects algorithm at runtime |
| **Observer** | Event notification | Push-based updates |

---

## Best Practices

### 1. **Use Const Iterator**
```cpp
class Iterator {
public:
    virtual bool hasNext() const = 0;
    virtual string next() = 0;
};
```

### 2. **Handle Empty Collections**
```cpp
if(!iterator.hasNext()) {
    cout << "Collection is empty" << endl;
    return;
}
```

### 3. **Avoid Iterator Invalidation**
```cpp
// Don't modify collection while iterating
while(iterator.hasNext()) {
    // DON'T: collection.removeBook(iterator.next());
    string book = iterator.next();
    processBook(book);
}
```

### 4. **Resource Cleanup**
```cpp
class Iterator {
public:
    virtual ~Iterator() {
        // Clean up resources if needed
    }
};
```

### 5. **Fail-Fast Behavior**
```cpp
// Detect concurrent modification
if(collectionModified) {
    throw new ConcurrentModificationException();
}
```

---

## Common Mistakes

### ❌ Mistake 1: Modifying Collection During Iteration
```cpp
// WRONG
while(iterator.hasNext()) {
    string book = iterator.next();
    if(book == "Java") {
        collection.removeBook(book);  // Can cause issues!
    }
}
```

### ✅ Solution:
```cpp
// RIGHT
vector<string> toRemove;
while(iterator.hasNext()) {
    string book = iterator.next();
    if(book == "Java") {
        toRemove.push_back(book);
    }
}
for(auto& book : toRemove) {
    collection.removeBook(book);
}
```

### ❌ Mistake 2: Reusing Iterator After Exhaustion
```cpp
while(iterator.hasNext()) {
    cout << iterator.next() << endl;
}
cout << iterator.next() << endl;  // ERROR: No more elements
```

### ✅ Solution:
```cpp
BookIterator iterator(collection);  // Create new iterator
while(iterator.hasNext()) {
    cout << iterator.next() << endl;
}
```

---

## Advanced Concepts

### 1. **Iterator Factory Method**
```cpp
class BookCollection {
public:
    Iterator* createIterator() {
        return new BookIterator(*this);
    }
};
```

### 2. **Reverse Iterator**
```cpp
class ReverseIterator : public Iterator {
private:
    BookCollection& collection;
    int index;
    
public:
    ReverseIterator(BookCollection& collection)
        : collection(collection), 
          index(collection.size() - 1) {}
    
    string next() override {
        return collection.getBook(index--);
    }
};
```

### 3. **Filtered Iterator**
```cpp
class FilteredIterator : public Iterator {
private:
    Iterator* wrapped;
    bool (*predicate)(const string&);
    
public:
    string next() override {
        while(wrapped->hasNext()) {
            string elem = wrapped->next();
            if(predicate(elem)) return elem;
        }
    }
};
```

---

## Related Design Patterns

### **Composite Pattern**
- Often used with Iterator
- Iterator traverses Composite tree structures
- Helps implement tree traversal

### **Factory Pattern**
- Iterator factory creates appropriate iterators
- Creates concrete iterators based on collection type

### **Strategy Pattern**
- Different traversal strategies
- Swap algorithms at runtime

### **Command Pattern**
- Iterator can be combined with Command
- Encapsulate operations on each element

### **Template Method Pattern**
- Define iterator algorithm skeleton
- Subclasses implement specific steps

---

## Summary

| Aspect | Details |
|--------|---------|
| **Type** | Behavioral Design Pattern |
| **Purpose** | Sequential access without exposing structure |
| **Key Intent** | Decouple traversal from collection |
| **Main Benefit** | Encapsulation and uniform interface |
| **Complexity** | Medium |
| **Frequency of Use** | Very High (STL, Collections APIs) |

---

## References

- Gang of Four Design Patterns
- Refactoring.guru Iterator Pattern
- C++ STL Iterator Documentation
- Java Collections Framework

---

## Code Location
- **Implementation**: [iterator.cpp](iterator.cpp)
- **Pattern Type**: Behavioral Pattern
- **Complexity**: O(n) for full traversal
- **Space**: O(1) for iterator state

