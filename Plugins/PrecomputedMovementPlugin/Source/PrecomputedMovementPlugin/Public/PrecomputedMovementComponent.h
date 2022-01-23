// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"

#include "PrecomputedMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRECOMPUTEDMOVEMENTPLUGIN_API UPrecomputedMovementComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FVector> Path;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float PlayRate = 1.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartTime = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsPlaying = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsLooping = true;

    UPrecomputedMovementComponent();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
