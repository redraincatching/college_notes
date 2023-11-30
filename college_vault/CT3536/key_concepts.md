# key concepts and classes
## monobehaviours
MonoBehaviour is the base class from which scripts derive
this hooks the class into the game loop so various methods such as Update(), Start(), OnDestroy() are called for you by the game engine

Awake(), Start(), and OnEnabled() are all different methods
-> awake and start are basically the same, and happen once
-> OnEnabled happens multiple times

Update() -> every frame
FixedUpdate() -> every physics frame

in games, it is useful to be able to execute code at programmer-controlled intervals, or at a specified time in the future
in unity monobehaviours, these methods can do this 
- Invoke()
- Coroutine()

there are also several important public data members
- enabled
- gameObject    // reference to GameObject
- transform
- name

> every object has a transform innately

there are some more methods which are useful for manipulating GameObjects and their components
- sendmessage()
- broadcastmessage()
- getcomponent()
- getcomponentinchildren() / getcomponentinparent()
- getinstanceid()
- etc.

the flexibility of these is due to the composition system used in unity, rather than inheritance

---
## GameObjects in unity
base class for all entities
-> you don't need to attach them as a component
### useful data members
- activeInhierarchy
- transform
- tag
### useful methods
- AddComponent()
#### adding a component at runtime
- SendMessage()
- GetComponent()
- SetActive()
### useful static methods
// unusual because you call it on the GameObject itself, and not an instance of the class
- Find()
- Destroy()
- Instantiate()

### getting a reference to a gameobject at runtime
- have it referenced as a public member of the script that needs it, and associate it at design time in the inspector
- use GameObject.Find("name") to find it by name
// inefficient so don't do it every day
- use GameObject.FindObjectByTag() to get an array of all objects with that tag

### runtime instantiation + destruction of gameobjects
- so far, we have created all the gameobjects we need at design time
- often we need to create/destroy things at runtime - bullets, enemies, etc

---

## Transforms
defines the position, orientation, and scale of an object
child objects have their own transform which is a nested coordinate system, i.e. a modification of the parent's
### key members
- position (Vector3)
- localPosition (Vector3)
- rotation (Quaternion)
- localRotation (Quaternion)
- right, up, forward (normalized Vector3s)

### key methods
- Rotate()
- Translate()
- RotateAround()
- LookAt()

---
## the singleton pattern
a common design pattern in unity is to create single-instance "management" scripts
e.g. GameManager, GUIManager, 

### static member variables
by declaring a member variable static, you're creating a single copy of the variable which is owned by the class, rather than any specific instantiated object
each instance does not have its own unique copy

a common use is if you want to have a collection of all the instances of a class

### static methods
by declaring a method static, you're creating a method that is called on the class itself, not an instance
for obvious reasons such methods only have access to static member variables

> #game_development #c_sharp 