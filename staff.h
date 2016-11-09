// staff.h

#ifndef STAFF_H_INCLUDED
#define STAFF_H_INCLUDED

#include "constants.h"

struct Row {
        char c; // character
        char p; // pitch
        char pc; // pitch sharp
        int r; // range
        char pp; // double octave pitch
        char rp; // range for double pitch
        int i; // interval half step numbering
        int ic; // interval sharps
};

class Staff {
        public:
                Staff();
                
                void populate_bass(char staff[ROWS][COLS]);
                void populate_treble(char staff[ROWS][COLS]);
                void design(char key);
                void populate_staff(char display[ROWS][COLS]);
                Row get_row(int r);
                void transpose(char key);

        private:
                
                Row rows[ROWS];
};

#endif
