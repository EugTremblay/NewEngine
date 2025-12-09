#pragma once
/// <summary>
/// interface to add on Collideable components
/// </summary>
class ICollideable
{
public:
    virtual void OnCollisionEnter(Entity* other) = 0;
};
