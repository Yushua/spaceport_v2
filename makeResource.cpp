#include "resource.h"

Resource createResource(const std::string& name, const std::string& type) {
    Resource res;
    res.name = name;
    res.type = type;
    res.weight = 0.0; // Default for now
    return res;
}