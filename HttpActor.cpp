#include "HttpActor.h"
#include "Http.h"
#include "Json.h"
#include "Engine/Engine.h"

HttpActor::HttpActor()
{
}

/*void HttpActor::sendStr()
{
	FHttpModule* Http = &FHttpModule::Get();
	TSharedRef<IHttpRequest> HttpRequest = Http->CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "text/plain");
	HttpRequest->SetURL("localhost:8080/a");
	HttpRequest->SetContentAsString("POST string from UE4");
	HttpRequest->ProcessRequest();
}*/

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

/*void HttpActor::OnRequestComplete(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response->GetContentType() == TEXT("text/plain"))
	{
		FString result = Response->GetContentAsString();

		GEngine->AddOnScreenDebugMessage(0, 4.0f, FColor::Orange, TEXT("%s"), *result);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(0, 4.0f, FColor::Emerald, TEXT("The Message Wanst receibed"));
	}
}*/


void HttpActor::BeginPlay()
{
	//Super::BeginPlay();

	//sendStr();

}

void HttpActor::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);

}
