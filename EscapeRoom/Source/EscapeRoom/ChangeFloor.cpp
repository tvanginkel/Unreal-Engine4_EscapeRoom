// Fill out your copyright notice in the Description page of Project Settings.

#include "ChangeFloor.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UChangeFloor::UChangeFloor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UChangeFloor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOverlaps = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UChangeFloor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ElevatorSpace->IsOverlappingActor(ActorThatOverlaps) && done != true)
	{
		//for (int32 i = 0; i < 450; i++)
		//{
		//	FVector NewPos = GetOwner()->GetTransform().GetLocation() - FVector(0.f, 0.f, 1.f);
		//	GetOwner()->SetActorLocation(NewPos);
		//}

		//done = true;
		//GetOwner()->SetActorLocation(FVector(852.f,-1658.f,-604.f));
	}
}

