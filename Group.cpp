#include "Group.h"

Group::Group()
{
    groupId = -1;
}

Group::Group(int gid)
{
    groupId = gid;
}

void Group::addMember(int uid)
{
    members.insert(uid);
}

void Group::removeMember(int uid)
{
    members.erase(uid);
}