// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleActorPool.h"
#include "Example.h"

// Sets default values
AExampleActorPool::AExampleActorPool()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExampleActorPool::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExampleActorPool::InitializePool(int32 Count)
{
	Pool.Reset(Count);

	for (int i = 0; i < Count; i++)
	{
		AExample* Spawned;

		// Note(Lucas): This variable is expected to be set on a blueprint that inherits this class
		if (ActorClass)
		{
			Spawned = GetWorld()->SpawnActor<AExample>(ActorClass, (FMath::VRand()*FVector(500.,500.,0.)), FRotator(0., 0., 0.));
		}
		else
		{
			Spawned = GetWorld()->SpawnActor<AExample>(FVector(0., 0., 0.), FRotator(0., 0., 0.));
		}

		if (Spawned)
		{
			Pool.Add(Spawned);
			Spawned->SetActorIsActive(false);
		}
	}
}

AActor* AExampleActorPool::ActivateActorFromPool()
{
	for (int i = 0; i < Pool.Num(); i++)
	{
		if (Pool[i] && !Pool[i]->GetActorIsActive())
		{
			Pool[i]->SetActorIsActive(true);

			return Pool[i];
		}
	}
	return nullptr;
}

bool AExampleActorPool::DeactivateActorFromPool(AExample* Actor)
{
	int index = 0;
	if (Pool.Find(Actor, index))
	{
		Pool[index]->SetActorIsActive(false);
		return true;
	}

	return false;
}

// Called every frame
void AExampleActorPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

