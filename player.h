// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08) (revised again 11/13/2020 by Eralp Orkun)
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

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;


class Player {
    public:
        Player(); //default constructor, shouldn't really be used (no name)


        Player(string name) { // player constructor, use player name as argument
            myName = name;
            moveFirst = false;
        }

        string getName() const { //return name
            return myName;
        }

        bool getMoveFirst() const { //return bool on whether moveFirst condition is true, used for turn order
            return moveFirst;
        }

        void setMoveFirst(bool first) { //set moveFirst condition, used for turn order
            moveFirst = first;
        }

        /* FUNCTION - void addCard
        * adds a card c to the player's hand
        *   o card is not removed
        precondition: Must be valid card object
        postcondition: card added to player's hand
        */
        void addCard(Card c);

        /* FUNCTION - void bookCards
        * takes c1 and c2 and books them from players hand
        *   o c1 and c2 are removed from hand
        *   o c1 and c2 are added to myBook
        precondition: c1 and c2 must be in hand
        postcondition: card added to mybook
        */

        void bookCards(Card c1, Card c2);

        /* FUNCTION - Card chooseCardFromHand
        * uses some strategy to choose one card from the player's
        * hand so they can say "Do you have a 4?"
        *   o uses strategy of picking different random cards to increase chances of match
        precondition: must have a card in hand to use function
        postcondition: card that is picked is returned
        */
        Card chooseCardFromHand() const;


        /* FUNCTION - Card removeCardFromHand
        * Remove the card c from the hand and return it to the caller
        *   o removes the card from player's hand
        *   o returns the removed card
        precondition: requires knowing if card exists in hand, exact card match
        postcondition: removes and returns card, otherwise returns error
        */
        Card removeCardFromHand(Card c);

        /* FUNCTION - Card removeSameRankFromHand
        * Remove the card with same rank as c from the hand and return it to the caller
        *   o removes the card from player's hand
        *   o returns the removed card
        precondition: requires knowing if card exists in hand, same rank as Card c
        postcondition: removes and returns card, otherwise returns error
        */
        Card removeSameRankFromHand(Card c);

        /* FUNCTION - string showHand
        * returns string of current hand of player
        *   o appends all cards together into string
        *   o returns the string
        precondition: requires valid player
        postcondition: returns hand string of all hands together
        */
        string showHand() const;

        /* FUNCTION - string showBooks
        * returns string of current book of player
        *   o appends all cards together into string
        *   o returns the string
        precondition: requires valid player
        postcondition: returns the book string of all books together
        */
        string showBooks() const;

        /* FUNCTION - int getHandSize
        * returns size of player hand
        precondition: requires valid player
        postcondition: returns number of cards in hand
        */
        int getHandSize() const;

        /* FUNCTION - int getBookSize
        * returns size of player hand
        precondition: requires valid player
        postcondition: returns number of cards in hand
        */
        int getBookSize() const;

        //this function will check a players hand for a pair.
        //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
        //Will ignore the exact same card as given as input (e.g 7d input and only 7d found returns false)

        bool checkHandForPair(Card &c1, Card &c2);

        //Does the player have a card with the same rank as c in her hand?
        //e.g. will return true if the player has a 7d and the parameter is 7c
        //Will ignore the exact same card as given as input (e.g 7d input and only 7d found returns false)

        bool sameRankInHand(Card c) const;

        //clear all books for player
        //pre: valid player
        //post: removes all books
        void removeAllBooks();


        //Unused & Commented out functions below:
        //
        //Does the player have the card c in her hand?
        // bool cardInHand(Card c) const;

        //OPTIONAL
        // comment out if you decide to not use it
        //this function will check a players hand for a pair.
        //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
        // bool checkHandForBook(Card &c1, Card &c2);

        //OPTIONAL
        // comment out if you decide to not use it
        //Does the player have a card with the same rank as c in her hand?
        // bool rankInHand(Card c) const;

    private:

        vector<Card> myHand; //vector of cards for hand in game
        vector<Card> myBook; //vector of cards for storing books in game
        bool moveFirst;  //whether player moves first
        string myName;  //name of player

};


#endif
