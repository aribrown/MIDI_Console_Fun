// constants
//
#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

const int LEDGERS = 6;
const int STAFF_SIZE = 9;
const int MIDDLE = 3;

const int COLS = 203;
const int ROWS = (LEDGERS*2) + (STAFF_SIZE*2) + MIDDLE;

const char L_NOTE = 'O';
const char S_NOTE = '@';
const char BARLINE = '|';
const char STEM = '|';
const char TAIL_EIGHT = '_';
const char TAIL_SIX = '=';

const float WHOLE_VAL = 4;
const float HALF_VAL = 2;
const float DOTTED = 1.5;
const float QUARTER_VAL = 1;
const float EIGHTH_VAL = 0.5;
const float SIXTEENTH_VAL = 0.25;
const int STEM_LENGTH = 2;

const char C = 'a';
const char D = 's';
const char E = 'd';
const char F = 'f';
const char G = 'g';
const char A = 'h';
const char B = 'j';
const char CC = 'k';
const char DD = 'l';
const char EE = ';';
// sharps/flats
const char W = 'w';
const char EEE = 'e';
const char R = 'r';
const char I = 'i';
const char T = 't';
const char Y = 'y';
const char U = 'u';
const char O = 'o';
const char P = 'p';
const char SHARP = '#';

const char X = 'x';
const char Z = 'z';
const char N = 'n';
const char M = 'm';

const int TIMESTEP = 150000;

const char SPACE = ' ';
const char LINE = '-';
const char LEDGE = '-';
const char DOT = '.';

const int NN = 8;
const int NUM_NOTES = 50;
const int NUM_CHORDS = 30;
const int POS_INCREMENT = 8;
const int TIMESIG = 4;

const char SENTINEL = '~';
const char CHORD_BUILDER = 's';
const char MELODY_BUILDER = 'a';
const char AI = 'd';

const char LS = '_';
const char S = '/';
const char RS = '\\';
const char US = '|';
#endif
