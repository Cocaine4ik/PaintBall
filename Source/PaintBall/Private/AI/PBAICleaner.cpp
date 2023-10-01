// // PaintBall. All Rights Reserved.


#include "AI/PBAICleaner.h"
#include "PBPaintComponent.h"

APBAICleaner::APBAICleaner(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
}

void APBAICleaner::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    APBAIPawn::OnCollision(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, Hit);
    
    if (!PaintComponent->IsPainted() && OtherPaintComponent->IsPainted())
    {
        OtherPaintComponent->SetDefaultColor();
    }
    OtherPaintComponent = nullptr;
}
