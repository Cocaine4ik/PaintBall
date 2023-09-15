// // PaintBall. All Rights Reserved.


#include "AI/PBAIPawn.h"
#include "Kismet/KismetMathLibrary.h"

APBAIPawn::APBAIPawn(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
}

void APBAIPawn::MoveRandomDirection()
{
    if (!GetWorld()) return;
    
    const auto RandomVector = UKismetMathLibrary::RandomUnitVector();
    const auto RandomSpeed = GetRandomValueWithStep(0.0f, Speed, 50.0f);
    StaticMeshComponent->AddImpulse(FVector(RandomVector.X, RandomVector.Y, 0.0f) * RandomSpeed * StaticMeshComponent->GetMass());

    GetWorld()->GetTimerManager().SetTimer(RandomMoveTimerHandle, this, &APBAIPawn::MoveRandomDirection, MovementDelay, false);
}

float APBAIPawn::GetRandomValueWithStep(float Min, float Max, float Step)
{
    const auto Range = (Max - Min) / Step + 1;
    const auto RandomIndex = FMath::FRandRange(0, Range - 1);
    const auto RandomValue = Min + RandomIndex * Step;
    
    return RandomValue;
}

void APBAIPawn::BeginPlay()
{
    Super::BeginPlay();

    MoveRandomDirection();
}