# Design Patterns

Design patterns are reusable solutions to common software design problems. They are not copy-paste code templates. They are ways to organize classes and responsibilities so the system is easier to extend, test, and understand.

## Recommended Order

Start with creational patterns, then behavioral patterns.

1. [Creational Patterns](Creational/README.md)
2. [Behavioral Patterns](Behavioral/README.md)

## Pattern Families In This Repo

| Family | Purpose | Folder |
|---|---|---|
| Creational | How objects are created | [Creational](Creational/README.md) |
| Behavioral | How objects communicate and share behavior | [Behavioral](Behavioral/README.md) |

## How To Study A Pattern

For each pattern:

1. Read the README first.
2. Identify the problem.
3. Identify each class role.
4. Trace the flow from `main()`.
5. Compile and run the example.
6. Change one class or add one new behavior.

## Important Advice

Do not memorize pattern names only. Focus on the design pressure:

- What becomes hard without the pattern?
- What responsibility is separated?
- What becomes easier to change later?
- What extra complexity does the pattern add?

Good design is about choosing the simplest structure that can handle expected change.
