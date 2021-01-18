// FILE: go_fish.cpp
// This is the main driver to play go_fish
// written by Eralp Orkun
// 11/13/2020
// driver program with functions to help driver
/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Eralp Orkun, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Eralp Orkun
 * email address: eaorkun@utexas.edu
 * UTEID: eao789
 * Section 5 digit ID: 16000
 * Date: 11/11/2020
 */


#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <fstream>     // for file input
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:

/* FUNCTION - void dealHand
 * deals numCards Cards from Deck to Player object
     o removes numCards Cards from Deck array
     o adds numCards Cards to Player hand
 precondition: requires a minimum of numCards Cards in Deck array
 postcondition: numCards Card are dealt
*/
void dealHand(Deck &d, Player &p, int numCards);

/* FUNCTION - void startup
 * Initializes the go fish game given two new players and a new deck
     o calls dealHand inside
 precondition: requires a reset p1, p2 and d deck
 postcondition: Initializes go fish game
*/

void startup(Player &p1, Player &p2, Deck &d);


/* FUNCTION - void printHands
 * Prints the current hands of both players
     o prints p1 and then p2
 precondition: requires 2 Player object
 postcondition: displays all of cards to output file
*/

void printHands(const Player &p1, const Player &p2);

/* FUNCTION - void printBooks
 * Prints the current books of both players
     o prints p1 and then p2
 precondition: requires 2 Player object
 postcondition: displays all of cards that are booked to output file
*/

void printBooks(const Player &p1, const Player &p2);

/* FUNCTION - void checkBooks
 * checks hand of player for books (multiple) and will book then if found
     o Works if multiple cards to book
 precondition: requires valid Player object
 postcondition: cards are removed from hand of current player and added to book vector
*/

void checkBooks(Player &currentPlayer);

/* FUNCTION - void drawForTurns
 * determines which player will go first for game
     o Player who draws lower card from deck wins
     o Keeps on drawing until one player draws lower
     o Automatically shuffles deck as needed

 precondition: must be called before game initialized, 2 new valid player objects, and deck.
 postcondition: player object marked as first player, requires resetGame to reset objects
*/

void drawForTurns(Player &p1, Player &p2, Deck &d);

/* FUNCTION - bool isGameOver
 * determines if the game is over
     o Game over if total books == 26 between both player objects

 precondition: Must be valid Player objects, to be used within a game.
 postcondition: returns bool, true if the game is over, false otherwise
*/
bool isGameOver(const Player &p1, const Player &p2); //return true if all books formed


/* FUNCTION - void playerTurn
 * Executes 1 turn of a player, following go fish rules
    o main player as first argument
    o other player as second argument
    o checks for books after turns
 precondition: Must be valid Player objects, to be used within a game and valid deck.
 postcondition: follows go fish rules, repeats if takes a card, and adjusts state after that
*/

void playerTurn(Player &currentPlayer, Player &otherPlayer, Deck &d); //return true if continue player turn

/* FUNCTION - void determineWinner
 * determines winner by counting who has more books
 precondition: Must be valid Player objects, to be used AFTER isGameOver is true;
 postcondition: outputs the winner and number of books to file output
*/

void determineWinner(const Player &p1, const Player &p2);

/* FUNCTION - void resetGame
 * resets player objects and deck to be used again in a new game
 precondition: Must be valid Player objects
 postcondition: Resets Player objects, and resets deck
*/

void resetGame(Player &p1, Player &p2, Deck &d);

// starting number of cards to be dealt
const int STARTING_NUM_CARDS = 7; // defined as 7 for two players

ofstream myfile;  //declare file variable (global to be used in functions)

