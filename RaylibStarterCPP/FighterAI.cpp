#include "FighterAI.h"
#include "Fighter.h"
#include "Gatherer.h"
#include "Transport.h"

FighterAI::FighterAI(Spaceship* spaceship, GameWorld* gWPointer)
{
	owner = spaceship;
	gameWorldPointer = gWPointer;
	//this->gameWorldPointer->allShips = 
	currentState = State::Idle;
	countdownTimer = COUNTDOWN;
	deltaTime = GetFrameTime();
	owner->GetPosition();
	owner->GetVelocity();
	//distanceToTarget = owner->targetShip->GetPosition();
	distanceToTarget = 100;
	owner->PatrolAIPath();
}

FighterAI::~FighterAI()
{
}

void FighterAI::Update()
{
	switch (currentState)
	{
	case State::Patrolling:
	{	//What the thing does while it's Patrolling.
		//owner->PatrolAIMovement();
		//countdownTimer = COUNTDOWN;
		for (int i = 0; i < gameWorldPointer->allShips.size(); i++)
		{
			if (owner->WithinRange(gameWorldPointer->allShips[i]))
			{
				owner->targetShip = gameWorldPointer->allShips[i];
				TransitionState(State::Attack);
				break;
			}
		}
		std::cout << "The AI Agent is currently Patrolling" << std::endl;
		//owner->WithinRange()
		//if (distanceToTarget < spaceShip.WithinRange())
		//{
		//	TransitionState(State::Attack);
		//}

		//countdownTimer = COUNTDOWN;
		//for (int i = 0; i < gameWorldPointer->allShips.size(); i++)
		//{
		//	if (owner->WithinRange(vectorOfAllShips[i], 20))
		//	{
		//		owner->targetShip = &vectorOfAllShips[i];
		//		TransitionState(State::Attack);
		//		break;
		//	}
		//}
		//owner->WithinRange()
		//	if (distanceToTarget < spaceShip.WithinRange())
		//	{
		//		TransitionState(State::Attack);
		//	}
		break;
	}
	case State::Attack:
	{
		owner->AttackAIMovement();
		//countdownTimer = COUNTDOWN;
		for (int i = 0; i < gameWorldPointer->allShips.size(); i++)
		{
			if (distanceToTarget > owner->WithinRange(gameWorldPointer->allShips[i]) && countdownTimer == 0)
			{
				owner->targetShip = gameWorldPointer->allShips[i];
				TransitionState(State::Idle);
				//break;
			}
		}
		//if (distanceToTarget > owner->WithinRange(owner->targetShip) && countdownTimer == 0)
		//{
		//	TransitionState(State::Idle);
		//}
		std::cout << "The AI Agent is currently attacking" << std::endl;
		//for (int i = 0; i < gameWorldPointer->allShips.size(); i++)
		//{
		//	if (!owner->WithinRange(gameWorldPointer->allShips[i]))
		//	{
		//		(countdownTimer * deltaTime)--;
		//		//owner->targetShip = gameWorldPointer->allShips[i];
		//		TransitionState(State::Idle);
		//		//if (distanceToTarget > owner->WithinRange(owner->targetShip))
		//		//{
		//		//	TransitionState(State::Idle);
		//		//}
		//	}
		//}
		countdownTimer--;
		//TransitionState(State::Idle);
		break;
	}
	case State::Gather:
	{

		break;
	}
	case State::Transport:
	{
		//Transport::EmptyTransport;
		//Transport::ReturnTransport;
		break;
	}
	case State::Idle:
	{
		countdownTimer = COUNTDOWN;
		//Vector2 velocity = { 0,0 };
		//owner->GetVelocity();
		//owner->SetVelocity(velocity);
		//countdownTimer--;
		std::cout << "The AI Agent is currently Idle" << std::endl;
		for (int i = 0; i < gameWorldPointer->allShips.size(); i++)
		{
			if (owner->WithinRange(gameWorldPointer->allShips[i]))
			{
				owner->targetShip = gameWorldPointer->allShips[i];
				std::cout << "The current state will shift to Attack" << std::endl;
				TransitionState(State::Attack); 
			}
			else
			{
				if (distanceToTarget > owner->WithinRange(gameWorldPointer->allShips[i]) && ((countdownTimer * deltaTime) == 0))
				{
					owner->targetShip = gameWorldPointer->allShips[i];
					std::cout << "The current state will shift to Patrolling" << std::endl;
					TransitionState(State::Patrolling);
				}
			}
		}
		//if (distanceToTarget < owner->WithinRange(owner->targetShip))
		//{
		//	TransitionState(State::Attack);
		//}
		//if ((distanceToTarget > owner->WithinRange(owner->targetShip)) > (COUNTDOWN * deltaTime))
		//{
		//	TransitionState(State::Patrolling);
		//}
		break;
	}
	default:
		std::cout << "State transition failed. Default statement. Failed Test: " << counter << std::endl;
		counter++;
		TransitionState(State::Idle);
	//Do what the thing does every frame while it's idle.
	}
}

void FighterAI::TransitionState(State newState)
{
	//if (currentState == State::Idle)
	//{
	//	Vector2 velocity = { 0,0 };
	//	//play 'wakeup' animation or whatever
	//	spaceShip.GetVelocity();
	//	spaceShip.SetVelocity(velocity);
	//}

	currentState = newState;
}
