# YAGNI

YAGNI means “You Aren't Gonna Need It.” Build for current requirements and evidence, not imagined future features. This does not mean ignoring a known requirement or making change unnecessarily difficult.

[`yagni.cpp`](yagni.cpp) is the example. Identify which speculative behavior it avoids and what new requirement would justify adding that behavior. Compile it from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra Principles/YAGNI/yagni.cpp -o yagni.exe
.\yagni.exe
```
