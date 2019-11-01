#include "songs.hpp"

static Note left_score[] = {
    { DO3, EIGHTH }, { MI3, EIGHTH }, { SOL3, HALF },
    { DO3, EIGHTH }, { FA3D, EIGHTH }, { LA3, HALF },
    { DO3, EIGHTH }, { MI3, EIGHTH }, { SOL3, HALF },
    { DO3, EIGHTH }, { FA3D, EIGHTH }, { LA3, HALF },

    { SI2, EIGHTH }, { RE3, EIGHTH }, { LA3, HALF },
    { LA2D, EIGHTH }, { DO3D, EIGHTH }, { LA3, HALF },
    { LA2, EIGHTH }, { DO3, EIGHTH }, { SOL3, HALF },
    { RE3, EIGHTH }, { FA3D, EIGHTH }, { LA3, HALF },

    { DO3, EIGHTH }, { MI3, EIGHTH }, { SOL3, HALF },
    { DO3, EIGHTH }, { FA3D, EIGHTH }, { LA3, HALF },
    { DO3, EIGHTH }, { MI3, EIGHTH }, { SOL3, HALF },
    { DO3, EIGHTH }, { FA3D, EIGHTH }, { LA3, HALF },

    { SI2, EIGHTH }, { RE3, EIGHTH }, { LA3, HALF },
    { LA2D, EIGHTH }, { DO3D, EIGHTH }, { LA3, HALF },
    { LA2, EIGHTH }, { DO3, EIGHTH }, { SOL3, HALF },
    { RE3, EIGHTH }, { FA3D, EIGHTH }, { DO3, HALF },


    { FA3, EIGHTH }, { LA3, EIGHTH }, { DO4, EIGHTH }, { MI4, EIGHTH | QUARTER },
    { MI3, EIGHTH }, { SOL3, EIGHTH }, { SI3, EIGHTH }, { RE4, EIGHTH }, { SI3, EIGHTH }, { SOL3, EIGHTH },
    { RE3, EIGHTH }, { FA3, EIGHTH }, { LA3, EIGHTH }, { DO4, EIGHTH | QUARTER },
    { DO3, EIGHTH }, { MI3, EIGHTH }, { SOL3, EIGHTH }, { SI3, EIGHTH }, { SOL3, EIGHTH }, { MI3, EIGHTH },

    { FA3, EIGHTH }, { LA3, EIGHTH }, { DO4, EIGHTH }, { MI4, EIGHTH | QUARTER },
    { MI3, EIGHTH }, { SOL3, EIGHTH }, { SI3, EIGHTH }, { RE4, EIGHTH }, { SI3, EIGHTH }, { SOL3, EIGHTH },
    { RE3D, EIGHTH }, { SOL3, EIGHTH }, { LA3D, EIGHTH }, { DO4D, EIGHTH }, { LA3D, EIGHTH }, { SOL3, EIGHTH },
    { RE3, EIGHTH }, { FA3, EIGHTH }, { SOL3, EIGHTH }, { LA3, EIGHTH }, { SOL3, HALF }
};

static Note right_score[] = {
     { SI4, HALF }, { RE5, QUARTER },
     { LA4, HALF }, { SOL4, EIGHTH }, { LA4, EIGHTH },
     { SI4, HALF }, { RE5, QUARTER },
     { LA4, HALF | QUARTER },

     { SI4, HALF }, { RE5, QUARTER },
     { LA5, HALF }, { SOL5, QUARTER },
     { RE5, HALF }, { DO5, EIGHTH }, { SI4, EIGHTH },
     { LA4, HALF | QUARTER },

     { SI4, HALF }, { RE5, QUARTER },
     { LA4, HALF }, { SOL4, EIGHTH }, { LA4, EIGHTH },
     { SI4, HALF }, { RE5, QUARTER },
     { LA4, HALF | QUARTER },

     { SI4, HALF }, { RE5, QUARTER },
     { LA5, HALF }, { SOL5, QUARTER },
     { RE6, HALF | QUARTER },
     { RE6, HALF | QUARTER },


     { RE6, HALF }, { DO6, EIGHTH }, { SI5, EIGHTH },
     { DO6, EIGHTH }, { SI5, EIGHTH }, { SOL5, HALF },
     { DO6, HALF }, { SI5, EIGHTH }, { LA5, EIGHTH },
     { SI5, EIGHTH }, { LA5, EIGHTH }, { MI5, HALF },

     { RE6, HALF }, { DO6, EIGHTH }, { SI5, EIGHTH },
     { DO6, EIGHTH }, { SI5, EIGHTH }, { SOL5, QUARTER }, { DO6, QUARTER },
     { SOL6, HALF | QUARTER },
     { REST, HALF | EIGHTH }, { RE4, EIGHTH }, { SOL5, QUARTER }
};

static Song zelda_lullaby_song(100,
        left_score, nElements(left_score),
        right_score, nElements(right_score));

const Song& zelda_lullaby()
{
    return zelda_lullaby_song;
}
