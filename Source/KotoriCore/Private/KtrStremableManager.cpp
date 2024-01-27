// Fill out your copyright notice in the Description page of Project Settings.


#include "KtrStremableManager.h"

TSharedPtr<FStreamableHandle> UKtrStreamableManager::RequestAsyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete)
{
	auto&& streamableManager = UAssetManager::GetStreamableManager();
	auto&& handle = streamableManager.RequestAsyncLoad(Path);
	handle->BindCompleteDelegate(FStreamableDelegate::CreateLambda([handle, OnComplete]()
	{
		TArray<UObject*> loadedAssets;
		handle->GetLoadedAssets(loadedAssets);
		OnComplete.ExecuteIfBound(loadedAssets);
		UE_LOG(LogTemp, Log, TEXT("CompleteLoadedAssets"));
		handle->ReleaseHandle();
	}));
	return handle;
}
