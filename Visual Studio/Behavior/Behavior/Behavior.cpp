#include "StdAfx.h"
#include "Behavior.h"
#include <math.h>

//Adjust the gain constants to tune the controller response

float Behavior::g_fMaxSpeed = 4.0f;
float Behavior::g_fMaxAccel = 10.0f;
float Behavior::g_fKNeighborhood = 100.0f;
float Behavior::g_fOriKv = 1.0;  // Orientation
float Behavior::g_fOriKp = 1.0; 
float Behavior::g_fVelKv = 1.0;  // Velocity 
float Behavior::g_fAgentRadius = 2.0;


Behavior::Behavior(const char* name) : m_name(name)
{
}

Behavior::Behavior(const Behavior& orig) : m_name(orig.m_name)
{
}

const std::string& Behavior::GetName() const
{
    return m_name;
}

// Given an actor and desired velocity, calculate a corresponding force
vec3 Behavior::CalculateForce(Actor& actor, const vec3& dvel)
{
	//your code goes here
	
	return vec3(0,0,0);
}

// Given an actor and desired velocity, calculate a corresponding torque
vec3 Behavior::CalculateTorque(Actor &actor, const vec3& dvel)
{    
	// 1. Get current rotation matrix

	// 2. Construct desired rotation matrix 
    // (This corresponds to facing in the direction of our desired velocity)
	// Note: Z points forwards; Y Points UP; and X points left

	// 3. Compute the change in rotation matrix that will
	// rotate the actor towards our desired rotation

	// 4. Construct quaternion to get axis and angle from dr
	

	// find torque

	return vec3(0,0,0);
}