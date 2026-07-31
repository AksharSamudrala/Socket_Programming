#pragma once

#include <unordered_map>
#include <string>
#include "Client.h"
#include "Group.h"

class ChatServer
{
private:
    std::unordered_map<int, Client> users;
    std::unordered_map<int, Group> groups;

public:
    void connectUser(int userId);

    void disconnectUser(int userId);

    void joinGroup(int userId, int groupId);

    void leaveGroup(int userId);

    void sendMessage(int userId,
                     const std::string& msg);

    void showGroupMembers(int groupId);
};