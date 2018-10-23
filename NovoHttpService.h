#pragma once
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpActor.generated.h"

UCLASS(BLUEPRINTABLE) 
class CPPPROJECT_API AHttpActor : public AActor { 
  GENERATED_BODY()

public:	FHttpModule* Https;
  
  UPROPERTY(BlueprintReadOnly)

/* The actual HTTP call */
UFUNCTION() void MyHttpCall();

/*Assign this function to call when the GET request processes sucessfully*/
void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

// Sets default values for this actor's properties
AHttpActor(const class FObjectInitializer& ObjectInitializer);

// Called when the game starts or when spawned virtual
void BeginPlay() override; 
};
