#pragma once

namespace my_stl
{
template<typename KeyType, typename ValueType>
class map;

template<typename KeyType, typename ValueType>
class map_node {
public:
    map_node<KeyType, ValueType>(const KeyType& key, const ValueType& value) :
        m_key(key),
        m_value(value)
    {}

    map_node<KeyType, ValueType>(const KeyType& key) :
        m_key(key),
        m_value(ValueType())
    {}

    bool operator>(const map_node<KeyType, ValueType>& right) const {
        return m_key > right.m_key;
    }

    bool operator>=(const map_node<KeyType, ValueType>& right) const {
        return m_key >= right.m_key;
    }

    bool operator<(const map_node<KeyType, ValueType>& right) const {
        return m_key < right.m_key;
    }

    bool operator<=(const map_node<KeyType, ValueType>& right) const {
        return m_key <= right.m_key;
    }

    bool operator==(const map_node<KeyType, ValueType>& right) const {
        return m_key == right.m_key;
    }
    bool operator!=(const map_node<KeyType, ValueType>& right) const {
        return m_key != right.m_key;
    }
public:
    KeyType m_key;
    ValueType m_value;
};
} // namespace my_stl
