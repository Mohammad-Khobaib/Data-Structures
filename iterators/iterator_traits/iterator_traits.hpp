#pragma once

namespace my_stl
{
template<typename Iterator>
struct iterator_traits {
    using value_type = typename Iterator::value_type;
    using pointer = typename Iterator::pointer;
    using difference_type = typename Iterator::diffference_type;
    using reference = typename Iterator::reference;
};

template<typename T>
struct iterator_traits<T*> {
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using difference_type = long int;
};

template<typename T>
struct iterator_traits<const T*> {
    using value_type = const T;
    using pointer = const T*;
    using reference = const T&;
    using difference_type = long int;
};
}
