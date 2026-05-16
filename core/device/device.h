#ifndef DEVICE_H
#define DEVICE_H

#include <neko_types.h>

class IMemoryDevice
{
public:
    virtual u8 read(u16 offset) = 0;
    virtual void write(u16 offset, u8 value) = 0;

    virtual ~IMemoryDevice() = default;
};

class IClockDevice
{
public:
    virtual void tick(u32 cycles) = 0;

    virtual ~IClockDevice() = default;
};

#endif // DEVICE_H
