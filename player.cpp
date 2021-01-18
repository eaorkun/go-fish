//
// Created by Eralp on 11/11/2020.
//
// FILE:  player.cpp
// written by Eralp Orkun
// Date 11/13/2020)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks
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

#include "player.h"
#include <string>

Player::Player() { //default constructor, shouldn't really be used (no name)
    moveFirst = false;
}

/* FUNCTION - string showHand
* returns string of current hand of player
*   o appends all cards together into string
*   o returns the string
precondition: requires valid player
postcondition: returns hand string of all hands together
*/
string Player::showHand() const {
    string returnString;
    for(auto handCard : myHand) {
        returnString += handCard.toString()+", "; //append all cards into string, separated by comma
    }
    returnString[returnString.length()-2] = '\0'; //replace last comma with null char
    return returnString;
}

/* FUNCTION - string showBooks
* returns string of current book of player
*   o appends all cards together into string
*   o returns the string
precondition: requires valid player
postcondition: returns the book string of all books together
*/
string Player::showBooks() const {
    string dummyString;
    for(auto bookCard : myBook) {
        dummyString += bookCard.toString()+", "; //append all cards into string, separated by comma
    }
    dummyString[dummyString.length()-2] = '\0'; //replace last comma with null char
    return dummyString;
}

/* FUNCTION - void addCard
* adds a card c to the player's hand
*   o card is not removed
precondition: Must be valid card object
postcondition: card added to player's hand
*/
void Player::addCard(Card c) {
    myHand.push_back(c);
}

/* FUNCTION - void bookCards
* takes c1 and c2 and books them from players hand
*   o c1 and c2 are removed from hand
*   o c1 and c2 are added to myBook
precondition: c1 and c2 must be in hand
postcondition: card added to mybook
*/

void Player::bookCards(Card c1, Card c2) {
    Card book1;
    Card book2;
    book1 = removeCardFromHand(c1); //remove from hands
    book2 = removeCardFromHand(c2);
    myBook.push_back(book1); //add to book
    myBook.push_back(book2);
}

/* FUNCTION - Card chooseCardFromHand
* uses some strategy to choose one card from the player's
* hand so they can say "Do you have a 4?"
*   o uses strategy of picking different random cards to increase chances of match
precondition: must have a card in hand to use function
postcondition: card that is picked is returned
*/
Card Player::chooseCardFromHand() const {
    int random;
    random = rand()%myHand.size(); // num from 0 to size-1
    return myHand.at(random);;
}


/* FUNCTION - Card removeCardFromHand
* Remove the card c from the hand and return it to the caller
*   o removes the card from player's hand
*   o returns the removed card
precondition: requires knowing if card exists in hand, exact card match
postcondition: removes and returns card, otherwise returns error
*/
Card Player::removeCardFromHand(Card c) {
    Card returnCard(-1, Card::spades); //returns error card if not found
    int count = 0;
    for(auto handCard : myHand) { //check cards in hand
        if(handCard == c) { //if card is equal to search
            returnCard = handCard;
            myHand.erase(myHand.begin()+count); //index
            break;
        }
        count++;
    }
    return returnCard;
}

/* FUNCTION - Card removeSameRankFromHand
* Remove the card with same rank as c from the hand and return it to the caller
*   o removes the card from player's hand
*   o returns the removed card
precondition: requires knowing if card exists in hand, same rank as Card c
postcondition: removes and returns card, otherwise returns error
*/
Card Player::removeSameRankFromHand(Card c) {
    Card returnCard(-1, Card::spades); //returns error card if not found
    int count = 0;
    for(auto handCard : myHand) {
        if(handCard.getRank() == c.getRank()) { //if rank of card is equal to search rank
            returnCard = handCard;
            myHand.erase(myHand.begin()+count); //index
            break;
        }
        count++;
    }
    return returnCard;
}

/* FUNCTION - int getHandSize
* returns size of player hand
precondition: requires valid player
postcondition: returns number of cards in hand
*/

int Player::getHandSize() const {
    return myHand.size();
}

/* FUNCTION - int getBookSize
* returns size of player hand
precondition: requires valid player
postcondition: returns number of cards in hand
*/
int Player::getBookSize() const {
    int numBooks = myBook.size();
    numBooks = numBooks/2; // num cards /2 == numBooks
    return numBooks;
}

//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
//Will ignore the exact same card as given as input (e.g 7d input and only 7d found returns false)
bool Player::checkHandForPair(Card &c1, Card &c2) {
    bool pairInHand = false;
    for(auto handCard : myHand) { //outer loop
        if(sameRankInHand(handCard) == true) {
            for(auto cmpCard : myHand) { //inner loop
                if((handCard != cmpCard) && (handCard.getRank() == cmpCard.getRank())) { //if no duplicate & rank match
                    c1 = handCard;
                    c2 = cmpCard;
                    pairInHand = true;
                    break; //break from inner loop
                }
            }
        }
        if(pairInHand) {
            break; //break from outer loop
        }
    }
    return pairInHand; //return
}

//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c
//Will ignore the exact same card as given as input (e.g 7d input and only 7d found returns false)
bool Player::sameRankInHand(Card c) const {
    bool sameRank = false;
    for(auto handCard : myHand) { //check each card in hand
        if((c != handCard) && (c.getRank() == handCard.getRank())) { //if not duplicate and rank match
            sameRank = true;
            break;
        }
    }
    return sameRank;
}

//clear all books for player
//pre: valid player
//post: removes all books
void Player::removeAllBooks() {
    myBook.clear();
}