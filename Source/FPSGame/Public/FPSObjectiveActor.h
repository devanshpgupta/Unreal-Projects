// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"
class USphereComponent;

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:

	//In order to expose we need to define it under UPROPERTY MACROOOOOOO
	UPROPERTY(VisibleAnywhere, Category = "Components")

	//To assign a visual representation  like Box or Sphere
	UStaticMeshComponent * MeshComp;

	//In order to expose we need to define it under UPROPERTY MACROOOOOOO
	UPROPERTY(VisibleAnywhere, Category="Components")

	//USphereComponent- It is used to hold some collision information
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, category = "Effects")
	UParticleSystem* PickupFX;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Spawn some particle effect whenever we overlap this objective
	void PlayEfects();

	
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
};
