

#include "PrecomputedMovementManager.h"

#include "JsonObjectConverter.h"
#include "JsonUtilities.h"
#include "PrecomputedMovementComponent.h"

UPrecomputedMovementManager::UPrecomputedMovementManager()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UPrecomputedMovementManager::BeginPlay()
{
    Super::BeginPlay();
    LoadPrecomputedMovementData();
}

void UPrecomputedMovementManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPrecomputedMovementManager::LoadPrecomputedMovementData()
{
    const auto JsonFilePath =
        FPaths::ProjectConfigDir() + "PrecomputedMovement/Data.json";    // json for now, csv would be more efficient
    if (FPaths::FileExists(JsonFilePath))
    {
        FString Json;
        FFileHelper::LoadFileToString(Json, *JsonFilePath);
        FJsonObjectConverter::JsonObjectStringToUStruct<FPrecomputedMovementDataCollection>(
            Json, &PrecomputedMovementDataCollection, 0, 0);
        if (ensureAlways(ActorClass != nullptr))
        {
            for (const auto& Actor : PrecomputedMovementDataCollection.Actors)
            {
                auto A = GetWorld()->SpawnActor<AActor>(ActorClass, FVector::ZeroVector, FRotator::ZeroRotator);
                A->SetActorLabel(Actor.Name);
                const auto Component = A->FindComponentByClass<UPrecomputedMovementComponent>();
                if (ensureAlways(Component != nullptr))
                {
                    Component->Path = Actor.MovementPath;
                }
            }
        }
    }
}
