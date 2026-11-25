# Observer

Observer lets one subject notify multiple subscribers when something changes. The subject keeps the observer interface, so it does not need to depend on each subscriber's concrete class.

## Roles in this example

[`youtube_notification.cpp`](youtube_notification.cpp) models a YouTube channel and its subscribers:

| Role | Responsibility |
|---|---|
| Subject / publisher | Stores subscribers and sends updates |
| Observer / subscriber | Receives an update through a shared interface |
| Client | Creates the channel and subscribers, then connects them |

Trace `main()` to see subscribers register and receive a notification after a new video is uploaded.

## When it helps

Use Observer when several parts of a program need to react to one event. Remember to manage subscriptions: stale observers and unclear notification order can make the flow harder to debug. A direct call is simpler when there is only one fixed recipient.

## Build

From this directory:

```powershell
g++ -std=c++17 -Wall -Wextra youtube_notification.cpp -o youtube_notification.exe
.\youtube_notification.exe
```
