// Fill out your copyright notice in the Description page of Project Settings.


#include "KtrStremableManager.h"

TSharedPtr<FStreamableHandle> UKtrStreamableManager::RequestSyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UKtrStreamableManager::RequestSyncLoad);
	auto&& streamableManager = UAssetManager::GetStreamableManager();
	auto&& handle = streamableManager.RequestSyncLoad(Path);
	KtrHandles.Add({handle, OnComplete});
	return handle;
}

TSharedPtr<FStreamableHandle> UKtrStreamableManager::RequestAsyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete)
{
	auto&& streamableManager = UAssetManager::GetStreamableManager();
	auto&& handle = streamableManager.RequestAsyncLoad(Path);
	KtrHandles.Add({handle, OnComplete});
	return handle;
}

void UKtrStreamableManager::Tick(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UKtrStreamableManager::Tick);
	for (auto&& KtrHandle : KtrHandles)
	{
		if(KtrHandle.OnComplete.IsBound())
		{
			if(KtrHandle.StreamableHandle->HasLoadCompleted())
			{
				TRACE_CPUPROFILER_EVENT_SCOPE(UKtrStreamableManager::Tick::OnComplete);
				TArray<UObject*> loadedAssets;
				KtrHandle.StreamableHandle->GetLoadedAssets(loadedAssets);
				//読み込みアセットを引数にするCompleteデリゲート呼び出し
				KtrHandle.OnComplete.ExecuteIfBound(loadedAssets);
			}	
		}
	}
	TRACE_CPUPROFILER_EVENT_SCOPE(KtrHandes.RemoveAll);
	KtrHandles.RemoveAll([](const KtrHandle& handle)
	{
		const bool bRet = handle.StreamableHandle->HasLoadCompleted() || handle.StreamableHandle->WasCanceled(); 
		if(bRet)
		{
			handle.StreamableHandle->ReleaseHandle();
		}
		return bRet;
	});
}
