//
// Created by Eralp on 11/11/2020.
//
// FILE: deck.cpp
// written by Eralp Orkun
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

#include "deck.h"

using namespace std;

// pristine, sorted deck
// creates deck with 52 cards ordered
Deck::Deck() {
    myIndex = SIZE;
    for(int i = 0; i < 13; i++) { //all ranks
        Card::Suit cardSuit;
        for(int j = 0; j < 4; j++) { //each suite
            switch(j) {
                case 0:
                    cardSuit = Card::spades;
                    break;
                case 1:
                    cardSuit = Card::hearts;
                    break;
                case 2:
                    cardSuit = Card::diamonds;
                    break;
                case 3:
                    cardSuit = Card::clubs;
                    break;
                default:
                    break;
            }
            Card deckCard((i+1), cardSuit); //create card for each rank and suit
            myCards[i+13*j] = deckCard; //add to array
        }
    }
}

//shuffles the deck
//restores cards to filled deck
//and shuffles
void Deck::shuffle() {
    myIndex = SIZE; //reset deck to full
    srand(time(nullptr)); // for random
    Card temporary;
    int random;
    for(int i = 0; i < SIZE; i++) { // iterate each card in deck
        random = rand()%SIZE;
        temporary = myCards[i]; //save current
        myCards[i] = myCards[random]; // swap with random index
        myCards[random] = temporary; // swap
    }
}

//removes top card from deck
//returns the Card
//decreases index
// if fail returns error card
Card Deck::dealCard() {
    if(myIndex > 0) {
        myIndex--;
        return myCards[myIndex];
    }
    else {
        Card failure(-1, Card::spades); //error card
        return failure;
    }
}

//return size of Deck
int Deck::size() const {
    return myIndex;
}


