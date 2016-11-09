// staff.cpp
//
#include<iostream>
using namespace std;

#include "staff.h"
#include "constants.h"

Staff::Staff()
{
        for (int i = 0; i < ROWS; i++) {
                rows[i].c = ' ';
                rows[i].p = ' ';
                rows[i].pc = ' ';
                rows[i].r = 0;
                rows[i].pp = ' ';
                rows[i].rp = ' ';
                rows[i].i = 0;
                rows[i].ic = 0;
        }
}

void Staff::populate_staff(char display[ROWS][COLS])
{
        for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                        display[r][c] = rows[r].c;
                }
        }
        populate_treble(display);
        populate_bass(display);
}

Row Staff::get_row(int r)
{
        return rows[r];
}

void Staff::design(char key)
{
        rows[ROWS/2].c = SPACE;
        rows[(ROWS/2)-1].c = SPACE;
        rows[(ROWS/2)+1].c = SPACE;
        for (int r = (ROWS/2)+2; r < ((ROWS/2)+2)+STAFF_SIZE; r++) {
                if (r%2 == 0) {rows[r].c = LINE;}
                else {rows[r].c = SPACE;}
        }
        for (int r = (ROWS/2)-2; r > ((ROWS/2)-2)-STAFF_SIZE; r--) {
                if (r%2 == 0) {rows[r].c = LINE;}
                else {rows[r].c = SPACE;}
        }
        for (int r = ((ROWS/2)+2)+STAFF_SIZE;
                        r < ((ROWS/2)+2)+STAFF_SIZE+LEDGERS;
                        r++){
                rows[r].c = SPACE;
        }
        for (int r = ((ROWS/2)-2)-STAFF_SIZE;
                        r > ((ROWS/2)-2)-STAFF_SIZE-LEDGERS;
                        r--){
                rows[r].c = SPACE;
        }
        rows[ROWS/2].pp = CC;
        rows[(ROWS/2)-1].pp = DD;
        rows[(ROWS/2)-2].pp = EE;
        rows[ROWS/2].p = C;
        rows[(ROWS/2)-1].p = D;
        rows[(ROWS/2)-2].p = E;
        rows[(ROWS/2)-3].p = F;
        rows[(ROWS/2)-4].p = G;
        rows[(ROWS/2)-5].p = A;
        rows[(ROWS/2)-6].p = B;
        rows[(ROWS/2)-7].pp = CC;
        rows[(ROWS/2)-8].pp = DD;
        rows[(ROWS/2)-9].pp = EE;
        rows[(ROWS/2)-7].p = C;
        rows[(ROWS/2)-8].p = D;
        rows[(ROWS/2)-9].p = E;
        rows[(ROWS/2)-10].p = F;
        rows[(ROWS/2)-11].p = G;
        rows[(ROWS/2)-12].p = A;
        rows[(ROWS/2)-13].p = B;
        rows[(ROWS/2)-14].pp = CC;
        rows[(ROWS/2)-15].pp = DD;
        rows[(ROWS/2)-16].pp = EE;
        rows[(ROWS/2)-14].p = C;
        rows[(ROWS/2)-15].p = D;
        rows[(ROWS/2)-16].p = E;
        
        rows[(ROWS/2)+1].p = B;
        rows[(ROWS/2)+2].p = A;
        rows[(ROWS/2)+3].p = G;
        rows[(ROWS/2)+4].p = F;
        rows[(ROWS/2)+5].pp = EE;
        rows[(ROWS/2)+6].pp = DD;
        rows[(ROWS/2)+7].pp = CC;
        rows[(ROWS/2)+5].p = E;
        rows[(ROWS/2)+6].p = D;
        rows[(ROWS/2)+7].p = C;
        rows[(ROWS/2)+8].p = B;
        rows[(ROWS/2)+9].p = A;
        rows[(ROWS/2)+10].p = G;
        rows[(ROWS/2)+11].p = F;
        rows[(ROWS/2)+12].pp = EE;
        rows[(ROWS/2)+13].pp = DD;
        rows[(ROWS/2)+14].pp = CC;
        rows[(ROWS/2)+12].p = E;
        rows[(ROWS/2)+13].p = D;
        rows[(ROWS/2)+14].p = C;
        rows[(ROWS/2)+15].p = B;
        rows[(ROWS/2)+16].p = A;

        rows[ROWS/2].pc = W;
        rows[(ROWS/2)-1].pc = EEE;
        rows[(ROWS/2)-2].pc = R;
        rows[(ROWS/2)-3].pc = T;
        rows[(ROWS/2)-4].pc = Y;
        rows[(ROWS/2)-5].pc = U;
        rows[(ROWS/2)-6].pc = I;
        rows[(ROWS/2)-7].pc = W;
        rows[(ROWS/2)-8].pc = EEE;
        rows[(ROWS/2)-9].pc = R;
        rows[(ROWS/2)-10].pc = T;
        rows[(ROWS/2)-11].pc = Y;
        rows[(ROWS/2)-12].pc = U;
        rows[(ROWS/2)-13].pc = I;
        rows[(ROWS/2)-14].pc = W;
        rows[(ROWS/2)-15].pc = EEE;
        rows[(ROWS/2)-16].pc = R;
        
        rows[(ROWS/2)+1].pc = I;
        rows[(ROWS/2)+2].pc = U;
        rows[(ROWS/2)+3].pc = Y;
        rows[(ROWS/2)+4].pc = T;
        rows[(ROWS/2)+5].pc = R;
        rows[(ROWS/2)+6].pc = EEE;
        rows[(ROWS/2)+7].pc = W;
        rows[(ROWS/2)+8].pc = I;
        rows[(ROWS/2)+9].pc = U;
        rows[(ROWS/2)+10].pc = Y;
        rows[(ROWS/2)+11].pc = T;
        rows[(ROWS/2)+12].pc = R;
        rows[(ROWS/2)+13].pc = EEE;
        rows[(ROWS/2)+14].pc = W;
        rows[(ROWS/2)+15].pc = I;
        rows[(ROWS/2)+16].pc = U;
        
        rows[ROWS/2].rp = 3;
        rows[(ROWS/2)-1].rp = 3;
        rows[(ROWS/2)-2].rp = 3;
        rows[ROWS/2].r = 4;
        rows[(ROWS/2)-1].r = 4;
        rows[(ROWS/2)-2].r = 4;
        rows[(ROWS/2)-3].r = 4;
        rows[(ROWS/2)-4].r = 4;
        rows[(ROWS/2)-5].r = 4;
        rows[(ROWS/2)-6].r = 4;
        rows[(ROWS/2)-7].rp = 4;
        rows[(ROWS/2)-8].rp = 4;
        rows[(ROWS/2)-9].rp = 4;
        rows[(ROWS/2)-7].r = 5;
        rows[(ROWS/2)-8].r = 5;
        rows[(ROWS/2)-9].r = 5;
        rows[(ROWS/2)-10].r = 5;
        rows[(ROWS/2)-11].r = 5;
        rows[(ROWS/2)-12].r = 5;
        rows[(ROWS/2)-13].r = 5;
        rows[(ROWS/2)-14].rp = 5;
        rows[(ROWS/2)-15].rp = 5;
        rows[(ROWS/2)-16].rp = 5;
        rows[(ROWS/2)-14].r = 6;
        rows[(ROWS/2)-15].r = 6;
        rows[(ROWS/2)-16].r = 6;
        
        rows[(ROWS/2)+1].r = 3;
        rows[(ROWS/2)+2].r = 3;
        rows[(ROWS/2)+3].r = 3;
        rows[(ROWS/2)+4].r = 3;
        rows[(ROWS/2)+5].rp = 2;
        rows[(ROWS/2)+6].rp = 2;
        rows[(ROWS/2)+7].rp = 2;
        rows[(ROWS/2)+5].r = 3;
        rows[(ROWS/2)+6].r = 3;
        rows[(ROWS/2)+7].r = 3;
        rows[(ROWS/2)+8].r = 2;
        rows[(ROWS/2)+9].r = 2;
        rows[(ROWS/2)+10].r = 2;
        rows[(ROWS/2)+11].r = 2;
        rows[(ROWS/2)+12].rp = 1;
        rows[(ROWS/2)+13].rp = 1;
        rows[(ROWS/2)+14].rp = 1;
        rows[(ROWS/2)+12].r = 2;
        rows[(ROWS/2)+13].r = 2;
        rows[(ROWS/2)+14].r = 2;
        rows[(ROWS/2)+15].r = 1;
        rows[(ROWS/2)+16].r = 1;
       
        // half steps based on key
        //
        

        rows[ROWS/2].i = 0;
        rows[ROWS/2].ic = 1;
        rows[(ROWS/2)-1].i = 2;
        rows[(ROWS/2)-1].ic = 3;
        rows[(ROWS/2)-2].i = 4;
        rows[(ROWS/2)-2].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)-3].i = 5;
        rows[(ROWS/2)-3].ic = 6;
        rows[(ROWS/2)-4].i = 7;
        rows[(ROWS/2)-4].ic = 8;
        rows[(ROWS/2)-5].i = 9;
        rows[(ROWS/2)-5].ic = 10;
        rows[(ROWS/2)-6].i = 11;
        rows[(ROWS/2)-6].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)-7].i = 0;
        rows[(ROWS/2)-7].ic = 1;
        rows[(ROWS/2)-8].i = 2;
        rows[(ROWS/2)-8].ic = 3;
        rows[(ROWS/2)-9].i = 4;
        rows[(ROWS/2)-9].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)-10].i = 5;
        rows[(ROWS/2)-10].ic = 6;
        rows[(ROWS/2)-11].i = 7;
        rows[(ROWS/2)-11].ic = 8;
        rows[(ROWS/2)-12].i = 9;
        rows[(ROWS/2)-12].ic = 10;
        rows[(ROWS/2)-13].i = 11;
        rows[(ROWS/2)-13].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)-14].i = 0;
        rows[(ROWS/2)-14].ic = 1;
        rows[(ROWS/2)-15].i = 2;
        rows[(ROWS/2)-15].ic = 3;
        rows[(ROWS/2)-16].i = 4;
        
        rows[(ROWS/2)+1].i = 11;
        rows[(ROWS/2)+1].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)+2].ic = 10;
        rows[(ROWS/2)+2].i = 9;
        rows[(ROWS/2)+3].ic = 8;
        rows[(ROWS/2)+3].i = 7;
        rows[(ROWS/2)+4].ic = 6;
        rows[(ROWS/2)+4].i = 5;
        rows[(ROWS/2)+5].i = 4;
        rows[(ROWS/2)+5].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)+6].ic = 3;
        rows[(ROWS/2)+6].i = 2;
        rows[(ROWS/2)+7].ic = 1;
        rows[(ROWS/2)+7].i = 0;
        rows[(ROWS/2)+8].i = 11;
        rows[(ROWS/2)+8].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)+9].ic = 10;
        rows[(ROWS/2)+9].i = 9;
        rows[(ROWS/2)+10].ic = 8;
        rows[(ROWS/2)+10].i = 7;
        rows[(ROWS/2)+11].ic = 6;
        rows[(ROWS/2)+11].i = 5;
        rows[(ROWS/2)+12].i = 4;
        rows[(ROWS/2)+12].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)+13].ic = 3;
        rows[(ROWS/2)+13].i = 2;
        rows[(ROWS/2)+14].ic = 1;
        rows[(ROWS/2)+14].i = 0;
        rows[(ROWS/2)+15].i = 11;
        rows[(ROWS/2)+15].ic = -30;//nonexistant even when shifted
        rows[(ROWS/2)+16].ic = 10;
        rows[(ROWS/2)+16].i = 9;
        
        transpose(key);
}

