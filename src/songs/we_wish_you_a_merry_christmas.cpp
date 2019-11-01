#include "songs.hpp"

static Note we_wish_you_a_merry_christmas_score[] = {
    { REST, HALF }, { RE4, QUARTER },
    { SOL4, QUARTER }, { SOL4, EIGHTH }, { LA4, EIGHTH }, { SOL4, EIGHTH }, { FA4D, EIGHTH },
    { MI4, QUARTER }, { MI4, QUARTER }, { MI4, QUARTER },

    { LA4, QUARTER }, { LA4, EIGHTH }, { SI4, EIGHTH }, { LA4, EIGHTH }, { SOL4, EIGHTH },
    { FA4D, QUARTER }, { RE4, QUARTER }, { RE4, QUARTER },
    { SI4, QUARTER }, { SI4, EIGHTH }, { DO5, EIGHTH }, { SI4, EIGHTH }, { LA4, EIGHTH },

    { SOL4, QUARTER }, { MI4, QUARTER }, { RE4, EIGHTH }, { RE4, EIGHTH },
    { MI4, QUARTER }, { LA4, QUARTER }, { FA4D, QUARTER },
    { SOL4, QUARTER }, { REST, QUARTER }, { RE4, QUARTER },
};

static Song we_wish_you_a_merry_christmas_song(82,
        we_wish_you_a_merry_christmas_score,
        nElements(we_wish_you_a_merry_christmas_score));

const Song& we_wish_you_a_merry_christmas()
{
    return we_wish_you_a_merry_christmas_song;
}
