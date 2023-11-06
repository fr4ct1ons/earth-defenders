// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"

// Sets default values
APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentHealth = maxHealth;
	
	dynaMat = UMaterialInstanceDynamic::Create(materialOriginal, this);
	dynaMat->SetScalarParameterValue("IntegrityLevel", static_cast<float>(currentHealth)/static_cast<float>(maxHealth));
}

// Called when the game starts or when spawned


//on PlayerTank.h:
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

