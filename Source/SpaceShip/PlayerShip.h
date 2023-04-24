// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Thruster.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "PlayerShip.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class SPACESHIP_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components", meta = (AllowPrivateAccess = true));
	UCameraComponent* Camera;
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext *CharacterMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input", meta = (AllowPrivateAccess)) //If true, properties defined in the C++ private scope will be accessible to blueprints
	UInputAction* ForwardThrustAction;

	void ForwardThrust(const FInputActionValue &Value);
	
	UPROPERTY(EditAnywhere, Category="Components")
	UThruster* RearThruster;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* ShipStaticMeshComp;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
