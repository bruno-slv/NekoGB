#ifndef _CARTRIDGE_H_
#define _CARTRIDGE_H_

#include <neko_types.h>
#include <device.h>
#include <header.h>
#include <memory>

class Cartridge : public IDevice
{
private:
    header_info_t header;
public:
    std::unique_ptr<u8[]> rom;
    size_t rom_size;

    Cartridge();

    void load(const u8 *data_source, size_t size);
    u8 read(u16 offset) override;
    void write(u16 offset, u8 value) override;

    void tick(u32 cycles) override;
    u8 reset() override;

    ~Cartridge() override;
};

#endif // _CARTRIDGE_H_
