// COURSE.CPP - Course class implementation

#include "unit.h"
#include <iostream>

Unit::Unit()
{
  SetName("NO_INPUT");
  SetId("NO_INPUT");
  SetCredits(0);
}

//---------------------- GET METHODS ---------------------------

const unsigned Unit::GetCredits() const
{
    return credits;
}

const string Unit::GetName() const
{
    return name;
}

const string Unit::GetId() const
{
    return id;
}

//---------------------- SET METHODS ---------------------------

void Unit::SetCredits( unsigned cred )
{
  credits = cred;
}

void Unit::SetName(string nam)
{
  name = nam;
}

void Unit::SetId(string nId)
{
  id = nId;
}
