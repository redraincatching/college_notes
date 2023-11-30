# raycasting
involves casting a ray from a source position, and checking what physics elements it hits
static methods of the Physics class
can be performed against colliders and triggers
as well as rays, unity lets you cast larger objects like spheres or boxes in a direction
you can also filter by layer
note: this is not the only way to detect colliders, but it's a classic for a reason

## Physics.Raycast
a simple boolean raycast identifying whether or not there is a collision

```c#
public static bool Raycast( 
	Vector3 origin, Vector3 direction, // mandatory
	float maxDistance, int layerMask, QueryTriggerInteraction qti // optional
	)
```

### parameters
- origin
	- starting point in world coordinates
- direction
	- direction in world coords
- maxDistance
	- what do you think
- layerMask
	- used to selectively ignore colliders on a certain layer
- QueryTriggerInteraction
	- specifies trigger interaction

> raycasts will not detect colliders for which the origin is inside of

### out
you can add the parameter 
```c#
out RaycastHit hitInfo
```
to obtain more information about the collider that was hit first
- .collider
	- the collider that was hit
- .distance
	- distance from ray's origin to impact point
- .normal
	- the surface normal of the hit surface
- .point
	- the impact point in world space
- .rigidbody
	- the collider that was hit
	- could be null

> in c#, out is a way of passing by reference




> #game_development #c_sharp 