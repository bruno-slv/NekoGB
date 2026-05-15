#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <neko_types.h>
#include <string>

typedef struct
{
    std::string name;

    u16 start;
    u16 end;
} address_range_t;

#define MEMORY_MAP(X)           \
    X(ROM, 0x0000, 0x7FFF)      \
    X(VRAM, 0x8000, 0x9FFF)     \
    X(ERAM, 0xA000, 0xBFFF)     \
    X(WRAM, 0xC000, 0xDFFF)     \
    X(ECHO_RAM, 0xE000, 0xFDFF) \
    X(OAM, 0xFE00, 0xFE9F)      \
    X(IO, 0xFF00, 0xFF7F)       \
    X(HRAM, 0xFF80, 0xFFFE)     \
    X(IE, 0xFFFF, 0xFFFF)

constexpr address_range_t memory_addresses[] =
{
#define X(name, start, end) { #name, start, end },
    MEMORY_MAP(X)
#undef X
};

#endif // MEMORY_MAP_H
