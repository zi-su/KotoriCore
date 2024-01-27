// Fill out your copyright notice in the Description page of Project Settings.

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
class KOTORICORE_API UKtrStreamableManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static TSharedPtr<FStreamableHandle> RequestAsyncLoad(const TArray<FSoftObjectPath>& Path, const FKtrStreamableDelegate& OnComplete = FKtrStreamableDelegate());
};
