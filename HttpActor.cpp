// Fill out your copyright notice in the Description page of Project Settings.

#include "HttpActor.h"
#include "Http.h"
#include "Json.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"


// Sets default values
AHttpActor::AHttpActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

//TMap<FString, FString> AHttpActor::getStr(FString id, FString mes)
void AHttpActor::getStr(FString id, FString mes)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
	FHttpModule* Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb("GET");
	//HttpRequest->SetURL("https://api.crmsimples.com.br/API?method=getPainelGame&id=8&mes=1");
	FString URL = "https://api.crmsimples.com.br/API?method=getPainelGame&id=" + id;
	URL += "&mes=";
	URL = URL + mes;
	HttpRequest->SetURL(URL);
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetHeader(TEXT("token"), TEXT("46f343fba7-77b1-4442-89c4-f82a7f33079b"));

	HttpRequest->ProcessRequest();
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &AHttpActor::OnResponseReceived);
}

//TMap<FString, FString> AHttpActor::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
void AHttpActor::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {

	//Create a pointer to hold the json serialized data
	TSharedPtr<FJsonObject> JsonObject;

	//Create a reader pointer to read the json data
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	//Deserialize the json data given Reader and the actual object to deserialize
	if (FJsonSerializer::Deserialize(Reader, JsonObject)) {

		//Get the value of the json object by field name
		int32 id = JsonObject->GetIntegerField("Id");
		FString nome = JsonObject->GetStringField("Nome");
		FString DataInicial = JsonObject->GetStringField("DataInicial");
		FString DataFinal = JsonObject->GetStringField("DataFinal");
		double VNGanha = JsonObject->GetNumberField("ValorNegociacaoGanha");
		int32 CNGanha = JsonObject->GetIntegerField("CountNegociacaoGanha");
		int32 Meta = JsonObject->GetIntegerField("Meta");
		double PercentualMeta = JsonObject->GetNumberField("PercentualMeta");

		//Add data to array
		ArrCaveJolimont.Emplace(FString::FromInt(id));
		ArrCaveJolimont.Emplace(nome);
		ArrCaveJolimont.Emplace(DataInicial);
		ArrCaveJolimont.Emplace(DataFinal);
		ArrCaveJolimont.Emplace(FString::SanitizeFloat(VNGanha));
		ArrCaveJolimont.Emplace(FString::FromInt(CNGanha));
		ArrCaveJolimont.Emplace(FString::FromInt(Meta));
		ArrCaveJolimont.Emplace(FString::SanitizeFloat(PercentualMeta));

		TArray <TSharedPtr<FJsonValue>> marr = JsonObject->GetArrayField("ListEquipe");
		for (int i = 0; i != marr.Num(); i++) {
			TSharedPtr<FJsonObject> temp = marr[i]->AsObject();
			//ArrSuco
			if (i == 0) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 0"));
				ArrSuco.Emplace(FString::FromInt(temp->GetIntegerField("Id")));
				ArrSuco.Emplace(temp->GetStringField("Nome"));
				ArrSuco.Emplace(temp->GetStringField("Cor"));
				ArrSuco.Emplace(FString::SanitizeFloat(temp->GetNumberField("ValorNegociacaoGanha")));
				ArrSuco.Emplace(FString::FromInt(temp->GetIntegerField("CountNegociacaoGanha")));
				ArrSuco.Emplace(FString::FromInt(temp->GetIntegerField("Meta")));
				ArrSuco.Emplace(FString::SanitizeFloat(temp->GetNumberField("PercentualMeta")));
			}
			//ArrEspumante
			else if (i == 1) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 1"));
				ArrEspumante.Emplace(FString::FromInt(temp->GetIntegerField("Id")));
				ArrEspumante.Emplace(temp->GetStringField("Nome"));
				ArrEspumante.Emplace(temp->GetStringField("Cor"));
				ArrEspumante.Emplace(FString::SanitizeFloat(temp->GetNumberField("ValorNegociacaoGanha")));
				ArrEspumante.Emplace(FString::FromInt(temp->GetIntegerField("CountNegociacaoGanha")));
				ArrEspumante.Emplace(FString::FromInt(temp->GetIntegerField("Meta")));
				ArrEspumante.Emplace(FString::SanitizeFloat(temp->GetNumberField("PercentualMeta")));
			}
			//ArrCerveja
			else if (i == 2) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 1"));
				ArrCerveja.Emplace(FString::FromInt(temp->GetIntegerField("Id")));
				ArrCerveja.Emplace(temp->GetStringField("Nome"));
				ArrCerveja.Emplace(temp->GetStringField("Cor"));
				ArrCerveja.Emplace(FString::SanitizeFloat(temp->GetNumberField("ValorNegociacaoGanha")));
				ArrCerveja.Emplace(FString::FromInt(temp->GetIntegerField("CountNegociacaoGanha")));
				ArrCerveja.Emplace(FString::FromInt(temp->GetIntegerField("Meta")));
				ArrCerveja.Emplace(FString::SanitizeFloat(temp->GetNumberField("PercentualMeta")));
			}
			//ArrVinho
			else if (i == 3) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 1"));
				ArrVinho.Emplace(FString::FromInt(temp->GetIntegerField("Id")));
				ArrVinho.Emplace(temp->GetStringField("Nome"));
				ArrVinho.Emplace(temp->GetStringField("Cor"));
				ArrVinho.Emplace(FString::SanitizeFloat(temp->GetNumberField("ValorNegociacaoGanha")));
				ArrVinho.Emplace(FString::FromInt(temp->GetIntegerField("CountNegociacaoGanha")));
				ArrVinho.Emplace(FString::FromInt(temp->GetIntegerField("Meta")));
				ArrVinho.Emplace(FString::SanitizeFloat(temp->GetNumberField("PercentualMeta")));
			}
		}
			//Count Array
			//int32 CountArr = ArrSuco.Num();

			//Output it to the engine
			//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString(wtf));
			//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString::FromInt(id) + FString(nome) + FString(DataInicial) + FString(DataFinal) + FString::SanitizeFloat(VNGanha) + FString::FromInt(CNGanha) + FString::FromInt(Meta) + FString::SanitizeFloat(PercentualMeta));
	}
}

// Called when the game starts or when spawned
void AHttpActor::BeginPlay()
{
	Super::BeginPlay();
	//getStr();
}

// Called every frame
void AHttpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
