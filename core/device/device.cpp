#include <device.h>

IDevice::IDevice(u16 start, u16 end)
    : address{start, end}
{
}

IDevice::~IDevice()
{
}
