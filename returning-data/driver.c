#include "driver.h"
#include <string.h>
#include <stdlib.h>

static struct EthernetDriverInfo info = {"DRIVER", "This is a driver"};

struct EthernetDriverStat ethernetDriverGetStatistics()
{
  struct EthernetDriverStat stat;
  stat.received_packets = 1;
  stat.total_sent_packets = 2;
  stat.successfully_sent_packets = 3;
  stat.failed_sent_packets = 4;
  return stat;
}


const struct EthernetDriverInfo* ethernetDriverGetInfo()
{
  return &info;
}


void ethernetDriverGetIp(struct IpAddress* ip)
{
  strcpy(ip->address, "192.168.0.1");
  strcpy(ip->subnet, "255.255.255.0");
}


struct Packet* ethernetDriverGetPacket()
{
  struct Packet* packet = malloc(sizeof(struct Packet));
  strcpy(packet->data, "This is the data in the packet");
  packet->size = strlen(packet->data);
  return packet;
}


