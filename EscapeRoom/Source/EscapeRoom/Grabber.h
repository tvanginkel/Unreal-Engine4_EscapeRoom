// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	APlayerController* Controller;



private:
	/// How far grabber can reach
	UPROPERTY(EditAnywhere)
	float Reach = 200.f;
		
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab
	void Grab();

	//Called when grab is released
	void Release();

	//Looks for UInputComponent 
	void SetInputComponent();

	//Looks for UPhysicsHandleComponent 
	void SetPhysicsComponent();

	FVector GetReachLineEnd();
	FVector GetReachLineStart();

	FHitResult GetFirstPhysicsBodyInReach();
};
