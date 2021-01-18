//
// Created by Eralp on 11/11/2020.
//
//card.cpp file
//EE 312


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

#include "card.h"

//default constructor
Card::Card() {
    myRank = 1;
    mySuit = spades;
}

//constructor to initialize rank and Suit
Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

//returns card rank and suit together as string
string Card::toString() const {
    return rankString(myRank)+suitString(mySuit);
}

// compares two cards to see if suit is the same
// true if suit of Card is the same as c
bool Card::sameSuitAs(const Card &c) const {
    bool sameSuit = true;
    if(mySuit != c.mySuit) {
        sameSuit = false;
    }
    return sameSuit;
}

// return rank, 1..13 as int value
int Card::getRank() const {
    return myRank;
}


// return "s", "h",... based on suit Type
string Card::suitString(Card::Suit s) const {
    string returnString;
    switch(s) {
        case spades:
            returnString = "s";
            break;
        case hearts:
            returnString = "h";
            break;
        case diamonds:
            returnString = "d";
            break;
        case clubs:
            returnString = "c";
            break;
        default:
            break;
    }
    return returnString;
}

// return "A", "2", ..."Q" based on integer rank
string Card::rankString(int r) const {
    string returnString;
    switch(r) {
        case 1:
            returnString = "A";
            break;
        case 2:
            returnString = "2";
            break;
        case 3:
            returnString = "3";
            break;
        case 4:
            returnString = "4";
            break;
        case 5:
            returnString = "5";
            break;
        case 6:
            returnString = "6";
            break;
        case 7:
            returnString = "7";
            break;
        case 8:
            returnString = "8";
            break;
        case 9:
            returnString = "9";
            break;
        case 10:
            returnString = "10";
            break;
        case 11:
            returnString = "J";
            break;
        case 12:
            returnString = "Q";
            break;
        case 13:
            returnString = "K";
            break;
        default:
            break;
    }
    return returnString;
}

//overloaded equality
//rank and suit must be equal
bool Card::operator==(const Card &rhs) const {
    bool cardsEqual = true;
    if((getRank() != rhs.getRank()) || (!sameSuitAs(rhs))) { //if one of these is false, then cards not equal
        cardsEqual = false;
    }
    return cardsEqual;
}

//overloaded inequality
//fails if rank and suit is equal
bool Card::operator!=(const Card &rhs) const {
    bool cardsNotEqual = true;
    if((getRank() == rhs.getRank()) && (sameSuitAs(rhs))) { //if equal, then inequal is false
        cardsNotEqual = false;
    }
    return cardsNotEqual;
}

//overloaded for output so you can output Card directly
ostream &operator<<(ostream &out, const Card &c) {
    out<<c.toString(); // e.g. 5s
    return out;
}