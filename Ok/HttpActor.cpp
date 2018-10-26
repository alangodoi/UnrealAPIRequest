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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
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

		/*ArrayOne.Add(TEXT("Id"), TEXT(FString::FromInt(id)));
		ArrayOne.Add(TEXT("Nome"), TEXT(nome));
		ArrayOne.Add(TEXT("DataInicial"), TEXT(DataInicial));
		ArrayOne.Add(TEXT("DataFinal"), TEXT(DataFinal));
		ArrayOne.Add(TEXT("ValorNegociacaoGanha"), TEXT(FString::SanitizeFloat(VNGanha)));
		ArrayOne.Add(TEXT("CountNegociacaoGanha"), TEXT(FString::FromInt(CNGanha)));
		ArrayOne.Add(TEXT("Meta"), TEXT(FString::FromInt(Meta)));
		ArrayOne.Add(TEXT("PercentualMeta"), TEXT(FString::SanitizeFloat(PercentualMeta)));*/

		UE_LOG(LogTemp, Warning, TEXT("===== GET ListEquipe ====="));
		//FString teste = JsonObject->GetField("ListEquipe");
		//UE_LOG(LogTemp, Warning, TEXT(teste));
		//ArrSuco = JsonObject->GetArrayField("ListEquipe");
		//TArray<TSharedPtr<FJsonValue>> objArray = JsonObject->GetArrayField("ListEquipe");
		//ArrTeste = JsonObject->GetArrayField("ListEquipe");
		//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, "printing ListEquipe...");
		UE_LOG(LogTemp, Warning, TEXT("===== printing ListEquipe... ====="));
		auto arr = JsonObject->GetArrayField("ListEquipe");
		for (int32 index = 0; index < arr.Num(); index++)
		{
			//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, "name:" + FString(objArray[index]->AsString()));
			UE_LOG(LogTemp, Warning, TEXT("TESTE"));

			//ArrSuco
			if (index == 0) {
				//ArrSuco.Emplace(FString::FromInt();
				UE_LOG(LogTemp, Warning, TEXT("Index = 0"));
				auto arr2 = arr[0].Get()->TryGetArray;

				//UE_LOG(LogTemp, Warning, TEXT(arr[0].Get()->AsString()));
				//GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, FString(sucoId));
				//UE_LOG(LogTemp, Warning, TEXT(FString(arr[index]["Id"])));
				//ArrSuco.Append(FString(arr[index]["Id"]), arr[index].Num());
				//ArrSuco.Emplace(FString::FromInt(id));
				//ArrSuco.Emplace(nome);
			}
			//ArrEspumante
			else if (index == 1) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 1"));
			}
			//ArrCerveja
			else if (index == 2) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 2"));
			}
			//ArrVinho
			else if (index == 3) {
				UE_LOG(LogTemp, Warning, TEXT("Index = 3"));
			}

			//UE_LOG(LogTemp, Warning, TEXT(objArray[index]->AsString()));
			//UE_LOG(LogTemp, Warning, TEXT(FString(ArrSuco[index])));
		}

		/*for (int itZones = 0; itZones != zonesJs.Num(); itZones++) {
			TSharedPtr<FJsonObject> temp = zonesJs[itZones]->AsObject();
			TArray <TSharedPtr<FJsonValue>> eventJs = temp->GetArrayField("events");
			for (int itEvents = 0; itEvents != eventJs.Num(); itEvents++) {
				TSharedPtr<FJsonObject> tempEventJs = eventJs[itEvents]->AsObject();
				FString nameEvents = tempEventJs->GetStringField("name");

			}*/

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
