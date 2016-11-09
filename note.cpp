// note.cpp
//
#include<iostream>
using namespace std;

#include "constants.h"
#include "note.h"
#include "staff.h"

Note::Note()
{
        initialize_note();             
}

void Note::create(char tone, int range, float val, bool acc)
{
        if (val == WHOLE_VAL) {
                value = WHOLE_VAL;
        }
        if (val == HALF_VAL) {
                value = HALF_VAL;
                stem_bool = true;
        }
        if (val == QUARTER_VAL) {
                value = QUARTER_VAL;
                head = S_NOTE;
                stem_bool = true;
        }
        if (val == EIGHTH_VAL) {
                value = EIGHTH_VAL;
                head = S_NOTE;
                stem_bool = true;
                tail_bool = true;
        }
        if (val == SIXTEENTH_VAL) {
                value = SIXTEENTH_VAL;
                head = S_NOTE;
                stem_bool = true;
                tail_bool = true;
                tail = TAIL_SIX;
        }
        if (val == WHOLE_VAL*DOTTED) {
                value = WHOLE_VAL*DOTTED;
                dot_bool = true;
        }
        if (val == HALF_VAL*DOTTED) {
                value = HALF_VAL*DOTTED;
                stem_bool = true;
                dot_bool = true;
        }
        if (val == QUARTER_VAL*DOTTED) {
                value = QUARTER_VAL*DOTTED;
                head = S_NOTE;
                stem_bool = true;
                dot_bool = true;
        }
        if (val == EIGHTH_VAL*DOTTED) {
                value = EIGHTH_VAL*DOTTED;
                head = S_NOTE;
                stem_bool = true;
                tail_bool = true;
                dot_bool = true;
        }
        if (val == SIXTEENTH_VAL*DOTTED) {
                value = SIXTEENTH_VAL*DOTTED;
                head = S_NOTE;
                stem_bool = true;
                tail_bool = true;
                tail = TAIL_SIX;
                dot_bool = true;
        }
        octave = range;
        pitch = tone;
        sharp = acc;

}

void Note::initialize_note()
{
        pitch = C;
        octave = 4;
        value = 0;
        head = L_NOTE;
        stem_bool = false;
        tail_bool = false;
        dot_bool = false;
        stem = STEM;
        tail = TAIL_EIGHT;
        dot = DOT; 
        sharp = false;
}

