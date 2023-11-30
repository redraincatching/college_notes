# Game engines
 a set of integrated subsystems geared towards high-performance realtime media
- graphics rendering
- physics
- networking
- special effects
- 3d audio
- user input

## The Game Loop
at their core, games operate on a "game loop"
- operating at 60 fps or more
- deal with inputs
	- received asynchronously via events or polled
- process game objects
	- user-controlled objects
	- enemy ai
	- other scheduled behaviours (e.g. sprite frame updates)
- move game objects
	- by physics system or directly controlled
- redraw
- either wait or run at max obtainable speed
	- don't block the main thread

> ## unity - using the editor
> https://docs.unity3d.com/Manual/UsingTheEditor.html

## the unity api
most of the code we write will manipulate code form the UnityEngine and UnityEngine.UI namespaces


## component-based architecture
2nd-generation game engines use this as it suits game logic very well
different to classic oop as it's based on composition, not inheritance
every entity consists of one or more components that add functionality
entity behaviour can be changed at runtime by adding or removing components
each component is essentially a separate software object that is attached to a higher-level GameObject
for example, if a player and a tree in a 2d game both need to cast shadows, they shouldn't be instances of the same parent class, but could both add a component called "CastShadow"

> ##### composition vs inheritance
> composition is better for code reuse
> inheritance is better for hierarchical taxonomies of classes




> #game_development #c_sharp