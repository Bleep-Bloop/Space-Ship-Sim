// Fill out your copyright notice in the Description page of Project Settings.


#include "Thruster.h"

// Sets default values for this component's properties
UThruster::UThruster()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//TemporaryThrusterStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Temp Thruster Static Mesh");
	//TemporaryThrusterStaticMesh->SetSimulatePhysics(true);
	
}

// Called when the game starts
void UThruster::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UThruster::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UThruster::ActivateThrust(UStaticMeshComponent* ParentStaticMesh, float InputValue)
{

	if(ParentStaticMesh)
	{
		FVector ForwardThrustMoveVec = (FVector::RightVector * ThrusterPower) * InputValue;
		ParentStaticMesh->AddForce(ForwardThrustMoveVec, NAME_None, true);
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("UThruster::InputValue: %f"), InputValue));
}

