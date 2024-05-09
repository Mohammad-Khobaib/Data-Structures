#pragma once

#include "typedefs.hpp"

namespace my_stl
{
// This function advances the given iterator by a specified number of steps.
// It iterates through the iterator 'count' times, incrementing it each time.
template <typename Iterator>
void advance(Iterator& iterator, size_type count) {
    for (size_type i = 0; i < count; i++) {
        ++iterator;
    }
}
} // namespace my_stl