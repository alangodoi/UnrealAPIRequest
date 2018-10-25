// Fill out your copyright notice in the Description page of Project Settings.

#include "HttpActor.h"
#include "Http.h"
#include "Json.h"
#include "Engine/Engine.h"


// Sets default values
AHttpActor::AHttpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void HttpActor::getStr()
{
	FHttpModule* Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetURL("https://api.crmsimples.com.br/API?method=getPainelGame&id=8&mes=1");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetHeader(TEXT("token"), TEXT("46f343fba7-77b1-4442-89c4-f82a7f33079b"));

	//HttpRequest->OnProcessRequestComplete().BindUObject(this, &HttpActor::OnRequestComplete);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));

	HttpRequest->ProcessRequest();
}

// Called when the game starts or when spawned
void AHttpActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AHttpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
