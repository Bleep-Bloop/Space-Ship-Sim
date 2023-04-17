// Fill out your copyright notice in the Description page of Project Settings.


#include "Thruster.h"

#include "EnhancedInputSubsystems.h"

// Sets default values
AThruster::AThruster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ThrusterStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Thruster Static Mesh"));
	RootComponent = ThrusterStaticMesh;
	
}

// Called when the game starts or when spawned
void AThruster::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AThruster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AThruster::ActivateThruster(float InputValue)
{
	// ToDo: Implement Add Force
	//FVector ForwardMovement = FVector((ThrustPower * InputValue), 0, 0); // InputValue = Value.GetMagnitude()
	//ThrusterStaticMeshComp->AddForce(ForwardMovement, NAME_None, true);
	
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::Printf(TEXT("InputValue: %f"), InputValue));
	
}

