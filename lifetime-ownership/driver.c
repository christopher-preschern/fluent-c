#include <stdbool.h>
#include <stdlib.h>
#include "driver.h"


struct Sender
{
  char destination_ip[15];
  int number_of_callers;
};


static struct Sender dummy_sender;
static int number_of_sent_packets = 0;
static int number_of_received_packets = 0;

static void lock()
{
  /* dummy */
}

static void unlock()
{
  /* dummy */
}

void decreaseNumberOfCallers(SENDER s)
{
  if(s->number_of_callers > 0)
  {
    s->number_of_callers = s->number_of_callers - 1;
  }
}

void increaseNumberOfCallers(SENDER s)
{
  s->number_of_callers = s->number_of_callers + 1;
}

static int numberOfCallers(SENDER s)
{
  return s->number_of_callers;
}

bool isInSenderList(char* destination_ip)
{
  /*dummy implementation*/
  return false;
}

SENDER getSenderFromList(char* destination_ip)
{
  return &dummy_sender;
}

static SENDER createSender(char* destination_ip)
{
  SENDER s = malloc(sizeof(struct Sender));
  /* create socket to destination_ip and store it in SENDER s*/
  return s;
} 

static void destroySender(SENDER s)
{
  /* close socket stored in SENDER s */
  free(s);
}

SENDER openSender(char* destination_ip)
{
  SENDER s;
  if(isInSenderList(destination_ip))
  {
    s = getSenderFromList(destination_ip);
  }
  else
  {
    s = createSender(destination_ip);
  }
  increaseNumberOfCallers(s);
  return s;
} 

void sendByte(SENDER s, char data)
{
  lock(); /* mutual exclusion for threads */
  number_of_sent_packets++;
  unlock();
  /* send data via socket stored in SENDER s */
}

void closeSender(SENDER s)
{
  decreaseNumberOfCallers(s);
  if(numberOfCallers(s) == 0)
  {
    /* close socket stored in SENDER s */
    free(s);      
  }
}

int getNumberOfSentBytes()
{
  return number_of_sent_packets;
}

int getNumberOfReceivedBytes()
{
  return number_of_received_packets;
}

char receiveByte()
{
  number_of_received_packets++;
  /* socket stuff */
}

