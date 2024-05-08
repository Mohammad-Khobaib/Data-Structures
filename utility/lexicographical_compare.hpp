#pragma once

namespace my_stl
{
template<typename InputIterator>
bool lexicographical_compare(InputIterator lhs_begin, InputIterator lhs_end, InputIterator rhs_begin, InputIterator rhs_end) {
    while (lhs_begin != lhs_end && rhs_begin != rhs_end) {
        if (*lhs_begin < *rhs_begin) {
            return true;
        }
        if (*lhs_begin > *rhs_begin) {
            return false;
        }
        ++lhs_begin;
        ++rhs_begin;
    }
    if (lhs_begin == lhs_end && rhs_begin != rhs_end) {
        return true;
    } else {
        return false;
    }
}
} // namespace my_stl
