// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExampleActorPool.generated.h"

UCLASS()
class NEWMODULE_API AExampleActorPool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExampleActorPool();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AExample> ActorClass;

	TArray<AExample*> Pool;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable)
	void InitializePool(int32 Count);

	UFUNCTION(BlueprintCallable)
	AActor* ActivateActorFromPool();

	UFUNCTION(BlueprintCallable)
	bool DeactivateActorFromPool(AExample* Actor);


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
