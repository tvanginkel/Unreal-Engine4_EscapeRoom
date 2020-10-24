// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor2.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

#define OUT


// Sets default values for this component's properties
UOpenDoor2::UOpenDoor2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor2::BeginPlay()
{
	Super::BeginPlay();

	CloseAngle = GetOwner()->GetActorRotation();
	
}


// Called every frame
void UOpenDoor2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TotalMass = 0.f;

	if (!RedVolume) { UE_LOG(LogTemp, Error, TEXT("RedVolume not found"));   return; }
	if (!BlueVolume) { UE_LOG(LogTemp, Error, TEXT("BlueVolume not found"));  return; }
	if (!GreenVolume) { UE_LOG(LogTemp, Error, TEXT("GreenVolume not found")); return; }
	if (!WhiteVolume) { UE_LOG(LogTemp, Error, TEXT("WhiteVolume not found")); return; }

	TArray<AActor*> RedCubes;
	TArray<AActor*> BlueCubes;
	TArray<AActor*> GreenCubes;
	TArray<AActor*> WhiteCubes;

	RedVolume->GetOverlappingActors(OUT RedCubes);
	BlueVolume->GetOverlappingActors(OUT BlueCubes);
	GreenVolume->GetOverlappingActors(OUT GreenCubes);
	WhiteVolume->GetOverlappingActors(OUT WhiteCubes);

	for (auto& Index : RedCubes)
	{
		UCubeTipe* CubeComponent = Index->FindComponentByClass<UCubeTipe>();
		if (!CubeComponent || CubeComponent && CubeComponent->GetType() != 1)
		{
			Index = nullptr;
			continue;
		}
		TotalMass += Index->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	for (auto& Index : BlueCubes)
	{
		UCubeTipe* CubeComponent = Index->FindComponentByClass<UCubeTipe>();
		if (!CubeComponent || CubeComponent && CubeComponent->GetType() != 2)
		{		
			Index = nullptr;
			continue;
		}
		TotalMass += Index->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	for (auto& Index : GreenCubes)
	{
		UCubeTipe* CubeComponent = Index->FindComponentByClass<UCubeTipe>();
		if (!CubeComponent || CubeComponent && CubeComponent->GetType() != 3)
		{
			Index = nullptr;
			continue;
		}
		TotalMass += Index->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	for (auto& Index : WhiteCubes)
	{
		UCubeTipe* CubeComponent = Index->FindComponentByClass<UCubeTipe>();
		if (!CubeComponent || CubeComponent && CubeComponent->GetType() != 0)
		{
			Index = nullptr;
			continue;
		}
		TotalMass += Index->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	CheckTotalMass();
}

	void UOpenDoor2::CheckTotalMass()
	{
		if (TotalMass >= MinMass)
		{
			OnOpen.Broadcast();
		}
		else
		{
			OnClose.Broadcast();
		}
	}


