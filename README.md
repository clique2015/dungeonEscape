Unreal Engine 5 – Dungeon Escape Game
Game Overview
Dungeon Escape is a timed puzzle-based game developed in Unreal Engine 5. The gameplay centers on exploration, environmental interaction, and time-critical decision-making.
The game begins when the player steps onto a pressure plate, which triggers a timed gate to open. The player must enter the dungeon room and retrieve an initial key within the allotted time. If the player fails to collect the key before the timer expires, the gate closes and the game is lost.
Upon successfully obtaining the key, the player places it on a statue. This action unlocks an underground dungeon entrance, allowing the player to descend the stairs and acquire the final exit key. After returning to the main level, the player uses this key to unlock the main exit gate, successfully completing the game.

Class Definitions and Responsibilities
Lock.cpp
 Manages the lock state of game objects. It tracks whether a key has been placed using the isKeyPlaced variable, which determines whether the associated lock can be unlocked.
CollectibleItem.cpp
 Handles collectible items within the game. When a key is collected, the class uses the AddTag function to register the key as collected by the player.
MoveDoor.cpp
 Controls the movement of doors and gates. It manages opening and closing behavior by interpolating between a defined starting position and a destination position.
TrigBoxComponent.cpp
 Detects player interaction with the pressure plate. This class uses a box collider to monitor overlap events when the player steps onto or off the pressure plate.
MyProject7Projectile.cpp
 Implements the key collection mechanic. This class uses the OnComponentHit event to detect interaction with keys, checks the distance between the player and the key, and verifies that the player has a clear line of sight before allowing the key to be collected.



