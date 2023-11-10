// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerTank.generated.h"

UCLASS()
class EARTHDEFENDERS_API APlayerTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerTank();

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
	int32 maxHealth = 5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 currentHealth = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterialInterface* materialOriginal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInstanceDynamic* dynaMat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentShootCooldown = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float shootCooldown = 0.75f;
};
