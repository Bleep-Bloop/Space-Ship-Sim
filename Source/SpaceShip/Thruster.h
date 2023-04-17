// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Thruster.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACESHIP_API UThruster : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UThruster();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* TemporaryThrusterStaticMesh; // Will be removed/replaced after adding ship model

	UPROPERTY(EditAnywhere)
	float ThrusterPower = 1;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * ToDo: Should I pass ThrusterPower from the ship class?
	 * @brief Applies force (ThrusterPower) along the x-axis
	 * @param InputValue FInputActionValue.Magnitude passed from the input binding in PlayerShip class. 
	 */
	void ActivateThrust(float InputValue); 
	
};
