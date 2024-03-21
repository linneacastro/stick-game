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

#include <stdio.h>

int pick (int n); // Pick function prototype
void stickprinting (int n); // Stick printing function prototype 

void main (int argc, char **argv) // Main function
{
int remainingsticks; // Will use for initial sticks and stick count following turns
char extra1[120];

int waiting = 1;  // Will use this to enter initial while loop to begin parsing
int stickspicked; // Num of sticks user chooses to remove stored here
char temp[120];   // Array allocated to store user's input prior to parsing
char extra2[120]; // Array allocated to check for integer followed by not integer
int strikes = 0;  // 2 illegal entries in a row and you forfeit game

int sticks; // For pick function

remainingsticks = 21; // If no arg given save for program name, default initial sticks 21 THIS WORKS

// If multiple args are given for initial stick count THIS WORKS
if (argc > 2){
printf("Please enter the number of sticks to begin with or hit enter for default 21.\n");
return;
}

// If not number arg given for initial stick count... it DOES still accept negative numbers though :/
if (argc == 2){
int flag=sscanf(argv[1], "%d%s", &remainingsticks, extra1);
if (flag != 1){
printf("Please enter the number of sticks to begin with.\n");
return;
}
}

//sscanf(argv[1],"%d",&remainingsticks); My first iteration of the parsing chunk above

printf("Hello!  Welcome to the stick picking game.\n");
printf("We are starting the game with %d sticks. Good luck!\n", remainingsticks);

// Enter loop until valid input (1/2/3) is entered  

  while (waiting == 1){ // Initialized waiting = 1 so this will be true, allowing automatic entry to loop
    printf("How many sticks do you want to remove? 1, 2, or 3? "); // Moved this INSIDE the while loop
    fgets(temp,120,stdin); // Get keyboard inpt from user w their stick pick: 1, 2, or 3 ONLY
    int result=sscanf(temp,"%d%s",&stickspicked,extra2); // Interpret user input w SSCANF to parse

    if (result == 1 && 0<stickspicked && stickspicked<4) { // Valid # entered... but we want it to be 1, 2, or 3.
      waiting=0; // Clears flag to leave loop
      strikes=0; // A legal entry resets "strike" count

printf("\nYou removed %d stick/s.\n", stickspicked);

remainingsticks = remainingsticks - stickspicked;
	if (remainingsticks <= 0){ // Checks to see if user has drawn last lot of sticks
	printf("\nYou just won the game by drawing the last stick/s!  Congratulations!\n");
	break; // Exits program if user wins
	}

printf("There are %d sticks remaining.", remainingsticks);
stickprinting(remainingsticks); // Calling stick printing function
printf("(%d)\n\n", remainingsticks);

sticks=pick(remainingsticks);
printf("\nMy turn. I removed %d stick/s.\n", sticks);
remainingsticks=remainingsticks-sticks;
	if (remainingsticks <= 0){  // Checks to see if computer has drawn last lot of sticks
	printf("\nI just won the game by drawing the last stick/s!  I'll play you again :)\n");
	break;
	}

printf("There are now %d sticks left.", remainingsticks);
stickprinting(remainingsticks); // Calling stick printing function again
printf("(%d)\n\n", remainingsticks);

waiting = 1; // I want to stay inside the loop 

    } else { // Something other than 1/2/3 was entered
      strikes++; // If user inputs illegal entry, strikes will be incremented by 1
		if(strikes == 1){
		printf("Not a valid entry. Strikes: %d.\n", strikes);
		}

		else if(strikes >= 2){
		printf("Not a valid entry. Strikes: %d.", strikes);
		printf("\n2 strikes in a row, you have forefeited the game and I have won!\n");
		return; // Takes me out of the program for 2 strikes in a row
		}
           }
 }

} // End of main function

// PICK FUNCTION picks 1 if 4 divides evenly, otherwise prints remainder n%4

int pick(int n) 
{
int remainder;
int pick;

remainder = n%4; // Function is called after the user inputs a valid number, it takes number of remaining sticks and div by 4

  if (remainder == 0){
  pick = 1;  // If 4 divides in evenly, computer will choose to remove 1 stick
  }

  else {
  pick = remainder; // Otherwise the computer will remove the remainder
  }

  return(pick);
}


// STICKS PRINTING FUNCTION based on p. 178 in C Primer Plus Textbook

void stickprinting(int n)
{
  while (n-- > 0) // Func is called after each turn to display sticks.  Remaining stick number gets passed to func.
    printf(" | "); // It prints one pipe for the current stick count, decrements by 1, and prints a stick for that value... until n=1
}
