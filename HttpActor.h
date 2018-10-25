#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpActor.generated.h"

UCLASS(BLUEPRINTABLE)
class APPJOLIMONT_API HttpActor : public AActor
{
	//GENERATED_BODY()

public:

	HttpActor();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	/*UFUNCTION()
		void sendStr();*/
	UFUNCTION()
		void getStr();
	//UFUNCTION()
		//void OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);


};
