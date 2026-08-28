# Iterator Design Pattern

The Iterator pattern is a behavioral design pattern that provides a standard way to access elements of a collection one by one without exposing how the collection is stored internally.

In simple words:

> Iterator means: traverse a collection without knowing its internal structure.

## Problem It Solves

Without an iterator, client code may directly depend on how data is stored.

Example:

```cpp
for (int i = 0; i < books.size(); i++) {
    cout << books[i] << endl;
}
```

This is fine for a vector, but what if the collection later becomes a linked list, tree, playlist, or database result? The client code may need to change.

## Main Idea

Move traversal logic into a separate iterator object.

The client only asks:

- is there a next item?
- give me the next item

It does not need to know the internal storage.

## Structure

| Component | Responsibility |
|---|---|
| Iterator Interface | Declares traversal methods like `hasNext()` and `next()` |
| Concrete Iterator | Implements traversal for a specific collection |
| Collection | Stores data |
| Client | Uses the iterator to access elements |

## Typical Flow

```text
Client creates collection
Client asks collection for iterator
Iterator keeps current position
Client calls hasNext()
Client calls next()
Repeat until traversal is complete
```

## Files In This Folder

Read in this order:

1. [iterator.cpp](iterator.cpp) - basic iterator example
2. [student.cpp](student.cpp) - iterator with student data
3. [product.cpp](product.cpp) - iterator with product data
4. [music.cpp](music.cpp) - iterator-style traversal in a playlist/music example
5. [employee.cpp](employee.cpp) - iterator with employee objects

## When To Use

Use Iterator when:

- you need to traverse a collection sequentially
- the collection internals should stay hidden
- different collections should be traversed using the same style
- you want multiple traversal styles later
- client code should not manage indexes or internal pointers directly

## Advantages

- hides collection internals
- reduces coupling between client and collection
- keeps traversal logic separate
- supports different traversal styles
- makes client code cleaner

## Disadvantages

- adds extra classes
- can be overkill for very small collections
- may add small method-call overhead
- needs care if the collection changes while iterating

## Real-World Examples

- C++ STL iterators: `vector<int>::iterator`
- Java collection iterators
- database result cursors
- file system traversal
- playlists
- menu item traversal

## Easy Notes For Revision

**Simple idea:** provide a common way to move through a collection one item at a time.

**Example:** a `BookIterator` can traverse a `BookCollection` without exposing whether books are stored in a vector, list, or another structure.

**Where to use:**
- when client code should not know collection internals
- when multiple collections need the same traversal style
- when traversal logic should stay separate from business logic
- when different traversal orders may be needed later

**Advantages:**
- hides internal collection structure
- keeps traversal logic separate
- makes client code simpler
- supports different traversal styles

**Disadvantages:**
- adds extra iterator classes
- can be unnecessary for very simple loops
- collection changes during iteration can cause problems if not handled

**Interview explanation:** Iterator lets client code access collection elements sequentially using methods such as `hasNext()` and `next()` without exposing how the collection is stored.

## Quick Revision

```text
Intent:
Access collection elements sequentially without exposing internal structure.

Core methods:
hasNext() -> checks if more elements exist
next() -> returns current item and moves forward

Main benefit:
Client code stays independent of collection implementation.
```

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\DesignPatterns\Behavioral\Iterator-design-pattern"
g++ -std=c++17 -Wall -Wextra iterator.cpp -o iterator.exe
./iterator.exe
```

Replace `iterator.cpp` with `student.cpp`, `product.cpp`, `music.cpp`, or `employee.cpp` to run the other examples.
