# Composite

Composite lets clients use individual objects and groups of objects through the same interface. It is useful for tree-shaped structures where an operation should apply recursively to both a leaf and its container.

## Roles in this example

| Role | Example | Responsibility |
|---|---|---|
| Component | `FileSystem` | Declares the operation shared by files and folders (`show()`) |
| Leaf | `File` | Represents an item with no children |
| Composite | `Folder` | Stores child `FileSystem` objects and applies `show()` to each one |
| Client | `main()` | Builds the tree and calls `show()` on the root |

## How it works

`Folder` stores pointers to the common `FileSystem` interface. A child can therefore be either a `File` or another `Folder`. Calling `root->show()` prints the root and recursively visits each nested item, without the caller checking whether each item is a file or folder.

## Where to use

- File and folder hierarchies
- Organization charts or nested UI elements
- Menus and other tree-shaped structures where operations apply to subtrees

## Advantages

- Clients can treat leaves and groups uniformly.
- Adding a new component type does not require changing the traversal in the client.
- Recursive operations fit naturally on the composite.

## Trade-offs

- The shared interface may expose operations that only make sense for folders, such as adding children.
- Tree ownership and removal rules need to be defined; this example uses raw pointers and does not free its allocated objects.

The folder hierarchy example is in `composite.cpp`. An employee hierarchy using the same pattern is in `employee.cpp`: managers are composites, while individual contributors are leaves. It uses `std::unique_ptr` so the tree's objects are cleaned up automatically.

Compile and run the employee example from this directory:

```powershell
g++ -std=c++17 -Wall -Wextra employee.cpp -o employee.exe
.\employee.exe
```

Output:

```text
Ava - Manager
  Noah - Manager
    Liam - Developer
    Olivia - Developer
  Mia - Manager
    Ethan - Designer
```
