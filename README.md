/* PA1 A Stick Picking Game Written in C */
// NAME: Linnea P. Castro
// COURSE: CSE 224
// DATE: 30 SEP 2022
// ASSIGNMENT #: PA1
// SYNOPSIS: 
/*
This is a virtual stick picking game where the user and computer take turns drawing sticks from 
a pile with the goal of being the last player to draw the final sticks.  On any given turn, a player 
must choose to remove 1, 2, or 3 sticks. The user always goes first, with the computer following,
and turns alternating. A player is declared the winner when on their turn, they have narrowed
the stick pile down to at least 3 sticks, so they can claim the final handful.  The default number 
of starting sticks is 21, but the user can specify any custom number of sticks to begin with on
the program command line when they open the program up and write, stick 32, for example, to begin with
32 sticks.

Parsing parameters are in place to ensure a valid number is entered into the starting command line, 
together with checks to ensure a valid number of sticks are drawn on the user's turn.  A strike 
system is in place whereby the user is warned after their first illegal entry (if they try and 
draw 5 sticks on their turn, for example).  A second consecutive strike will boot them out of the
game. Strikes reset after good behavior (one valid entry). 

The program uses a formula to give the computer an advantage over the unassuming user.  The program
divides the number of remaining sticks by 4 and chooses the remainder as its draw for that turn.  If
4 divides in evenly, the computer will draw 1 stick.  The user can also use this same formula to 
beat the computer. 

Skills practiced include: becoming more fluid with navigating vi workflow, documenting work by
committing to GIT repository, understanding loop structures, building and using functions, breaking 
down problem into smaller pieces, and keeping positive mindset during challenges.  
*/
