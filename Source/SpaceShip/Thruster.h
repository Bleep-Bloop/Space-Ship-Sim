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

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	* ToDo: Should I pass ThrusterPower from the ship class?
	* @brief Applies force (ThrusterPower) along the X-axis
	* @param ParentStaticMesh StaticMeshComponent of the parent class. Used to AddTorque.
	* @param InputValue FInputActionValue.Magnitude passed from the input binding in PlayerShip class. 
	*/
	void ActivateThrust(UStaticMeshComponent* ParentStaticMesh, float InputValue) const;

	/**
	* ToDo: Should I pass ThrusterPower from the ship class?
	* @brief Adds torque (RotateThrusterPower) around Z-axis
	* @param ParentStaticMesh StaticMeshComponent of the parent class. Used to AddTorque.
	* @param InputValue FInputActionValue.Magnitude passed from the input binding in PlayerShip class. 
	*/
	void RotateThrust(UStaticMeshComponent* ParentStaticMesh, float InputValue) const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(EditAnywhere)
	float ThrusterPower = 2500;

	/**
	 * @note Change the parent's static mesh 'Angular Drag' to effect rotation stop (3.5 is a good starting point)
	 */
	UPROPERTY(EditAnywhere)
	float RotateThrusterPower = 300;
	
};
