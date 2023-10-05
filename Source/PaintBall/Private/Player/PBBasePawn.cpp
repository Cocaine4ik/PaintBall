// // PaintBall. All Rights Reserved.


#include "Player/PBBasePawn.h"
#include "Components/PBPaintComponent.h"

// Sets default values
APBBasePawn::APBBasePawn(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMeshComponent->SetSimulatePhysics(true);
    StaticMeshComponent->SetupAttachment(RootComponent);
    PaintComponent = CreateDefaultSubobject<UPBPaintComponent>(TEXT("PaintComponent"));
}

void APBBasePawn::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    
    OtherPaintComponent = OtherActor->GetComponentByClass<UPBPaintComponent>();

    if (!OtherPaintComponent) return;
}