void Staff::populate_treble(char staff[ROWS][COLS])
{
        int posy = LEDGERS - 1; 
        int posx = 0;
        staff[posy][posx+6] = LS;
        staff[posy+1][posx+5] = S; staff[posy+1][posx+7] = RS;
        staff[posy+2][posx+4] = US; staff[posy+2][posx+7] = S;
        staff[posy+3][posx+4] = RS; staff[posy+3][posx+6] = S;
        staff[posy+4][posx+4] = S;
        staff[posy+5][posx+3] = S; staff[posy+5][posx+5] = RS;
        staff[posy+5][posx+7] = LS; staff[posy+5][posx+8] = LS;
        staff[posy+5][posx+9] = LS;
        staff[posy+6][posx+2] = S; staff[posy+6][posx+5] = S;
        staff[posy+6][posx+6] = RS; staff[posy+6][posx+10] = RS;
        staff[posy+7][posx+2] = US; staff[posy+7][posx+5] = US;
        staff[posy+7][posx+6] = LS; staff[posy+7][posx+7] = RS;
        staff[posy+7][posx+10] = US;
        staff[posy+8][posx+2] = RS; staff[posy+8][posx+8] = RS;
        staff[posy+8][posx+10] = S;
        staff[posy+9][posx+3] = RS; staff[posy+9][posx+4] = LS; 
        staff[posy+9][posx+5] = LS; staff[posy+9][posx+6] = LS;
        staff[posy+9][posx+7] = LS; staff[posy+9][posx+8] = LS;
        staff[posy+9][posx+9] = S;
        staff[posy+10][posx+7] = RS; staff[posy+10][posx+8] = LS;
        staff[posy+10][posx+9] = S;

}
/*1      _  
 *2-    / \
 *3    |  /
 *4-   \ /
 *5    /
 *6-  / \ ___
 *7  /  /\   \
 *8- |  |_\  |
 *9  \     \ /
 *1-  \_____/
 *2       \_/
 *3    */

