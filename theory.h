// theory.h

#ifndef THEORY_H_INCLUDED
#define THEORY_H_INCLUDED

#include "constants.h" 
#include "note.h"
#include "staff.h"

struct Interval {
        int n1;
        int n2;
        int distance;
};
struct CHORD {
        Note notes_of_chord[NN];
//        Interval intervals[NN -1];
};


class Chord {

        public:
                Chord();
                CHORD populate_chord(int chord, char key, char mode);
                void pop_I();
                void pop_ii();
                void pop_iii();
                void pop_IV();
                void pop_V();
                void pop_vi();
                void pop_vii();
                void create_note(int range, string scale_degree);
                void find_pitches(char mode, char key);
                CHORD get_chord();

        private:
                
                CHORD c;
                int tonic;
                int two;
                int three;
                int four;
                int five;
                int six;
                int sev;
                int n;
                Staff staff;
};

#endif
