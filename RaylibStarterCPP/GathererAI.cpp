#include "GathererAI.h"

GathererAI::GathererAI(Gatherer* selectedGatherer, GameWorld* gWPointer)
{
}

GathererAI::~GathererAI()
{
}

void GathererAI::Update()
{
	switch (currentState)
	{
	case GatherState::Idle:
	{

	}
	case GatherState::Gather:
	{

	}
	case GatherState::Transport:
	{

	}
	}
}

void GathererAI::TransitionState(GatherState newState)
{
}
