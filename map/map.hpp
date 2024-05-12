#pragma once

#include<initializer_list>

#include "../trees/red_black_tree/red_black_tree_iterator.hpp"
#include "../trees/red_black_tree/red_black_tree.hpp"
#include "../pair/pair.hpp"
#include "map_node.hpp"

namespace my_stl
{
template<typename KeyType, typename ValueType>
class map {
public:
    using node = map_node<KeyType, ValueType>;
    using value_type = pair<KeyType, ValueType>;
    using size_type = unsigned int;
    using iterator = typename red_black_tree<node>::iterator;
    using const_iterator = typename red_black_tree<node>::const_iterator;

    map<KeyType, ValueType>() {}

    map<KeyType, ValueType>(const std::initializer_list<value_type>& values) {
        insert(values);
    }

    void insert(const value_type& val) {
        m_red_black_tree.insert_node(node(val.first, val.second));
    }

    void insert(const std::initializer_list<value_type>& values) {
        for (const value_type& val: values) {
            insert(val);
        }
    }
    
    void erase(const KeyType& key) {
        m_red_black_tree.delete_node(node(key));
    }

    size_type size() const {
        return m_red_black_tree.size();
    }

    iterator begin() {
        return m_red_black_tree.begin();
    }

    const_iterator begin() const {
        return m_red_black_tree.begin();
    }

    iterator end() {
        return m_red_black_tree.end();
    }

    const_iterator end() const {
        return m_red_black_tree.end();
    }

    ValueType& operator[](const KeyType& key) {
        try {
            node& temp = m_red_black_tree.search_node(node(key));
            return temp.m_value;
        } catch (const runtime_error& err) {
            throw runtime_error("Key not found");
        }
    }
private:
    red_black_tree<node> m_red_black_tree;
};
} // namespace my_stl
