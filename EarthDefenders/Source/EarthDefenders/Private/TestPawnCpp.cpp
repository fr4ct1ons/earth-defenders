// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawnCpp.h"

// Sets default values
ATestPawnCpp::ATestPawnCpp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestPawnCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPawnCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawnCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

