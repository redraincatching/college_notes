# coordinate systems
the most important distinction in unity is between local and global coordinates
hence, to rotate the camera around its perceived y-axis we can use
camera.transform.RotateAround(Vector3.zero, camera.transform.up, 50f * Time.deltaTime);
or we can use the global y-axis
camera.transform.RotateAround(Vector3.zero, Vector3.up, 50f * Time.deltaTime);

methods to transform from local to global
- public Vector3 TransformPoint(Vector3 position);
- public Vector3 TransformDirection(Vector3 direction);
- public Vector3 TransformVector(Vector3 vector);

and the other way around
- public Vector3 InverseTransformVector(Vector3 vector);

##### example
to find the world-coordinate of a point whic is 10 units "in front of" a spacceship, in terms of its own forward direction
// assume this code is in a component attached to the spaceship

```c#
Vector3 pt = transform.TransformPoint(new Vector3(0f, 0f, 10f));
```

could also do

```c#
Vector3 pt = transform.position + 1f * transform.forward;
```

##### example
accelerate a spaceship forwards (assuming it has a rigidbody and we're using physics, ad this is in a FixedUpdate method that is a sibling to its rigidbody)

```c#
RigidBody rigid = GetComponent<Rigidbody>;
rigid.addForce(transform.forward * 200f * Time.fixedDeltaTime);
```

##### example
direction and distance between two gameobjects

```c#
GameObject g1, g2;  // assumed not null

Vector3 difference, direction;
difference = g2.transform.position - g1.transform.position;
direction = difference.normalized;
float distance = difference.magnitude;
```


---
## screen-space, viewport-space, world-space
different mappings of position
Camera class provides methods for translating between the three spaces
each is stored as a Vector3

### screen space
defined in pixels
bottom-left is (0,0), top-right is (Camera.pixelWidth, Camera.pixelHeight)
in the Vector3, z is the position in front of the camera in world units
useful for mouse position or other pixel-relative operations

### viewport space
normalised and relative to the camera
(0,0) to (1, 1)
z is world units in front of the camera
useful for positioning gui elements

### world space
defined in global coordinates, e.g. Transform.position
appropriate for GameObjects

typical space translation operations
##### where is the mouse?
Camera.main.ScreenToWorldPoint(Input.mousePosition);

##### where is a gameobject on screen?
e.g. to position a gui object above it

```c#
GameObject targ; // assumed to be not null
Vector3 screenPos = Camera.main.WorldToScreenPoint(trag.transform.position);
```

> #game_development #c_sharp 