// Fill out your copyright notice in the Description page of Project Settings.


#include "KtrGameInstanceSubsystem.h"

void UKtrGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FWorldDelegates::OnWorldPreActorTick.AddUObject(this, &UKtrGameInstanceSubsystem::OnWorldPreActorTick);
	FWorldDelegates::OnWorldPostActorTick.AddUObject(this, &UKtrGameInstanceSubsystem::OnWorldPostActorTick);
	bIsTickable = true;
}

void UKtrGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UKtrGameInstanceSubsystem::IsTickable() const
{
	return bIsTickable;
}

TStatId UKtrGameInstanceSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UKtrGameInstanceSubsystem, STATGROUP_Tickables);
}

void UKtrGameInstanceSubsystem::Tick(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UKtrGameInstanceSubsystem::Tick);
}

void UKtrGameInstanceSubsystem::OnWorldPreActorTick(UWorld* World, ELevelTick LevelTick, float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UKtrGameInstanceSubsystem::OnWorldPreActorTick);
}

void UKtrGameInstanceSubsystem::OnWorldPostActorTick(UWorld* World, ELevelTick LevelTick, float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UKtrGameInstanceSubsystem::OnWorldPostActorTick);
}
