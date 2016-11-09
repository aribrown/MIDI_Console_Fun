// main implimentation
//
#include<iostream>
using namespace std;

#include "staff.h"
#include "note.h"
#include "constants.h"
#include "termfuncs.h"
#include "compose.h"

int main() {
        screen_clear();
        Composition ari;
        char k;
        k = ari.rules();
        ari.compose_music(k); // c major character
        return 0;
}
