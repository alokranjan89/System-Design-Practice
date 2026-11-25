# KISS

KISS means “Keep It Simple.” Prefer the clearest solution that meets the actual requirement. Simplicity does not mean skipping necessary validation or correctness.

Use this principle when choosing between designs: does the extra abstraction or feature solve a real problem today? If not, it may make the code harder to learn and maintain.

[`kiss.cpp`](kiss.cpp) is the example. Read it and identify what complexity it avoids. Compile it from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra Principles/KISS/kiss.cpp -o kiss.exe
.\kiss.exe
```
