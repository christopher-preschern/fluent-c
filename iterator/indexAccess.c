#define MAX_NAME_LENGTH 50
#define MAX_PWD_LENGTH 50

#include "indexAccess.h"


struct ACCOUNT
{
  char loginname[MAX_NAME_LENGTH];
  char password[MAX_PWD_LENGTH];
};

static struct ACCOUNT accountData[MAX_USERS] = {{"A","A"}, {"B","B"}, {"C","C"}, {"X","X"}, {"Y","Y"}};


char* getLoginName(int index)
{
  return accountData[index].loginname;
}





