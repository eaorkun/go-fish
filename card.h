//File Name: card.h
//
//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13
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

#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>

using namespace std;


class Card {
    public:

        enum Suit { //Suit of Card
            spades, hearts, diamonds, clubs
        };

        Card();          // default, ace of spades

        Card(int rank, Suit s);  //Create card with given rank and Suit

        string toString() const;  // return string version e.g. Ac 4h Js

        bool sameSuitAs(const Card &c) const;  // true if suit same as c

        int getRank() const;  // return rank, 1..13

        string suitString(Suit s) const;  // return "s", "h",...

        string rankString(int r) const;  // return "A", "2", ..."Q"

        bool operator==(const Card &rhs) const; //overloaded to compare Cards
        bool operator!=(const Card &rhs) const; //overload inequality to compare Cards


    private:

        int myRank;
        Suit mySuit;


};

ostream &operator<<(ostream &out, const Card &c); // overload to output, outputs toString of card


#endif
