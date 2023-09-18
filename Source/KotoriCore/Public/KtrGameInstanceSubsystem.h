// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "KtrGameInstanceSubsystem.generated.h"

/**
 * ゲームインスタンスサブシステムのベースクラス
 */
UCLASS(Abstract, Within = GameInstance)
class KOTORICORE_API UKtrGameInstanceSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnWorldPreActorTick(UWorld* World, ELevelTick LevelTick, float DeltaTime);
	virtual void OnWorldPostActorTick(UWorld* World, ELevelTick LevelTick, float DeltaTime);

protected:
	bool bIsTickable = false;
};
