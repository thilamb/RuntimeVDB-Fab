// Copyright (c) 2026 Thibault Lambert

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "MyActor.h"
#include "RuntimeVDBFunctionLibrary.h"

void UDelegateProxy::OnVdbLoaded(USparseVolumeTexture* Volume)
{
	ElapsedTime = FPlatformTime::Seconds() - StartTime;

	if (LambdaCallback)
	{
		LambdaCallback(this, Volume);
	}
}

void UDelegateProxy::OnVdbError(FText Error)
{
	// Handle Error here
}

//------------------------------------------------------------------------------------------

AMyActor::AMyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	auto GenericCallback = [this, bShouldRender = RenderAfterImport](UDelegateProxy* Proxy, USparseVolumeTexture* Volume)
		{
			UE_LOG(LogTemp, Warning, TEXT("Succesfully loaded VDB %s in %f seconds."), *Proxy->Filename, Proxy->ElapsedTime);

			if (bShouldRender)
			{
                // Do something
			}

			ActiveRequests.Remove(Proxy); // Remove reference
		};

	auto AddRequest = [this, GenericCallback](UDelegateProxy* Proxy, const FString& Filename)
		{
			Proxy->Filename = Filename;
			Proxy->StartTime = FPlatformTime::Seconds();
			if (!Proxy->LambdaCallback)
			{
				Proxy->LambdaCallback = GenericCallback;
			}

			FAsyncVdbLoader OkDelegate;
			OkDelegate.BindDynamic(Proxy, &UDelegateProxy::OnVdbLoaded);

			FVdbLoaderError ErrorDelegate;
			ErrorDelegate.BindDynamic(Proxy, &UDelegateProxy::OnVdbError);

			URuntimeVDBFunctionLibrary::AsyncLoadRuntimeVdbFromFilename(Filename, FVdbImportOptions{}, OkDelegate, ErrorDelegate);

			ActiveRequests.Add(Proxy); // keep reference to prevent garbage collection
		};


    // First OpenVDB async load
	UDelegateProxy* ProxyA = NewObject<UDelegateProxy>(this);
	AddRequest(ProxyA, "D:/VDBs/wdas_cloud_half.vdb");

    // Second OpenVDB async load
	UDelegateProxy* ProxyB = NewObject<UDelegateProxy>(this);
	AddRequest(ProxyB, "D:/VDBs/bunny_cloud.vdb");

    // Third OpenVDB async load with custom callback
	UDelegateProxy* ProxyC = NewObject<UDelegateProxy>(this);
	ProxyC->LambdaCallback = [this](UDelegateProxy* Proxy, USparseVolumeTexture* Volume) // Custom callback
		{
			UE_LOG(LogTemp, Warning, TEXT("Alternate lambda callback after succesfully loading VDB %s in %f seconds."), *Proxy->Filename, Proxy->ElapsedTime);
			ActiveRequests.Remove(Proxy); // Remove reference
		};
	AddRequest(ProxyC, "D:/VDBs/wdas_cloud_quarter.vdb");
}
