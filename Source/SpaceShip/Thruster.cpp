// Fill out your copyright notice in the Description page of Project Settings.


#include "Thruster.h"

// Sets default values for this component's properties
UThruster::UThruster()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
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

void UThruster::ActivateThrust(UStaticMeshComponent* ParentStaticMesh, float InputValue) const
{

	if(ParentStaticMesh)
	{
		FVector ForwardThrustMoveVector = (ParentStaticMesh->GetRightVector() * ThrusterPower) * InputValue;
		ParentStaticMesh->AddForce(ForwardThrustMoveVector, NAME_None, true);
	}
	
}

void UThruster::RotateThrust(UStaticMeshComponent* ParentStaticMesh, float InputValue) const
{

	if(ParentStaticMesh)
	{
		FVector RotateThrustMoveVector = FVector(0,0,RotateThrusterPower) * InputValue;
		ParentStaticMesh->AddTorqueInDegrees(RotateThrustMoveVector, NAME_None, true);
	}
	
}