void Note::place_note(char staff[ROWS][COLS], Staff s, int position)
{
        for (int r = 0; r < ROWS; r++) {
                Row rr = s.get_row(r);
                if ((pitch == rr.p && octave == rr.r)
                                ||(pitch == rr.pp && octave == rr.rp)) {
                        if (staff[r+1][position] == head ||
                                        staff[r-1][position] == head) {
                                position+= 2;
                        }
                        staff[r][position] = head;
                        if (staff[r+1][position -2] != head
                                        && staff[r-1][position -2] != head) {
                                if (stem_bool) {
                                        staff[r][position + 1] = stem;
                                        staff[r-1][position + 1] = stem;
                                }
                                if (tail_bool) {
                                        staff[r-2][position + 2] = tail;
                                }
                                if (dot_bool) {
                                        staff[r][position + 2] = dot;
                                }
                        }

                        // LEDGER LINES
                        if (pitch == C && octave == 4) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                        }
                        if (pitch == CC && octave == 5) {
                                if (staff[r+2][position] != head){
                                staff[r+2][position] = LEDGE;
                                staff[r+2][position+1] = LEDGE;
                                }
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                        }
                        if (pitch == CC && octave == 3) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                        }
                        if (pitch == A && octave == 5) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                        }
                        if (pitch == B && octave == 5) {
                                if (staff[r+1][position] != head){
                                staff[r+1][position] = LEDGE;
                                staff[r+1][position+1] = LEDGE;
                                }
                        }
                        if (pitch == C && octave == 6) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r+2][position] != head){
                                staff[r+2][position] = LEDGE;
                                staff[r+2][position+1] = LEDGE;
                                }
                        }
                        if (pitch == D && octave == 6) {
                                if (staff[r+3][position] != head){ 
                                staff[r+3][position+1] = LEDGE;
                                staff[r+3][position] = LEDGE;
                                }
                                if (staff[r+1][position] != head){ 
                                staff[r+1][position] = LEDGE;
                                staff[r+1][position+1] = LEDGE;
                                }
                        }
                        if (pitch == DD && octave == 5) {
                                if (staff[r+3][position] != head){ 
                                staff[r+3][position+1] = LEDGE;
                                staff[r+3][position] = LEDGE;
                                }
                                if (staff[r+1][position] != head){
                                staff[r+1][position] = LEDGE;
                                staff[r+1][position+1] = LEDGE;
                                }
                        }
                       if (pitch == E && octave == 6) { 
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r+2][position] != head){ 
                                staff[r+2][position] = LEDGE;
                                staff[r+2][position+1] = LEDGE;
                                }
                                if (staff[r+4][position] != head){ 
                                staff[r+4][position] = LEDGE;
                                staff[r+4][position+1] = LEDGE;
                                }
                       }
                       if (pitch == EE && octave == 5) { 
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r+2][position] != head){ 
                                staff[r+2][position] = LEDGE;
                                staff[r+2][position+1] = LEDGE;
                                }
                                if (staff[r+4][position] != head){ 
                                staff[r+4][position] = LEDGE;
                                staff[r+4][position+1] = LEDGE;
                                }
                       }
                       if (pitch == E && octave == 2) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                       }
                       if (pitch == EE && octave == 1) {
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                       }
                       if (pitch == D && octave == 2) { 
                                if (staff[r-1][position] != head){ 
                                staff[r-1][position] = LEDGE;
                                staff[r-1][position-1] = LEDGE;
                                }
                       }
                       if (pitch == DD && octave == 1) { 
                                if (staff[r-1][position] != head){ 
                                staff[r-1][position] = LEDGE;
                                staff[r-1][position-1] = LEDGE;
                                }
                       }
                       if (pitch == C && octave == 2) { 
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r-2][position] != head){ 
                                staff[r-2][position] = LEDGE;
                                staff[r-2][position-1] = LEDGE;
                                }
                       }
                       if (pitch == CC && octave == 1) { 
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r-2][position] != head){ 
                                staff[r-2][position] = LEDGE;
                                staff[r-2][position-1] = LEDGE;
                                }
                       }
                       if (pitch == B && octave == 1) { 
                                if (staff[r-1][position] != stem) { 
                                staff[r-1][position] = LEDGE;
                                staff[r-1][position-1] = LEDGE;
                                }
                                if (staff[r-3][position] != stem) { 
                                staff[r-3][position] = LEDGE;
                                staff[r-3][position-1] = LEDGE;
                                }
                       }
                       if (pitch == A && octave == 1) { 
                                if (staff[r][position-1] != stem) { 
                                staff[r][position-1] = LEDGE;
                                }
                                staff[r][position+1] = LEDGE;
                                if (staff[r-2][position] != stem) { 
                                staff[r-2][position] = LEDGE;
                                staff[r-2][position-1] = LEDGE;
                                }
                                if (staff[r-4][position] != stem) { 
                                staff[r-4][position] = LEDGE;
                                staff[r-4][position-1] = LEDGE;
                                }
                       }

                       // SHAPRS
                       if (sharp) {
                                if (staff[r+1][position-2] == head ||
                                               staff[r-1][position-2] == head) {
                                        staff[r][position - 4] = SHARP;
                                }
                                else {
                                staff[r][position - 2] = SHARP;
                                }
                       }

                }
        }        
}

float Note::get_val()
{
        return value;
}

char Note::get_char()
{
        return pitch;
}
