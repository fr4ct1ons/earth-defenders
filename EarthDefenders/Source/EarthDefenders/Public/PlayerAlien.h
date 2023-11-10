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
	void Descend();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 alienRows = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 alienColumns = 11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> AlienBP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent *invaderRoot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float minShootCooldown = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxShootCooldown = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentShootCooldown = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float selectShootCooldown = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float currentMovementCooldown = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float movementCooldown = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 currentMovementCount = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 maxMovementCount = 12;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float heightDecreaseAmount = -50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float winDescension = 500.0f;
	
	UFUNCTION(BlueprintCallable)
	virtual bool Movement(float direction);

	UFUNCTION(BlueprintCallable)
	virtual void AlienFire();
};
