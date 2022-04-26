

/** Ablauf
 * 1. Nimmt einen User Input (BONUS oder eine Datei)
 * 2. Input wird in 512-bit Block (16 32-bit Wörter) aufgeteilt und eventuell gepadded
 * 3. Die 4 32-bit Words werden initialisiert
 * 4. für jeden Block durchlaufen die Wörter 4 rounds á 16 Operations (64)
 * 5. eventuell repeat wenn es mehr als einen Block gibt (sequentiell einfach?)
 * 6. ausgabe der 4 wörter (verkettet natürlich)
 */

int main() {

    //todo process input, result = number of blocks, padded input
    //todo data structure for padded input  x * (16 * int)

    int x; //number of blocks in input

    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;

    /** 3 tops below are all constants **/
    //todo intialize K[], array with 64 constants which are sequentielly used in main loop
    //todo initialize words
    //todo s[], array with set amounts of lefrotate steps for each round

    for (int i = 0; i < x; ++i) { // todo for each block (depends on datastructure)

        int a_loc = A;
        int b_loc = B;
        int c_loc = C;
        int d_loc = D;
        int F; //output of specific round-function
        int g; //number calculated each round to determine which 32-bit word of the block gets used

        //todo copy current block from padded input to local variable (depends on datastructure)

        /** Main Loop **/
        for (int j = 0; j < 64; ++j) {
            if ( 0 <= j && j <= 15) {
                F = ( b_loc & c_loc ) | ( ( ~b_loc ) & d_loc );
                g = j;
            }
            else if ( 16 <= j && j <= 32) {
                F = ( d_loc & b_loc) | ( ( ~d_loc ) & c_loc );
                g = ( 5 * j + 1) % 16;
            }
            else if ( 33 <= j && j <= 48) {
                F = b_loc ^ c_loc ^ d_loc;
                g = ( 3 * j + 5) % 16;
            }
            else if ( 49 <= j && j <= 63) {
                F = c_loc ^ (b_loc | ( ~ d_loc ) );
                g = ( 7 * j ) % 16;
            }
            //todo F = F + a_loc + K[j] + M[g]
            a_loc = d_loc;
            d_loc = c_loc;
            c_loc = b_loc;
            //todo b_loc = b_loc + leftrotate(F, s[j]);

        }
        A = A + a_loc;
        B = B + b_loc;
        C = C + c_loc;
        D = D + d_loc;
    }
    //todo put A,B,C,D together for 128 bit
    //todo output

}