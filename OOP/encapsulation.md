# Encapsulation

Encapsulation keeps an object's state and the operations that protect it together. Hide implementation details and expose a small, clear public interface. In C++, `private`, `protected`, and `public` control access.

Encapsulation helps prevent invalid state; it is more than simply putting fields and methods in one class. For example, keep an account balance private and change it through operations that can enforce the account's rules.

## When it helps

- Callers should not be able to change state arbitrarily.
- An object needs to enforce rules whenever its state changes.
- The implementation may change while the public interface stays stable.

## Remember

Expose only the operations callers need. A public getter and setter for every field often defeats encapsulation.
