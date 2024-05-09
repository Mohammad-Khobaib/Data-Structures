#pragma once

namespace my_stl
{
// This function enables move semantics by converting the given value
// into an rvalue reference, allowing it to be efficiently moved instead of copied.
template<typename T>
inline T&& move(const T& val) {
    return (T&&) val;
}
} // namespace my_stl