void Staff::populate_bass(char staff[ROWS][COLS])
{
        int y = LEDGERS+STAFF_SIZE+MIDDLE;
        int x = 0;
        staff[y][x+4] = LS;
        staff[y][x+5] = LS;
        staff[y][x+6] = LS;
        staff[y][x+7] = LS;
        staff[y][x+8] = LS;
        staff[y+1][x+2] = S;
        staff[y+1][x+9] = RS;
        staff[y+1][x+6] = LS;
        staff[y+1][x+11] = DOT;
        staff[y+2][x+2] = US;
        staff[y+2][x+6] = S_NOTE;
        staff[y+2][x+7] = S;
        staff[y+2][x+9] = US;

        staff[y+3][x+11] = DOT;
        staff[y+3][x+2] = RS;
        staff[y+3][x+3] = LS;
        staff[y+3][x+4] = LS;
        staff[y+3][x+5] = LS;
        staff[y+3][x+6] = S;
        staff[y+3][x+9] = S;
      
        staff[y+4][x+8] = S;
        staff[y+5][x+7] = S;
        staff[y+6][x+6] = S;
        staff[y+7][x+5] = S;
        staff[y+8][x+4] = S;
}
/*1   _____
 *2 /   _  \ @
 *3 |   @/ |
 *4 \___/  / @
 *5       /
 *6      /
 *7     /
 *8    /
 *9   /
 *1  */

void Staff::transpose(char key)
{        
        int deg_shift = 0;
        for (int i = 0; i < ROWS; i++){
                if (rows[i].p == key) {
                        deg_shift = rows[i].i;
                }
                if (rows[i].pc == key) {
                        deg_shift = rows[i].ic;
                }
        }

        for (int i = 0; i < ROWS; i++) {
                rows[i].i -= deg_shift;
                rows[i].ic -= deg_shift;
        }       
}       
