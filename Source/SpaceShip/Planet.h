// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planet.generated.h"

/*
 * A physical object (planet) that objects can collide with.
 * Objects with physics enabled will orbit around the planet
 */
UCLASS()
class SPACESHIP_API APlanet : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	APlanet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * @brief Visual representation of the planet
	 * @note /** IMPORTANT Static mesh but be scaled on import to properly size the orbit effector.
	 *			 scaling in engine will cause the effector zone to be too small.
	 */
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlanetStaticMesh;

	//UPROPERTY(EditAnywhere)
	//UStaticMeshComponent* TestStaticMesh;
	
	// ToDo: AOrbitEffector* OrbitEffector;
	//UPROPERTY(EditAnywhere)
	//AOrbitEffector* OrbitEffector;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
