// Fill out your copyright notice in the Description page of Project Settings.

#include "HttpService.h"


// Sets default values
AHttpService::AHttpService()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHttpService::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHttpService::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

