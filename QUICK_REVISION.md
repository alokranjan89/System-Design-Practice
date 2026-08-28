# System Design Quick Revision

Use this file when you want to revise only the important points quickly.

## Study Order

1. Principles: KISS, DRY, YAGNI, SOLID.
2. Creational patterns: Factory, Builder, Prototype, Singleton.
3. Structural patterns: Adapter first.
4. Behavioral patterns: Strategy, Observer, Iterator, Command, Mediator, State.
5. LLD examples: practice class responsibilities and object relationships.

## Must-Know Questions

- What problem does this solve?
- Which classes are involved?
- Which class owns the main responsibility?
- Which class depends on abstraction?
- What becomes easier to change?
- What complexity does this add?
- When should this design be avoided?

## Pattern Memory Lines

| Topic | Revision Line |
|---|---|
| Factory | Move object creation away from client code. |
| Builder | Build complex objects step by step. |
| Prototype | Clone an existing object to create a similar object. |
| Singleton | Keep only one shared instance. |
| Adapter | Wrap an incompatible class with the expected interface. |
| Strategy | Switch algorithms or behavior at runtime. |
| Observer | Notify subscribers when one object changes. |
| Iterator | Traverse a collection without exposing internals. |
| Command | Convert a request into an object. |
| Mediator | Centralize communication between many objects. |
| State | Change behavior when internal state changes. |

## LLD Checklist

For every example:

1. Identify entities/classes.
2. Identify attributes and methods.
3. Separate responsibilities.
4. Find relationships: has-a, is-a, uses-a.
5. Trace the flow from `main()`.
6. Explain one possible improvement.
