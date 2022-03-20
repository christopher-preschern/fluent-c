#ifndef DRIVER_H
#define DRIVER_H


struct EthernetDriverInfo{
  char name[64];
  char description[1024];
};

/* Returns the driver name and description */
const struct EthernetDriverInfo* ethernetDriverGetInfo();



struct EthernetDriverStat{
  int received_packets;           /* Number of received packets */
  int total_sent_packets;         /* Number of sent packets (successfuly and failed */
  int successfully_sent_packets;  /* Number of successfully sent packets */
  int failed_sent_packets;        /* Number of packets failed to send */
};

/* Returns statistics information of the Ethernet driver */
struct EthernetDriverStat ethernetDriverGetStatistics();


struct IpAddress{
  char address[16];
  char subnet[16];
};

/* Stores the IP information into 'ip' which has to be provided by the caller*/
void ethernetDriverGetIp(struct IpAddress* ip);


struct Packet
{
  char data[1500]; /* maximum 1500 byte per packet */
  int size;        /* actual size of data in the packet */
};

/* Returns a pointer to a packet which has to be freed by the caller */
struct Packet* ethernetDriverGetPacket();

#endif

