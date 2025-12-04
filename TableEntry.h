#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;
    bool hasValue;

    TableEntry(std::string key, V value)
        : key(key), value(value), hasValue(true) {}

    TableEntry(std::string key)
        : key(key), hasValue(false) {}

    TableEntry()
        : key(""), hasValue(false) {}

    template <typename T>
    friend bool operator==(const TableEntry<T> &, const TableEntry<T> &);

    template <typename T>
    friend bool operator!=(const TableEntry<T> &, const TableEntry<T> &);

    template <typename T>
    friend std::ostream& operator<<(std::ostream &, const TableEntry<T> &);
};

// operador ==
template <typename V>
bool operator==(const TableEntry<V> &a, const TableEntry<V> &b) {
    return a.key == b.key;
}

// operador !=
template <typename V>
bool operator!=(const TableEntry<V> &a, const TableEntry<V> &b) {
    return a.key != b.key;
}

// operador <<
template <typename V>
std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te) {
    if (te.hasValue)
        out << te.key << " -> " << te.value;
    else
        out << te.key << " -> [NO VALUE]";
    return out;
}

#endif


