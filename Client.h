#pragma once

class Client
{
public:
    int userId;
    int groupId;
    bool connected;

    Client();
    Client(int uid);
};

/home/akshar/MediaNet/ChatServer.cpp