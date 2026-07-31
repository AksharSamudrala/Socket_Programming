#include "ChatServer.h"

int main()
{
    ChatServer server;

    server.connectUser(1);
    server.connectUser(2);
    server.connectUser(3);

    server.joinGroup(1,100);
    server.joinGroup(2,100);
    server.joinGroup(3,200);

    server.sendMessage(1,
                       "Hello Group 100");

    server.joinGroup(3,100);

    server.sendMessage(3,
                       "Hi everyone!");

    server.disconnectUser(2);

    server.showGroupMembers(100);

    return 0;
}