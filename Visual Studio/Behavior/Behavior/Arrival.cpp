#include "stdafx.h"
#include "Arrival.h"

float Arrival::g_fKArrival = 0.5f;

Arrival::Arrival(vec3 target) : Behavior("arrival"), m_pTarget(target)
{
}

Arrival::Arrival(const Arrival& orig) :
    Behavior(orig), m_pTarget(orig.m_pTarget)
{
}

Arrival::~Arrival()
{
    m_pTarget = vec3(0,0,0);
}

Behavior* Arrival::Clone() const
{
    return new Arrival(*this);
}

// Given the actor, return a desired velocity in world coordinates
// Arrival returns a velocity whose speed is proportional to the actors distance
// from the target
vec3 Arrival::CalculateDesiredVelocity(Actor& actor)
{
	return vec3(0,0,0);
}

