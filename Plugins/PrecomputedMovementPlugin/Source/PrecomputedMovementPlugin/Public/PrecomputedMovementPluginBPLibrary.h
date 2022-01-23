#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "PrecomputedMovementPluginBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FPrecomputedMovementData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FVector> MovementPath;
};

USTRUCT(BlueprintType)
struct FPrecomputedMovementDataCollection
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FPrecomputedMovementData> Actors;
};

UCLASS()
class UPrecomputedMovementPluginBPLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()
};
