﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/AssetManager.h"
#include "KtrStremableManager.generated.h"

DECLARE_DELEGATE_OneParam(FKtrStreamableDelegate, const TArray<UObject*>&);

/**
 * 独自のアセット読み込みマネージャ
 */
UCLASS()
class KOTORICORE_API UKtrStreamableManager : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	TSharedPtr<FStreamableHandle> RequestSyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete = FKtrStreamableDelegate());
	TSharedPtr<FStreamableHandle> RequestAsyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete = FKtrStreamableDelegate());

	virtual TStatId GetStatId() const override{ RETURN_QUICK_DECLARE_CYCLE_STAT(UKtrStreamableManager, STATGROUP_Tickables); };
	virtual void Tick(float DeltaTime) override;

private:
	struct KtrHandle
	{
		TSharedPtr<FStreamableHandle> StreamableHandle;
		FKtrStreamableDelegate OnComplete;
	};
	TArray<KtrHandle> KtrHandles;
};
