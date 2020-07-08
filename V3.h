
#include <iostream>

#include "Util.h"

struct V3
{
    float x, y, z;

    V3(float x, float y, float z)
        :
        x{x}, 
        y{y}, 
        z{z}
    {
        // LOG("Constructed");
    }

    V3(V3 const& other)
        :
        x{other.x},
        y{other.y},
        z{other.z}
    {
        // LOG("Copied");
    }

    V3(V3&& other)
        :
        x{other.x},
        y{other.y},
        z{other.z}
    {
        // NOTE: There is no heap-memory to move here,
        // so everything is just copied. Just for demon-
        // stration purposes.
        LOG("Moved");
    }

    friend std::ostream& operator<<(std::ostream& ostream, V3 const& v3);
};

std::ostream& operator<<(std::ostream& ostream, V3 const& v3)
{
    return ostream << "{" << v3.x << " " << v3.y << " " << v3.z << "}";
}