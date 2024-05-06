#pragma once

namespace my_stl
{  

// Template struct reference_selector assists in selecting the appropriate reference type
// for iterators of a given container type. It determines whether the iterator is const or non-const
// and provides the corresponding reference type accordingly.

template<typename ContainerType, bool IsConst>
struct reference_selector {
    using reference = typename ContainerType::value_type&;
};

template<typename ContainerType>
struct reference_selector<ContainerType, true> {
    using reference = const typename ContainerType::value_type&;
};
}
