#pragma once 

#include "typedefs.hpp"

namespace my_stl
{
template<typename Iterator>
size_type distance(Iterator begin, Iterator end) {
    size_type length = 0;
    while (begin != end) {
        ++begin;
        ++length;
    }
    return length;
}
} // namespace my_stl
