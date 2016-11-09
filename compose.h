// compose.h

#ifndef COMPOSE_H_INCLUDED
#define COMPOSE_H_INCLUDED

#include "constants.h"
#include "staff.h"
#include "note.h"
#include "theory.h"


class Composition {
        public:
                Composition();

                char rules(); // returns key
                void print();
                void compose_music(char key);


        private:
                char display[ROWS][COLS];
                Staff staff;
                Note notes[NUM_NOTES];
                Chord chords[NUM_CHORDS];

                int position;
                int note_num;
                int measure_duration;
                float time;
                int oct;
                int start_pos;
                bool wrap;
                char program;
};      

#endif