int main() {
    myfile.open("gofish_results.txt");
    myfile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    myfile << "~ Initializing Go-Fish (New Game Started) ~" << endl;
    myfile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    Player p1("Joe"); //create player 1
    Player p2("Jane"); //create player 2
    Deck d;  //create a deck of cards
    bool gameInProgress = true; //for game loop

    myfile << "** (Shuffling Deck - All 52 Cards) **" << endl;
    d.shuffle();
    myfile << "Drawing for the First Move" << endl;
    drawForTurns(p1, p2, d); //decide who goes first
    myfile << endl;

    startup(p1, p2, d); //initialize game
    myfile << endl;
    checkBooks(p1); //check possible books at start of game
    checkBooks(p2); //check possible books at start of game
    myfile << endl;

    printHands(p1, p2); //Starting display
    printBooks(p1, p2);
    myfile << endl;

    myfile << "[First Turn]" << endl;
    myfile << endl;
    if(p2.getMoveFirst()) {       //if p2 goes first, then do a turn before with p2
        playerTurn(p2, p1, d);
    }

    gameInProgress = true;
    while(gameInProgress) {   //game loops until 26 books formed
        myfile << endl;
        printHands(p1, p2); //display current hands and books every so often
        printBooks(p1, p2);
        myfile << endl;
        playerTurn(p1, p2, d);  //player 1
        if(isGameOver(p1, p2)) {
            gameInProgress = false;
        }
        else {
            playerTurn(p2, p1, d); //player 2
            if(isGameOver(p1, p2)) {
                gameInProgress = false;
            }
        }
    }

    myfile << endl;
    printHands(p1, p2); //final display (with nothing in hands, everything in books)
    printBooks(p1, p2);
    myfile << endl;

    determineWinner(p1, p2); // determine winner
    resetGame(p1, p2, d); //reset
    myfile.close();
    return EXIT_SUCCESS;
}

/* FUNCTION - void dealHand
 * deals numCards Cards from Deck to Player object
     o removes numCards Cards from Deck array
     o adds numCards Cards to Player hand
 precondition: requires a minimum of numCards Cards in Deck array
 postcondition: numCards Card are dealt
*/
void dealHand(Deck &d, Player &p, int numCards) {
    myfile << "** (Dealing Cards to " << p.getName() << ") **" << endl;
    for(int i = 0; i < numCards; i++) {
        p.addCard(d.dealCard());
    }
}

/* FUNCTION - void startup
 * Initializes the go fish game given two new players and a new deck
     o calls dealHand inside
 precondition: requires a reset p1, p2 and d deck
 postcondition: Initializes go fish game
*/

void startup(Player &p1, Player &p2, Deck &d) {
    int numCards = STARTING_NUM_CARDS;
    myfile << "** (Shuffling Deck - All 52 Cards) **" << endl;
    d.shuffle();
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    printHands(p1, p2);
    printBooks(p1, p2);
}

/* FUNCTION - void printHands
 * Prints the current hands of both players
     o prints p1 and then p2
 precondition: requires 2 Player object
 postcondition: displays all of cards to output file
*/
void printHands(const Player &p1, const Player &p2) {
    myfile << "<Displaying Hands>" << endl;
    myfile << p1.getName() << " has : " << p1.showHand() << endl;
    myfile << p2.getName() << " has : " << p2.showHand() << endl;
}


/* FUNCTION - void printBooks
 * Prints the current books of both players
     o prints p1 and then p2
 precondition: requires 2 Player object
 postcondition: displays all of cards that are booked to output file
*/

void printBooks(const Player &p1, const Player &p2) {
    myfile << "<Displaying Books>" << endl;
    myfile << p1.getName() << " has : " << p1.showBooks() << endl;
    myfile << p2.getName() << " has : " << p2.showBooks() << endl;
}

/* FUNCTION - void checkBooks
 * checks hand of player for books (multiple) and will book then if found
     o Works if multiple cards to book
 precondition: requires valid Player object
 postcondition: cards are removed from hand of current player and added to book vector
*/
void checkBooks(Player &currentPlayer) {
    Card outputCard1;
    Card outputCard2;
    bool searchForBook = true;
    while(searchForBook) {
        searchForBook = currentPlayer.checkHandForPair(outputCard1, outputCard2);
        if(searchForBook) {
            myfile << currentPlayer.getName() << " books two " << outputCard1.rankString(outputCard1.getRank()) << "'s"
                   << endl;
            currentPlayer.bookCards(outputCard1, outputCard2);
        }
    }
}

