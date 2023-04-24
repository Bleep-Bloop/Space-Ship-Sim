// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShip.h"
#include "EnhancedInputSubsystems.h"


#include "../../../../../../../../../../Program Files/Epic Games/UE_5.1/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"

// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipStaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship Static Mesh"));

	RootComponent = ShipStaticMeshComp;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Players Camera"));
	Camera->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);

	
	RearThruster = CreateDefaultSubobject<UThruster>("Back Thruster");
	RearThruster->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform, NAME_None);
	
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController *PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<
				UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CharacterMappingContext, 0);
		}
	}
	
}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(ForwardThrustAction, ETriggerEvent::Triggered, this, &APlayerShip::ForwardThrust);
	}
	
}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerShip::ForwardThrust(const FInputActionValue& Value)
{
	
		if(RearThruster)
			RearThruster->ActivateThrust(ShipStaticMeshComp, Value.GetMagnitude());
	
}


