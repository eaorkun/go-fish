Instructions for unzipping and running code
********************************************

Unzip contents into the same folder, make using the makefile, and run executable! There is a premade driver for running the game in go_fish.cpp

If editing code, make sure you read the various files for details on how to interact with the classes and objects

Implmentation is through vectors for holding the hands of each player and through vectors for holding the books. The deck is implemented by an array.

Any assumptions or known bugs: Gameplay followed clarifications on piazza and no known bugs known. However, only should use most functions in actual gameplay and not individually.

Read the rest of the lab instructions below!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Go Fish!
100 points
Due: Monday 11/13/2020 at 11:59 pm
The goal of this assignment is to use some pre-defined classes to create more classes and to use these classes to play a simple card game. We will use the basic rules of Go Fish. The requirement is that your program work with two players (starting with 7 cards).
The basic game (from Wikipedia)
One player is chosen to go first. This may be done by each player picking a card from the deck, and the player picking the lowest card goes first. These cards are returned to the deck.
The deck is shuffled, and 5 cards are dealt to each player, or 7 cards if there are only two players. The remaining card pack is placed between the players and is known as the “pool”.
The player whose turn it is to go first (Bob) asks another player (Alice) for their cards of a particular rank. For example, Bob asks Alice, "Alice, do you have any threes?". Bob may only ask for a rank of which he already holds at least one card. If Alice has any threes, she must then hand over all cards of that rank to Bob. Bob adds these cards to his hand and takes another turn. If Alice has no cards of that rank (threes), she says "Go fish" (or simply "Fish"), and Bob draws the top card from the pool. The turn then passes to the player who was asked, in this case Alice.
When one player has two of the same cards of a given rank, they form a book, and the cards are placed face up on the table. The game ends when all twenty-six books are formed, and the player who won the most books wins.
If the player whose turn it is has no cards left in their hand, the game is not over, but they simply draw the top card from the pack and the turn passes to the next player in the rotation, or, in the case of a two-player game, the other player.
We will be using the vector class from the Standard Template Library (STL) to hold the players cards and to hold the "books" that are formed from pairing cards. Each player will have a hand and a collection of books.
Some classes that we will use for this project will be provided in the starter zip file. You will
need to implement the .cpp files for most of these classes before you can get to the "Go Fish"
game.
card.h - simulates one playing card (a suit and a value).
deck.h - simulates a deck of 52 cards
player.h - simulates a player in the game
card_demo.cpp - a demo of a main program that will deal some cards
For the output of the program, you should print each play to a text log file (you may want to
echo to standard output while debugging) and the eventual winner.
Note: The computer will simulate the game and play the hands of both players. There is no
input from people.
e.g. Joe asks - Do you have a J?
Jane says - Go Fish
Joe draws 4d
Jane asks - Do you have a 4?
Joe says - Yes. I have a 4.
Jane books the 4..
Jane asks - Do you have a 6?
Joe says - Go Fish
Jane draws Jc
etc.
Your output can certainly be different as long as it describes the game. Make sure the results of
the game are clear.
Tips:
1) Start by implementing the Card class and testing it. Then the Deck class. Then the
Player.
2) If you are unsure about how the flow of the game should proceed, use your best judgment, and document your decision.
3) Print out each player’s hand after every turn and the state of the deck to make sure that the expected behavior (drawing/forming pairs) works.
4) Split your driver into smaller methods, such as a method to deal the starting cards to each player, a method to take all cards of a specific rank from another player, a method to choose a card that one player will ask another player, a method for a player to take a turn, and so on. Testing these smaller methods individually will help you avoid logic errors.
5) Start early!
How will Go Fish be graded?
Your Card and Deck classes are expected to conform to the interfaces that we provided in the headers. All the given methods must be implemented as according to the guidelines provided in the comments within each header. Feel free to add in any private functions/variables that you feel is necessary, but do not touch any of the public functions. However, you will have more freedom to implement your Player class and driver. Together, the two of them should be capable of playing a fully automated game of Go Fish with at least two players with no input from the user. We will not require you to adhere to any defined format for the output, but it should be readable and all of each player’s actions within a turn (drawing a card, asking for a card, forming pairs) must be outputted, which will be what we look at while grading.
Notes:
• You must do this assignment by yourself.
• The game you will simulate is a variant of the commonly played game. In our variant, as described above, the books are made of pairs (2 cards of the same rank). You do not need all 4 cards to make a book.
• Implement Deck::shuffle() without using any of the shuffle methods built into the C/C++ standard library.
• If you run into an ambiguous situation regarding the card game, use your best judgement and document your solution.
• Your output should go to the file gofish_results.txt.
• You must name your C++ source files card.h, card.cpp, deck.h, deck.cpp, player.h, player.cpp, and go_fish.cpp.
• Include a makefile.
• Include in your submission a README file for your program. It is important that you document how you implemented things, any assumptions or known bugs, how to build and run your code, etc.
• Appropriate values should be stored in constant variables.
• Be sure to follow the documentation standards for the course.
• Hand in a zipped file named prog06_xxxxxx.zip where xxxxxx is your UT EID number
Turn in: One zipped file that includes: your C++ source files card.h, card.cpp, deck.h, deck.cpp, player.h, player.cpp, and go_fish.cpp, a README file and a makefile
Upload: One zipped file named prog06_xxxxx.zip where xxxxxx is your UT EID to Canvas.
vpt 10/30/20
created by Roger Priebe (rlp 10/9/19)