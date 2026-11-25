# Iterator

Iterator provides a traversal interface so client code can visit collection items without managing the collection's traversal details.

## Examples

| File | Example |
|---|---|
| [`iterator.cpp`](iterator.cpp) | Book collection and iterator |
| [`student.cpp`](student.cpp) | Student collection |
| [`product.cpp`](product.cpp) | Product collection |
| [`music.cpp`](music.cpp) | Playlist traversal |
| [`employee.cpp`](employee.cpp) | Employee collection |

Start with `iterator.cpp`. Identify the collection, iterator, and client. Follow calls to `hasNext()` and `next()` and note where the current position is stored.

## Trade-off

An explicit iterator can hide collection details and support a common traversal API. It also adds code; for simple C++ containers, standard range-based loops and STL iterators are usually the better starting point. A collection modified during iteration needs a defined policy.

## Build

From this directory, compile one file at a time:

```powershell
g++ -std=c++17 -Wall -Wextra iterator.cpp -o iterator.exe
.\iterator.exe
```

Substitute any other listed source file to run its example.
