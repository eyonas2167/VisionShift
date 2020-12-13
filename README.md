# Programming Assignment 04 : Behavior Tree
Due: 11/11/2020, 11:59pm

## Compile and Run the code
- Same as previous assignment, here is Windows [VC solution](https://www.dropbox.com/s/eob7enphdffk3ul/netid-PA04.zip?dl=0) for your convenience

## Tasks

1. In a short paragraph, describe Zombie's behavior (10 pts)
	- Write this as comments in _MyZombieAgent.h_
	- The behavior of the Zombie cannot be simpler than the [behaviors](https://dev.to/code2bits/pac-man-patterns--ghost-movement-strategy-pattern-1k1a) of [the ghosts in PacMan](https://en.wikipedia.org/wiki/Ghosts_(Pac-Man)).
2. Draw a [behavior tree](https://en.wikipedia.org/wiki/Behavior_tree) based on the description (20 pts)
	- Save your drawing as an image file under _imgs/_ folder
	- Add the file name of the image to the end of your description in Task #1
3. Implement the behavior tree using the provided code (60 pts)
	- Implement Selector and Sequence nodes in _MyBehaviorTree.h_ and _MyBehaviorTree.cpp_ (20 pts)
		- Note: You are free to create more types of nodes if needed
	- Use Selector and Sequence nodes in _MyZombieAgent.cpp_ and create a behavior tree (40 pts)
		- The tree is created manually in build_behavior_tree()
		- Depending on your drawing, most likely, you will need to create several more classes of MyZombieTaskXX (empty implementation of MyZombieTask01 and MyZombieTask02 is provided)
4. Make a video that demonstrates the implemented behavior (10 pts)

## Bonus Tasks

1. Read the behavior tree in _MyZombieAgent.cpp_ instead of create the tree manually. (20 pts)
	- Define a behavior tree file format with selector node, sequence node and some predefined actions and conditons
	- Create a behavior tree file following the format
	- Read the file into your program and create the corresponding behavior tree.
	- Submit the file format and the behavior tree file with your code.
	- PS: No partial points. To earn the bonus points, you must finish all requirements. 

2. Design a game and provide the following details of your game to get the full points (20 pts)
    - A game title
    - Prototype Assets: new prototype assets used in this game.
    - High Concept: A one-sentence summary of your game.
    - Gameplay: A paragraph describing the actions the player can perform, the system dynamics, and the core mechanic.
    - Strategies: What player strategies do you expect will be effective at playing this game?
    - PS: Submit a document with all the required descriptions and an additional video showing the game play. 
    - PPS: No partial points. To earn the bonus points, you must finish all requirements. 


## What to submit

1. Zip the entire folder and the video and name it your_net_id_PA04.zip
2. Upload the zip file to blackboard
3. Please *state what Tasks and Bonus Points* you have finished on the blackboard submission page. 


