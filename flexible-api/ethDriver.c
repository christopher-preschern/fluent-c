#include <stddef.h>
#include "Driver.h"
#include "EthIOCTL.h"

/* dummy */

DRIVER_HANDLE driverCreate(void* initArg, struct DriverFunctions f)
{
  return NULL;
}

void driverDestroy(DRIVER_HANDLE h)
{
}

void sendByte(DRIVER_HANDLE h, char byte)
{
}

char receiveByte(DRIVER_HANDLE h)
{
  return 0;
}

void driverIOCTL(DRIVER_HANDLE h, int ioctl, void* context)
{
}