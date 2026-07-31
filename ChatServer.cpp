#include "ChatServer.h"
#include <iostream>

using namespace std;

void ChatServer::connectUser(int userId)
{
    users[userId] = Client(userId);

    cout << "User "
         << userId
         << " connected.\n";
}

void ChatServer::disconnectUser(int userId)
{
    leaveGroup(userId);

    users.erase(userId);

    cout << "User "
         << userId
         << " disconnected.\n";
}

void ChatServer::joinGroup(int userId,
                           int groupId)
{
    if(users.find(userId) == users.end())
        return;

    leaveGroup(userId);

    if(groups.find(groupId) == groups.end())
        groups[groupId] = Group(groupId);

    groups[groupId].addMember(userId);

    users[userId].groupId = groupId;

    cout << "User "
         << userId
         << " joined group "
         << groupId
         << endl;
}

void ChatServer::leaveGroup(int userId)
{
    if(users.find(userId) == users.end())
        return;

    int gid = users[userId].groupId;

    if(gid == -1)
        return;

    groups[gid].removeMember(userId);

    users[userId].groupId = -1;
}

void ChatServer::sendMessage(int userId,
                             const string& msg)
{
    if(users.find(userId) == users.end())
        return;

    int gid = users[userId].groupId;

    if(gid == -1)
        return;

    cout << "\nBroadcasting...\n";

    for(int member : groups[gid].members)
    {
        if(member == userId)
            continue;

        cout << "To User "
             << member
             << ": "
             << msg
             << endl;
    }
}

void ChatServer::showGroupMembers(int groupId)
{
    if(groups.find(groupId) == groups.end())
        return;

    cout << "Members : ";

    for(int x : groups[groupId].members)
        cout << x << " ";

    cout << endl;
}