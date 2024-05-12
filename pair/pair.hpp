#pragma once

namespace my_stl
{
template <typename KeyType, typename ValueType>
class pair {
public:
    KeyType first;
    ValueType second;

    pair(const KeyType& key, const ValueType& value) :
        first(key),
        second(value)
    {}
};
} // namespace my_stl
