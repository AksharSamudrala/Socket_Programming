#pragma once
#include <unordered_set>

class Group
{
public:
    int groupId;
    std::unordered_set<int> members;

    Group();
    Group(int gid);

    void addMember(int uid);
    void removeMember(int uid);
};