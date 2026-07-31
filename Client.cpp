#include "Client.h"

Client::Client()
{
    userId = -1;
    groupId = -1;
    connected = false;
}

Client::Client(int uid)
{
    userId = uid;
    groupId = -1;
    connected = true;
}