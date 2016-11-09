// note.h

#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include "constants.h"
#include "staff.h"

class Note {
        public:
                Note();

                void create(char tone, int range, float val, bool acc);
                void place_note(char staff[ROWS][COLS], Staff s, int position);
                void initialize_note();
                char get_char();
                float get_val();


        private:
                char pitch;
                int octave;
                float value;
                char head;
                bool stem_bool;
                bool tail_bool;
                bool dot_bool;
                char stem;
                char tail;
                char dot;
                bool sharp;
};

#endif
