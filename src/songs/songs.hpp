#pragma once

#include "song.hpp"

template<class T, size_t N>
constexpr size_t nElements(T (&)[N]) { return N; }

const Song& beethoven_n9();
const Song& we_wish_you_a_merry_christmas();
const Song& zelda_lullaby();
const Song& the_heart_asks_pleasure_first();
