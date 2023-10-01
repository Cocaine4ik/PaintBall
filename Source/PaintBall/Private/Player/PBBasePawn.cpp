// // PaintBall. All Rights Reserved.


#include "Player/PBBasePawn.h"
#include "Components/PBPaintComponent.h"
#include "AI/PBAICleaner.h"
#include "PBGameMode.h"

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
    /*
    if(GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("Collison From %s to %s"),
            *GetName(), *OtherActor->GetName()));
    */
    OtherPaintComponent = OtherActor->GetComponentByClass<UPBPaintComponent>();

    if (!OtherPaintComponent) return;
}

