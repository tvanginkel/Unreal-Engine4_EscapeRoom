// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CubeTipe.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor2.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpen2Request);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))

class ESCAPEROOM_API UOpenDoor2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor2();

	UPROPERTY(BlueprintAssignable)
		FOnOpen2Request OnOpen;

	UPROPERTY(BlueprintAssignable)
		FOnOpen2Request OnClose;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CheckTotalMass();

	UPROPERTY(EditAnywhere)
	ATriggerVolume* BlueVolume = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* RedVolume = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* GreenVolume = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* WhiteVolume = nullptr;

	FRotator CloseAngle;

	UPROPERTY(EditAnywhere)
	float MinMass = 60.f;

	float TotalMass = 0.f;



	//AActor* ActorThatOverlapps;

		
	
};
