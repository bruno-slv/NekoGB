#ifndef DEVICE_H
#define DEVICE_H

#include <neko_types.h>

class IDevice
{
public:
    virtual void tick(u32 cycles) = 0;
    virtual u8 reset() = 0;

    virtual u8 read(u16 offset) = 0;
    virtual void write(u16 offset, u8 value) = 0;

    IDevice();

    virtual ~IDevice();
};

#endif // DEVICE_H
