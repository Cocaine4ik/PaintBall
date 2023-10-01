// // PaintBall. All Rights Reserved.


#include "AI/PBAIPawn.h"
#include "AI/PBAICleaner.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"
#include "Components/PBPaintComponent.h"

APBAIPawn::APBAIPawn(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    BoxComponent->SetupAttachment(StaticMeshComponent);
    BoxComponent->SetBoxExtent(FVector(50.0f, 50.0f, 50.0f));
    BoxComponent->SetGenerateOverlapEvents(true);
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

void APBAIPawn::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    APBBasePawn::OnCollision(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, Hit);
    
    if (PaintComponent->IsPainted() && !OtherPaintComponent->GetOwner()->IsA(APBAICleaner::StaticClass()))
    {
        OtherPaintComponent->SetColor(PaintComponent->GetCurrentColor());
    }
}

void APBAIPawn::BeginPlay()
{
    Super::BeginPlay();
    
    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APBAIPawn::OnCollision);
    
    MoveRandomDirection();
}