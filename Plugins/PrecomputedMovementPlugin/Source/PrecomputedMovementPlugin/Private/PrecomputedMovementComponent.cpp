#include "PrecomputedMovementComponent.h"

#include "Kismet/GameplayStatics.h"

UPrecomputedMovementComponent::UPrecomputedMovementComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UPrecomputedMovementComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UPrecomputedMovementComponent::TickComponent(
    float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (bIsPlaying)
    {
        const float Time      = UGameplayStatics::GetRealTimeSeconds(this);
        int32       PathIndex = (int) (Time / PlayRate);
        if (bIsLooping && PathIndex > Path.Num())
        {
            PathIndex = PathIndex % Path.Num();
        }
        if (PathIndex < Path.Num() && PathIndex > 0)
        {
            const float   Alpha       = fmod(Time, PlayRate);
            const FVector NewPosition = FMath::Lerp(Path[PathIndex - 1], Path[PathIndex], Alpha);
            GetOwner()->SetActorLocation(NewPosition);
        }
    }
}
