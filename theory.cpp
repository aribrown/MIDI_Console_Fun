// theory.cpp

#include<iostream>
using namespace std;

#include "constants.h"
#include "note.h"
#include "staff.h"
#include "theory.h"

Chord::Chord()
{
        tonic = 0;
        two = 0;
        three = 0;
        four = 0;
        five = 0;
        six = 0;
        sev = 0;
        n = 0;
}

CHORD Chord::populate_chord(int chord, char key,  char mode)
{
        staff.design(key);
        find_pitches(mode, key);
        if (chord == 1) {
                pop_I();
        }    
        if (chord == 2) {
                pop_ii();
        }    
        if (chord == 3) {
                pop_iii();
        }    
        if (chord == 4) {
                pop_IV();
        }    
        if (chord == 5) {
                pop_V();
        }    
        if (chord == 6) {
                pop_vi();
        }    
        if (chord == 7) {
                pop_vii();
        }    
        return c;
}
void Chord::find_pitches(char mode, char key) {
        for(int i = 0; i < ROWS; i++) {
                Row rr = staff.get_row(i);
                if (rr.p == key) {
                       tonic = rr.i; 
                }
                if (rr.pc == key) {
                       tonic = rr.ic;
                }
        }
        five = tonic + 7;
        if (mode == 'M') {
                three = tonic + 4; 
        }
        if (mode == 'm') {
                three = tonic + 3;
        }
        two = tonic + 2;
        four = tonic + 5;
        six = tonic + 9;
        sev = tonic + 11;

}
void Chord::pop_I()
{
        create_note(2, "tonic");
        create_note(3, "tonic");
        create_note(4, "tonic");
        create_note(4, "three");
        create_note(4, "five");

}
void Chord::pop_ii()
{
        create_note(2, "two");
        create_note(3, "two");
        create_note(4, "two");
        create_note(4, "four");
        create_note(4, "six");
}
void Chord::pop_iii()
{

        create_note(2, "three");
        create_note(3, "three");
        create_note(4, "three");
        create_note(4, "five");
        create_note(4, "sev");
}
void Chord::pop_IV()
{

        create_note(2, "four");
        create_note(3, "four");
        create_note(4, "four");
        create_note(4, "six");
        create_note(5, "tonic");
}
void Chord::pop_V()
{

        create_note(2, "five");
        create_note(3, "five");
        create_note(4, "five");
        create_note(4, "sev");
        create_note(5, "two");
}
void Chord::pop_vi()
{

        create_note(2, "six");
        create_note(3, "six");
        create_note(4, "six");
        create_note(5, "tonic");
        create_note(5, "three");
}
void Chord::pop_vii()
{

        create_note(2, "sev");
        create_note(3, "sev");
        create_note(4, "sev");
        create_note(5, "two");
        create_note(5, "four");
}

void Chord::create_note(int range, string scale_degree)
{     
        int var;
        if (scale_degree == "tonic") {
                var = tonic;
        }
        if (scale_degree == "two") {
                var = two;
        }
        if (scale_degree == "three") {
                var = three;
        }
        if (scale_degree == "four") {
                var = four;
        }
        if (scale_degree == "five") {
                var = five;
        }
        if (scale_degree == "six") {
                var = six;
        }
        if (scale_degree == "sev") {
                var = sev;
        }
        char character;
        bool sharp = false;
                for(int j = 0; j < ROWS; j++) {
                        Row rr = staff.get_row(j);
                        if (rr.ic == var) {
                                character = rr.pc;               
                        }
                        if (rr.i == var) {
                                character = rr.p;               
                        }
               }
        if (character == W 
                || character == EEE
                || character == T
                || character == Y
                || character == I
                || character == R
                || character == U
                || character == O
                || character == P){
                sharp = true;
               if (character == W) {
                        character = C;
               } 
               if (character == EEE) {
                        character = D;
               } 
               if (character == T) {
                        character = F;
               } 
               if (character == Y) {
                        character = G;
               }
               if (character == U) {
                        character = A;
               }
               if (character == O) {
                        character = CC;
               }
               if (character == P) {
                        character = DD;
               }
               if (character == R) {
                        character = E;
               }
               if (character == I) {
                        character = B;
                }
        }
        if (n < NN) {
                c.notes_of_chord[n].create(character, range , 1, sharp);
                n++;
        }
}
CHORD Chord::get_chord()
{
        return c;
}
