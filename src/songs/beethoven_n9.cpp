#include "songs.hpp"

static Note beethoven_n9_score_left[] = {
    { DO3, HALF }, { SOL3, HALF },
    { DO3, HALF }, { SOL3, HALF },
    { DO3, HALF }, { SOL3, HALF },
    { DO3, HALF }, { SOL3, HALF },

    { DO3, HALF }, { SOL3, HALF },
    { DO3, HALF }, { SOL3, HALF },
    { DO3, HALF }, { SOL3, HALF },
    { SOL3, HALF }, { DO3, HALF },
};

static Note beethoven_n9_score_right[] = {
    { MI4, QUARTER }, { MI4, QUARTER }, { FA4, QUARTER }, { SOL4, QUARTER },
    { SOL4, QUARTER }, { FA4, QUARTER }, { MI4, QUARTER }, { RE4, QUARTER },
    { DO4, QUARTER }, { DO4, QUARTER }, { RE4, QUARTER }, { MI4, QUARTER },
    { MI4, HALF }, { RE4, HALF },

    { MI4, QUARTER }, { MI4, QUARTER }, { FA4, QUARTER }, { SOL4, QUARTER },
    { SOL4, QUARTER }, { FA4, QUARTER }, { MI4, QUARTER }, { RE4, QUARTER },
    { DO4, QUARTER }, { DO4, QUARTER }, { RE4, QUARTER }, { MI4, QUARTER },
    { RE4, QUARTER }, { DO4, QUARTER }, { DO4, HALF }
};

static Song beethoven_n9_song(100,
        beethoven_n9_score_left, nElements(beethoven_n9_score_left),
        beethoven_n9_score_right, nElements(beethoven_n9_score_right));

const Song& beethoven_n9()
{
    return beethoven_n9_song;
}
