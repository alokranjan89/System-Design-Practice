# Smart Notification System

This example combines two behavioral patterns in one small LLD problem:

- **Strategy** chooses how a notification is sent: email, SMS, or push notification.
- **Observer** notifies subscribed users after the notification is sent.

## Why This Example Exists

Use this example after studying the individual Strategy and Observer patterns. It shows how patterns can work together inside a small real-world flow instead of staying as isolated examples.

## Main Classes

| Class | Responsibility |
|---|---|
| `NotificationStrategy` | Common interface for notification channels |
| `EmailNotification` | Sends an email notification |
| `SmsNotification` | Sends an SMS notification |
| `PushNotification` | Sends a push notification |
| `Observer` | Common interface for users that receive updates |
| `EmailUser` | Observer that receives email-style updates |
| `MobileUser` | Observer that receives mobile-style updates |
| `NotificationService` | Uses a strategy and notifies all observers |

## Flow

```text
main()
  creates notification strategies
  creates users
  creates NotificationService
  adds users as observers
  sends a message using the current strategy
  changes the strategy
  sends another message
```

## How To Run

```powershell
cd "C:\Users\Asus\OneDrive\Desktop\System Design\Examples\Smart Notification System"
g++ -std=c++17 -Wall -Wextra smartNotification.cpp -o smartNotification.exe
./smartNotification.exe
```

## What To Learn

- how Strategy separates the sending method from the service
- how Observer lets many users react to the same notification
- how one LLD example can use more than one pattern
- how runtime behavior changes without rewriting the service class
