// Fill out your copyright notice in the Description page of Project Settings.


#include "Example.h"

// Sets default values
AExample::AExample()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool AExample::GetActorIsActive()
{
	return bIsActive;
}

void AExample::SetActorIsActive_Implementation(bool bIsActorActive)
{
	this->bIsActive = bIsActorActive;
	UE_LOG(LogTemp, Warning, TEXT("C++ Version of SetActorIsActive"));
}

bool AExample::ExampleFunction2_Implementation(int32 Number)
{
	return false;
}

// Called when the game starts or when spawned
void AExample::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExample::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

