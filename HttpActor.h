// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Http.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpActor.generated.h"

UCLASS(BLUEPRINTABLE)
class APPJOLIMONT2_API AHttpActor : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FString> ArrCaveJolimont;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FString> ArrSuco;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FString> ArrEspumante;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FString> ArrCerveja;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		TArray<FString> ArrVinho;

	UFUNCTION(BlueprintCallable)
		//TMap<FString, FString> getStr(FString id, FString mes);
		void getStr(FString id, FString mes);
	//UFUNCTION(BlueprintCallable)
	//TMap<FString, FString> OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	//Sets default values for this actor's properties
	AHttpActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*public:

		AHttpActor();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		UFUNCTION(BlueprintCallable)
			void getStr();*/

};
