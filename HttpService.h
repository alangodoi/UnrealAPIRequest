// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HttpService.generated.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "Json.h"
#include "JsonUtilities.h"

UCLASS()
class APPJOLIMONT_API AHttpService : public AActor
{
	GENERATED_BODY()

private:
FHttpModule* Http, Https;
FString ApiBaseUrl = "https://api.crmsimples.com.br/API?method=getPainelGame";

FString AuthorizationHeader = TEXT("Authorization");
void SetAuthorizationHash(FString Hash, TSharedRef<IHttpRequest>& Request);

TSharedRef<IHttpRequest> RequestWithRoute(FString Subroute);
void SetRequestHeaders(TSharedRef<IHttpRequest>& Request);

TSharedRef<IHttpRequest> GetRequest(FString Subroute);
TSharedRef<IHttpRequest> PostRequest(FString Subroute, FString ContentJsonString);
void Send(TSharedRef<IHttpRequest>& Request);

bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);

template <typename StructType>
void GetJsonStringFromStruct(StructType FilledStruct, FString& StringOutput);
template <typename StructType>
void GetStructFromJsonString(FHttpResponsePtr Response, StructType& StructOutput);

public:
	// Sets default values for this actor's properties
	AHttpService();
	virtual void BeginPlay() override;

	/*void Login(FRequest_Login LoginCredentials);
	void LoginResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
