typedef struct INTERNAL_DRIVER_STRUCT* DRIVER_HANDLE;
typedef void (*DriverSend_FP)(char byte);
typedef char (*DriverReceive_FP)();
typedef void (*DriverIOCTL_FP)(int ioctl, void* context);

struct DriverFunctions
{
  DriverSend_FP fpSend;
  DriverReceive_FP fpReceive;
  DriverIOCTL_FP fpIOCTL;
};

DRIVER_HANDLE driverCreate(void* initArg, struct DriverFunctions f);

void driverDestroy(DRIVER_HANDLE h);

void sendByte(DRIVER_HANDLE h, char byte);

char receiveByte(DRIVER_HANDLE h);

/* the parameter "context" is required to pass information like the
   value of the IP address to configure to the implementation */
void driverIOCTL(DRIVER_HANDLE h, int ioctl, void* context);
