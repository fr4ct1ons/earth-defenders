// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerAlien.generated.h"

UCLASS()
class EARTHDEFENDERS_API APlayerAlien : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerAlien();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 alienRows = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 alienColumns = 11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> AlienBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent *invaderRoot;
};