/* FUNCTION - void drawForTurns
 * determines which player will go first for game
     o Player who draws lower card from deck wins
     o Keeps on drawing until one player draws lower
     o Automatically shuffles deck as needed

 precondition: must be called before game initialized, 2 new valid player objects, and deck.
 postcondition: player object marked as first player, requires resetGame to reset objects
*/
void drawForTurns(Player &p1, Player &p2, Deck &d) {
    Card p1Card;
    Card p2Card;
    bool drawCard = true;
    while(drawCard) {
        p1Card = d.dealCard();
        myfile << p1.getName() << " drew " << p1Card << endl;
        p2Card = d.dealCard();
        myfile << p2.getName() << " drew " << p2Card << endl;
        if(p1Card.getRank() < p2Card.getRank()) {
            p1.setMoveFirst(true);
            myfile << p1.getName() << " goes first!" << endl;
            drawCard = false;
        }
        else if(p2Card.getRank() < p1Card.getRank()) {
            p2.setMoveFirst(true);
            myfile << p2.getName() << " goes first!" << endl;
            drawCard = false;
        }
        if(d.size() == 0) {
            myfile << "** (Shuffling Deck - All 52 Cards) **" << endl;
            d.shuffle();
        }
    }

}

/* FUNCTION - bool isGameOver
 * determines if the game is over
     o Game over if total books == 26 between both player objects

 precondition: Must be valid Player objects, to be used within a game.
 postcondition: returns bool, true if the game is over, false otherwise
*/
bool isGameOver(const Player &p1, const Player &p2) { //return true if all books formed
    bool isGameOver = false;
    if((p1.getBookSize()+p2.getBookSize()) == 26) {
        isGameOver = true;
    }
    return isGameOver;
}

/* FUNCTION - void playerTurn
 * Executes 1 turn of a player, following go fish rules
    o main player as first argument
    o other player as second argument
    o checks for books after turns
 precondition: Must be valid Player objects, to be used within a game and valid deck.
 postcondition: follows go fish rules, repeats if takes a card, and adjusts state after that
*/
void playerTurn(Player &currentPlayer, Player &otherPlayer, Deck &d) {
    Card drawCard;
    if(currentPlayer.getHandSize() > 0) {
        Card askCard;
        Card stealCard;
        askCard = currentPlayer.chooseCardFromHand();
        myfile << currentPlayer.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?"
               << endl;
        if(otherPlayer.sameRankInHand(askCard)) {
            myfile << otherPlayer.getName() << " says - Yes, I have a " << askCard.rankString(askCard.getRank())
                   << endl;
            stealCard = otherPlayer.removeSameRankFromHand(askCard);
            currentPlayer.addCard(stealCard);
            checkBooks(currentPlayer);
            playerTurn(currentPlayer, otherPlayer, d); // goes again
        }
        else {
            myfile << otherPlayer.getName() << " says - Go Fish" << endl; //go fish
            if(d.size() > 0) {
                drawCard = d.dealCard(); //draw from pool
                myfile << currentPlayer.getName() << " draws " << drawCard << endl;
                currentPlayer.addCard(drawCard);
                checkBooks(currentPlayer);
            }
            else {
                myfile << currentPlayer.getName() << " attempts to draw - pool empty!" << endl;
            }
        }
    }
    else {
        if(d.size() > 0) {
            drawCard = d.dealCard();
            myfile << currentPlayer.getName() << " draws " << drawCard << endl;
            currentPlayer.addCard(drawCard);  //draw from pool
            checkBooks(currentPlayer);
        }
        else {
            myfile << currentPlayer.getName() << " attempts to draw - pool empty!" << endl;
        }
    }

}

/* FUNCTION - void determineWinner
 * determines winner by counting who has more books
 precondition: Must be valid Player objects, to be used AFTER isGameOver is true;
 postcondition: outputs the winner and number of books to file output
*/
void determineWinner(const Player &p1, const Player &p2) {
    if(p1.getBookSize() > p2.getBookSize()) {
        myfile << p1.getName() << " won 'Go Fish!' with " << p1.getBookSize() << " Books!!!" << endl;
    }
    else if(p2.getBookSize() > p1.getBookSize()) {
        myfile << p2.getName() << " won 'Go Fish!' with " << p2.getBookSize() << " Books!!!" << endl;
    }
    else {
        myfile << "Tie game! Each player had 13 books!" << endl;
    }
}

/* FUNCTION - void resetGame
 * resets player objects and deck to be used again in a new game
 precondition: Must be valid Player objects
 postcondition: Resets Player objects, and resets deck
*/
void resetGame(Player &p1, Player &p2, Deck &d) {
    myfile << "[Resetting Status of Players and Deck]" << endl;
    p1.setMoveFirst(false);
    p2.setMoveFirst(false);
    p1.removeAllBooks();
    p2.removeAllBooks();
    myfile << "** (Shuffling Deck - All 52 Cards) **" << endl;
    d.shuffle();
}


