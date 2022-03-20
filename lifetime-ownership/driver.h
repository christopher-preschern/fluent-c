
typedef struct Sender* SENDER;

SENDER openSender(char* destination_ip);

void sendByte(SENDER s, char data);

void closeSender(SENDER s);

char receiveByte();

int getNumberOfSentBytes();

int getNumberOfReceivedBytes();

