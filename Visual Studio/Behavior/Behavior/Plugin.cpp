#include "stdafx.h"
#include "Behavior.h"
#include "Alignment.h"
#include "Arrival.h"
#include "Avoid.h"
#include "Cohesion.h"
#include "Departure.h"
#include "Flee.h"
#include "Flocking.h"
#include "Leader.h"
#include "Seek.h"
#include "Separation.h"
#include "Wander.h"


#if _MSC_VER // this is defined when compiling with Visual Studio
#define EXPORT_API __declspec(dllexport) // Visual Studio needs annotating exported functions with this
#else
#define EXPORT_API // XCode does not need annotating exported functions, so define is empty
#endif

extern "C"
{
	//Behavioral Animation

	enum Behaviors { alignment, arrival, avoid, cohesion, departure, flee, 
					flocking, leader, seek, separation, wander};

	//struct used to get actor data from Unity
	typedef struct
	{
		//1. complete struct definition to match Actor struct in Behavior.h
		
	
	} actorParameter;

	static int CurrentBehavior;
	static vector<Actor> AgentList;
	static vector<Obstacle> ObstacleList;

	void EXPORT_API initialize(int agentcount, int behavior)
	{
		CurrentBehavior = behavior;
		for (int i=0; i<agentcount; i++)
		{
			Actor A;
			AgentList.push_back(A);
		}
	}

	void EXPORT_API transferActorData(actorParameter agents[], int agentcount, int behavior)
	{
		CurrentBehavior = behavior;
		
		//2. copy all data from agents[] into AgentList
	
	}

	//3. Given an Actor, target and behavior CurrentBehavior, calculate
	//a desired velocity and store it in dvel
	void CalculateDesiredVelocity(int agentID, vec3 target, vec3& dvel)
	{
		vec3 dv(0,0,0);
		Actor A = AgentList[agentID];
		
		//your code goes here
		

		if (dv.Length() > Behavior::g_fMaxSpeed)
 		{
			dv.Normalize();
			dv *= Behavior::g_fMaxSpeed;
 		}
		dvel = dv;
	}

	//wrapper function for Behavior::CalculateForce
	void EXPORT_API CalculateForce(int agentID, float* target, float* force)
	{
		vec3 dv;
		CalculateDesiredVelocity(agentID, vec3(target[0], target[1], target[2]), dv);
		
		Seek s(vec3(0,0,0));
		vec3 f = s.CalculateForce(AgentList[agentID], dv);

		for (int i=0; i<3; i++)
			force[i] = f[i];
	}

	//wrapper function for Behavior::CalculateTorque
	void EXPORT_API CalculateTorque(int agentID, float* target, float* torque)
	{
		vec3 dv;
		CalculateDesiredVelocity(agentID, vec3(target[0], target[1], target[2]), dv);
		
		Seek s(vec3(0,0,0));
		vec3 t = s.CalculateTorque(AgentList[agentID], dv);

		for (int i=0; i<3; i++)
			torque[i] = t[i];
	}

	//4. Define obstacleParameter struct for data transfer between Unity and DLL

	
	//5. Write the DLL function transferObstacleData()


	//6. Write the DLL function clearObstacleData()
}

