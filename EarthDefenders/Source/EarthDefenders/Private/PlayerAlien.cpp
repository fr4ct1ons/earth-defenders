// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAlien.h"

// Sets default values
APlayerAlien::APlayerAlien()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerAlien::BeginPlay()
{
	Super::BeginPlay();
	FVector tempPos = FVector(0.0);
	UWorld* world = GetWorld();
	
	for (int y = 0; y < alienRows; y++)
	{
		for (int x = 0; x < alienColumns; x++)
		{
			tempPos.Set(0, 50*static_cast<double>(x), -50*static_cast<double>(y));
			FString name = FString("Invader " + FString::FromInt(x) + "_" + FString::FromInt(y));
			FActorSpawnParameters params;
			//params.bNoFail = true;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AActor* alien = world->SpawnActor<AActor>(AlienBP, tempPos, FRotator(0), params);

			if(alien == NULL)
			{
				UE_LOG(LogTemp, Warning, TEXT("Null!"));
			}
			else
			{
				alien->SetActorLocation(tempPos);
				if(invaderRoot != NULL)
				{
					alien->AttachToComponent(invaderRoot, FAttachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true));
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Root is null!"));
				}
				alien->SetActorLabel(name);
			}
		}
	}
}

// Called every frame
void APlayerAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerAlien::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

