// EndlessRunnerScoreSystem.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreSystem.generated.h"

UCLASS()
class YOURPROJECT_API AScoreSystem : public AActor
{
	GENERATED_BODY()

public:
	AScoreSystem();

	// Function to increment the score
	void IncrementScore();

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddToScore(int32 ScoreToAdd);

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;

protected:
	virtual void BeginPlay() override;

private:
	int32 CurrentScore;

	// Time interval between score increments (in seconds)
	float TimeBetweenScoreIncrements;

	// Amount to add to the score with each increment
	int32 ScoreToAddOnIncrement;

	FTimerHandle ScoreTimerHandle;
};
