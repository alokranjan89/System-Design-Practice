# DRY

DRY means “Don't Repeat Yourself.” Its useful focus is repeated knowledge or rules that can drift out of sync, not every repeated line of code. Duplication can be simpler than a premature shared abstraction when two pieces only look alike today.

[`dry.cpp`](dry.cpp) is the example. Look for the repeated rule and consider how a single authoritative implementation would help. Compile it from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra Principles/DRY/dry.cpp -o dry.exe
.\dry.exe
```
