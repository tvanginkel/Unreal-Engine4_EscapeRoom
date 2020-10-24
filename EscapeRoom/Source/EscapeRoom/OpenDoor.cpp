// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Engine/World.h"
#include "Grabber.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

}

//Opens door to the set angle

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PressurePlate) { UE_LOG(LogTemp, Error, TEXT("PressurePlate not found")); return; }

		if (GetTotalMassOfActorsOnPlate() >= MinMass) ///TODO make into paraeter
		{
			OnOpenRequest.Broadcast();
		}
		else
		{
			OnCloseRequest.Broadcast();
		}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;

	///Find all the  overlapping actors
	TArray <AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	///Iterate
	for (const auto& Index : OverlappingActors)
	{
		TotalMass += Index->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}

