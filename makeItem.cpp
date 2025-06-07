#include "makeItem.h"

Item createItem(const std::string& name, const std::string& type) {
    Item item;
    item.name = name;
    item.type = type;
    item.weight = 0.0; // Default for now
    return item;
}