# a* pathfinding
## Algorithm 
- Add the starting node to the open list 
- Look for the lowest f cost square on the open list (initially just the starting node) 
- Switch it to the closed list 
- For each of this squares neighbours 
	- If it is on the closed list or not usable for the path, ignore it 
	- Otherwise, if it isn't on the open list, add it to the open list, with the current square as its parent and appropriate f, g and h scores 
	- If it is on the open list, check if the g score is lower than it currently is if you go from the square you are on, if it is, update the parent of this square and recalculate the f score 
- Repeat from step 2 until you add the target square to the closed list or fail to find the target square 
- Working backwards from the target square, go from each square to its parent square to find the path

> #next_generation_technologies #algorithms #game_development