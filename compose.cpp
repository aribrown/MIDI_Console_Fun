// compose.cpp
//
#include<iostream>
#include<unistd.h>
using namespace std;

#include "constants.h"
#include "compose.h"
#include "note.h"
#include "staff.h"
#include "termfuncs.h"
#include "theory.h"

Composition::Composition()
{
        staff.design(C);
        staff.populate_staff(display);
        position = 18;
        start_pos = position;
        note_num = 0;
        oct = 4;
        time = 1;
        measure_duration = 0;
        print();
        wrap = false;
}

void Composition::print()
{
        for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                        cout << display[r][c];
                }
//                Row rr = staff.get_row(r);     // test transposition
 //               cout << rr.i << " " << rr.ic << " " << rr.pc;
                cout << endl;
        }
}

void Composition::compose_music(char key)
{

        staff.design(key);
        staff.populate_staff(display);
        if (program == MELODY_BUILDER || program == CHORD_BUILDER) {
        while (true) { 
                
        char character = getachar();
        if (program == MELODY_BUILDER) {
                usleep(TIMESTEP * 0.75);

        }
        if (program == CHORD_BUILDER){
                usleep(TIMESTEP);
        }
        if (character == SENTINEL) {
                break;
        }
        if (wrap) {
                position = start_pos;
                staff.populate_staff(display);
                wrap = false;
        }
        if ((character == A
                        || character == B
                        || character == C
                        || character == D
                        || character == E
                        || character == F
                        || character == G
                        || character == CC
                        || character == DD
                        || character == EE 
                        || character == W
                        || character == EEE
                        || character == T
                        || character == Y
                        || character == U
                        || character == I
                        || character == R
                        || character == O
                        || character == P)){
                bool sharp = false;
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
                notes[note_num].create(character, oct, time, sharp);
                if (program == MELODY_BUILDER) {position += POS_INCREMENT;}
                notes[note_num].place_note(display, staff, position); 
                measure_duration += notes[note_num].get_val();
                if (measure_duration >= TIMESIG) {
                        position += POS_INCREMENT;
                        if (program == MELODY_BUILDER) {
                        for (int r = LEDGERS; r < ROWS - LEDGERS; r++) {
                                display[r][position] = BARLINE;
                        }
                        }
                        measure_duration = 0;
                }
                if (COLS-position < TIMESIG*POS_INCREMENT){
                        screen_home();
                        print();
                        screen_clear();
                        print();
                        wrap = true;
                }
                note_num++;
                if (note_num == NUM_NOTES) {
                        note_num = 0;
                }
        }
        if (character == X && oct < 6) {oct++;}
        if (character == Z && oct > 1) {oct--;}
        if (character == M && time <= 4) {time++;}
        if (character == N && time >= 0.25) {time = time - 0.25;}
                screen_home();
                print();
        }
        }
        if (program == AI) {
                while (true) {
                for (int deg = 1; deg < 8; deg++) {
                for (int i = 0; i < NN; i++) {
                        chords[deg-1].populate_chord(deg, key,'M');
                        CHORD c = chords[deg-1].get_chord();
                        notes[i] = c.notes_of_chord[i];
                        notes[i].place_note(display, staff, position); 
                }
                if (wrap) {
                        position = start_pos;
                        staff.populate_staff(display);
                        wrap = false;
                }       
                if (COLS-position < TIMESIG*POS_INCREMENT){
                        screen_home();
                        print();
                        screen_clear();
                        print();
                        wrap = true;
                }
                screen_home();
                print();
                usleep(TIMESTEP);
                position += POS_INCREMENT;
                }
                }
                
        }
}

char Composition::rules()
{
        screen_clear();
        cout << endl << endl << endl;
        cout << "                  Welcome to Ari's Composition!" <<
                endl << endl;
        cout << "     The keyboard is in piano format. Press keys to create music."
                << endl;
        cout << endl <<"         " << X
                << " (Up Octave)                      " <<
                Y << " (Down Octave)" << endl;
        cout <<"         "<< N
                << " (Shorter Note Duration)          " <<
                M << " (Longer Note Duration)" << endl;

        cout << endl << "     PRESS:" << endl;
        cout << "                     ("<<
                MELODY_BUILDER << ") MELODY BUILDER" << endl;
        cout << "                     ("<<
                CHORD_BUILDER << ") CHORD BUILDER" << endl;
        cout << "                     ("<<
                AI << ") AI" << endl;
        program = getachar();
        place_cursor(20, 10);
        cout << "Key? ";
        char keyy;
        keyy = getachar();
        screen_clear();
        print ();
        return keyy;
}       
