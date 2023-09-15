# Alien-Shooter-Game

Arduino Alien Shooter Game

Objective:
The Arduino Alien Shooter game is a game where players use a laser pointer to "shoot" aliens represented by 
Light-Dependent Resistors (LDRs) and LEDs. The goal is to score as many points as possible before the you miss 
one and the game ends. Each time you hit an alien the game speeds up. Once you miss a Alien the game will end 
and display your score and the all time high score.

Components:

Light-Dependent Resistors (LDRs) with corresponding LEDs: These serve as the aliens in the game. Each LDR is associated with an LED,
and when the LDR is exposed to light (from the laser), the corresponding LED lights up.

Laser Pointer: This acts as your weapon to shoot the aliens.

LCD Screen: Displays your score during the game and the final score at the end.
Game Logic: Arduino microcontroller is responsible for controlling the game, including tracking the score, increasing the difficulty, and ending the game.
