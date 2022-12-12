
a major part of oop is modelling the problem
the goal is to identify
- the principle objects in the problem domain
- the responsibility of these objects
- the collaborations between objects

aim is to produce a simplified class diagram
- classes represent real-world entities
- associations are collaborations
- attributes are data hekd about the entities
- generalisation simplifies the structure

#### first:
identify the classes
-> usually, any noun is a class, though you may find yourself combining/splitting some of these 
// note: avoid any god-like classes such as a "system", this is bad for modularity

#### secondly:
the associations
what is an attribute of another class?
what is composed of other classes?

#### thirdly:
responsibilities
the verbs
where do they reside?
-> may not be as intuitive as it may seem at first

single responsibility principle
each class should have one responsibility, and all services should be aligned with that responsibility

note: an object should be responsible for communicating its own state

> #java #programming 