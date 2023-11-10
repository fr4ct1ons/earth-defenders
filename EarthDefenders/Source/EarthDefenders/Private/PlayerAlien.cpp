// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAlien.h"

// Sets default values
APlayerAlien::APlayerAlien()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentMovementCount = maxMovementCount;
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
			AActor* alien = NULL;
			alien = world->SpawnActor<AActor>(AlienBP, tempPos, FRotator(0), params);

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
				//For whatever reason this does not work when building, so disabling this for now.
				//alien->SetActorLabel(name);
			}
		}
	}
}

// Called every frame
void APlayerAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(currentMovementCooldown >= 0.0)
	{
		currentMovementCooldown -= DeltaTime;
	}

	if(currentShootCooldown >= 0.0f)
	{
		currentShootCooldown -= DeltaTime;
	}
}

// Called to bind functionality to input
void APlayerAlien::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool APlayerAlien::Movement(float direction)
{

	if(FMath::Abs(direction) >= 0.01f && currentMovementCooldown <= 0.0f)
	{
		if(GEngine)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Emerald, TEXT("Movement"));
		}
		float strength = FMath::Clamp(direction, -1, 1);

		invaderRoot->AddWorldOffset(FVector(0, strength * 50.0f, 0));
		FVector bufferLocation(0);
		bufferLocation = invaderRoot->GetComponentLocation();
		invaderRoot->SetWorldLocation(FVector(bufferLocation.X, FMath::Clamp(bufferLocation.Y, -700, 100), bufferLocation.Z));

		currentMovementCooldown = movementCooldown;
		
		currentMovementCount--;
		if(currentMovementCount <= 0)
		{
			Descend();
		}

		bufferLocation = invaderRoot->GetRelativeLocation();
		
		return true;
	}
	else
	{
		return false;
	}
}

void APlayerAlien::Descend()
{
	currentMovementCount = maxMovementCount;
	invaderRoot->AddWorldOffset(FVector(0.0, 0.0, heightDecreaseAmount));
}

void APlayerAlien::AlienFire()
{
	FHitResult hr;

	if(currentShootCooldown <= 0.0)
	{
		bool hasHit = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, true, hr);

		if(hasHit)
		{
			AActor* actor = hr.GetActor();
		}
	}
	
}

