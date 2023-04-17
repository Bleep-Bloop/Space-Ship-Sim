// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Thruster.generated.h"

UCLASS()
class SPACESHIP_API AThruster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThruster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UStaticMeshComponent* ThrusterStaticMesh;
	
	UPROPERTY(EditAnywhere, Category = "Stats")
	float ThrusterPower = 1;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ActivateThruster(float InputValue); // Passed FInputActionValue.Magnitude
	
};
