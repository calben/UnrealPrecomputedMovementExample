#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "PrecomputedMovementPluginBPLibrary.h"

#include "PrecomputedMovementManager.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRECOMPUTEDMOVEMENTPLUGIN_API UPrecomputedMovementManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FPrecomputedMovementDataCollection PrecomputedMovementDataCollection;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ActorClass;

    UPrecomputedMovementManager();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    void LoadPrecomputedMovementData();
};
