#include <cartridge.h>
#include <cstring>

Cartridge::Cartridge()
{
}

Cartridge::~Cartridge()
{    
}

void Cartridge::load(const u8 *data_source, size_t size)
{
    rom_size = size;
    rom = std::make_unique<u8[]>(rom_size);

    memcpy(rom.get(), data_source, rom_size);

    load_header_info(rom.get(), &header);
}

u8 Cartridge::read(u16 offset)
{
    return offset < rom_size ? rom[offset] : 0xFF;
}

void Cartridge::write(u16 offset, u8 value)
{
    (void)offset;
    (void)value;
}

void Cartridge::tick(u32 cycles)
{
}

u8 Cartridge::reset()
{
    return 0xFF;
}
