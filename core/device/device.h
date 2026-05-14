#ifndef DEVICE_H
#define DEVICE_H

#include <neko_types.h>

typedef struct
{
    u16 start;
    u16 end;
} AddressRange;

class IDevice
{
protected:
    AddressRange address;

public:
    virtual void tick(u32 cycles) = 0;
    virtual u8 reset() = 0;

    virtual u8 read(u16 address) = 0;
    virtual void write(u16 address, u8 value) = 0;

    IDevice(u16 start, u16 end);

    virtual ~IDevice();
};

#endif // DEVICE_H
