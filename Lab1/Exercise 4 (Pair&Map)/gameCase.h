#pragma once
//Assume you are developing a game and you have class Position that has x and y
//coordinates and a class hierarchy that has Creature as base class and Monster, Dragon,
//Solider and Player as derived classes.
//a.Show how to declare an object of class myMap to map each creature to a position in
//the game.
//b.What are the necessary updates for the above classes for myPair / myMap member
//functions to operate on them ?

// No chnages in pair , map 
//Every user-difined class needs operator overloading of = , == , << most of the cases 


//Game classes from ChatGPT

#include <iostream>
#include <string>
using namespace std;

// Position class to represent coordinates
class Position {
private:
    int x, y;

public:
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // Getter methods
    int getX() const { return x; }
    int getY() const { return y; }

    // Setter methods
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }

    // Overload == operator for comparison
    bool operator==(const Position& other) const {
        return (x == other.x) && (y == other.y);
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& os, const Position& pos) { //<------------------------ Important for print
        os << "(" << pos.x << ", " << pos.y << ")";
        return os;
    }
};

// Creature base class
class Creature {
private:
    string name;

public:
    Creature()
    {

    }
    Creature(const string& name) : name(name) {}

    // Getter for name
    string getName() const { return name; }

    // Overload == operator for comparison
    bool operator==(const Creature& other) const {
        return name == other.name;
    }

    // Overload << operator for printing
    friend ostream& operator<<(ostream& os, const Creature& creature) { //<------------------------ Important for print
        os << creature.name;
        return os;
    }
};

// Derived classes: Monster, Dragon, Soldier, Player
class Monster : public Creature {
public:
    Monster(const string& name) : Creature(name) {}
};

class Dragon : public Creature {
public:
    Dragon(const string& name) : Creature(name) {}
};

class Soldier : public Creature {
public:
    Soldier(const string& name) : Creature(name) {}
};

class Player : public Creature {
public:
    Player(const string& name) : Creature(name) {}
};