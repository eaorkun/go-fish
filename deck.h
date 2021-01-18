// FILE: deck.h
// written by Owen Astrachan, Roger Priebe and Michael Yang AND ERALP ORKUN (now on 11/13/2020)
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.
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


#ifndef _DECK_H
#define _DECK_H

#include <array>
#include "card.h"


using namespace std;


class Deck {
        static constexpr int SIZE = 52;

    public:


        Deck();           // pristine, sorted deck

        void shuffle();   // shuffle the deck, all 52 cards present
        Card dealCard();   // get a card, after 52 are dealt, fail

        int size() const; // # cards left in the deck

    private:

        array<Card, SIZE> myCards;
        int myIndex;  // current card to deal
};

#endif
