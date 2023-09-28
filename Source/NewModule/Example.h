// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Example.generated.h"

// Note(Lucas): Declaring delegate Type (also called signature)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FExampleDelegate, float, Number, FVector, Location, FString, String);

UCLASS()
class NEWMODULE_API AExample : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExample();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)  
	int ExampleInt;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category=Example)
	FExampleDelegate ExampleEventDispatcher;

	UFUNCTION(BlueprintImplementableEvent)
	bool ExampleFunction(AActor* Actor, const FString& String, FString& ResultString);

	UFUNCTION(BlueprintImplementableEvent)
	void ExampleEvent(AActor* Actor, const FString& String);

	UFUNCTION(BlueprintNativeEvent)
	bool ExampleFunction2(int32 Number);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
