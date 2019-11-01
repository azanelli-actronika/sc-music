#include "songs.hpp"

static Note left_score[] = {
    { LA3, HALF | QUARTER },
    { SOL3, HALF | QUARTER },
    { FA3, HALF | QUARTER },
    { MI3, HALF | QUARTER },

    { LA3, HALF | QUARTER },
    { SOL3, HALF | QUARTER },
    { FA3, HALF | QUARTER },
    { RE3, HALF | QUARTER },

    /* repeat 1 start */
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },

    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { SOL2, EIGHTH }, { RE3, EIGHTH }, { SOL3, EIGHTH }, { RE3, EIGHTH }, { SOL3, EIGHTH }, { RE3, EIGHTH },

    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },

    { MI2, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH },
    { MI2, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH },

    /* alt 1 start */
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },

    /* repeat 2 start */
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },

    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { FA2, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH }, { FA3, EIGHTH }, { DO3, EIGHTH },
    { SOL2, EIGHTH }, { RE3, EIGHTH }, { SOL3, EIGHTH }, { RE3, EIGHTH }, { SOL3, EIGHTH }, { RE3, EIGHTH },

    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },

    { MI2, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH },
    { MI2, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH }, { MI3, EIGHTH }, { SI2, EIGHTH },

    /* alt 2 start */
    { LA2, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH }, { LA3, EIGHTH }, { MI3, EIGHTH },
    /* normally it's a chord but we don't support it so... */
    { LA2, QUARTER }, { MI3, QUARTER }, { LA3, QUARTER },
};

static Note right_score[] = {
    { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { RE5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { DO5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { DO5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { DO5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },

    { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { MI5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { RE5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { DO5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH }, { DO5, EIGHTH }, { MI4, EIGHTH }, { LA4, EIGHTH },
    { LA4, EIGHTH }, { RE4, EIGHTH }, { FA4D, EIGHTH }, { LA4, EIGHTH | QUARTER },


    /* repeat 1 start */
    { LA4, HALF }, { LA4, QUARTER },
    { LA4, HALF }, { SI4, QUARTER },
    { LA4, HALF }, { SOL4, QUARTER },
    { MI4, HALF | QUARTER },

    { DO5, HALF }, { DO5, QUARTER },
    { DO5, HALF }, { MI5, QUARTER },
    { RE5, HALF }, { DO5, QUARTER },
    { SI4, HALF }, { DO5, EIGHTH }, { SI4, EIGHTH },

    { LA4, HALF }, { LA4, QUARTER },
    { MI5, HALF }, { SI4, QUARTER },
    { LA4, HALF }, { SOL4, QUARTER },
    { MI4, HALF }, { RE4, EIGHTH }, { DO4, EIGHTH },
    { DO4, HALF }, { RE4, EIGHTH }, { DO4, EIGHTH },

    { RE4, HALF }, { RE4, QUARTER },
    { MI4, HALF }, { SOL4D, QUARTER },

    /* alt1 */
    { LA4, HALF | QUARTER },

    /* repeat 2 start */
    { LA4, HALF }, { LA4, QUARTER },
    { LA4, HALF }, { SI4, QUARTER },
    { LA4, HALF }, { SOL4, QUARTER },
    { MI4, HALF | QUARTER },

    { DO5, HALF }, { DO5, QUARTER },
    { DO5, HALF }, { MI5, QUARTER },
    { RE5, HALF }, { DO5, QUARTER },
    { SI4, HALF }, { DO5, EIGHTH }, { SI4, EIGHTH },

    { LA4, HALF }, { LA4, QUARTER },
    { MI5, HALF }, { SI4, QUARTER },
    { LA4, HALF }, { SOL4, QUARTER },
    { MI4, HALF }, { RE4, EIGHTH }, { DO4, EIGHTH },
    { DO4, HALF }, { RE4, EIGHTH }, { DO4, EIGHTH },

    { RE4, HALF }, { RE4, QUARTER },
    { MI4, HALF }, { SOL4D, QUARTER },

    /* alt 2 */
    { LA4, HALF | QUARTER },
    { LA4, HALF | QUARTER }
};

static Song song(120,
        left_score, nElements(left_score),
        right_score, nElements(right_score));

const Song& the_heart_asks_pleasure_first()
{
    return song;
}
