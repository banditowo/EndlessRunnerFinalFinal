// EndlessRunnerScoreSystem.cpp
#include "ScoreSystem.h"

AScoreSystem::AScoreSystem()
{
	PrimaryActorTick.bCanEverTick = false;

	// Initialize score-related variables
	CurrentScore = 0;
	TimeBetweenScoreIncrements = 2.0f; // Adjust this interval as needed
	ScoreToAddOnIncrement = 1; // Adjust the score increment amount as needed
}

void AScoreSystem::BeginPlay()
{
	Super::BeginPlay();

	// Set up the timer to increment the score
	GetWorldTimerManager().SetTimer(ScoreTimerHandle, this, &AScoreSystem::IncrementScore, TimeBetweenScoreIncrements, true);
}

void AScoreSystem::IncrementScore()
{
	// Increment the score at regular intervals
	AddToScore(ScoreToAddOnIncrement);
}

void AScoreSystem::AddToScore(int32 ScoreToAdd)
{
	CurrentScore += ScoreToAdd;
}

int32 AScoreSystem::GetScore() const
{
	return CurrentScore;
}
