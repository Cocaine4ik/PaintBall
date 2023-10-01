// // PaintBall. All Rights Reserved.


#include "PBSpawnZone.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

APBSpawnZone::APBSpawnZone()
{
    SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
    RootComponent = SpawnArea;
}

void APBSpawnZone::BeginPlay()
{
    Super::BeginPlay();

}

bool APBSpawnZone::CalculateRandomSpawnLocation(FVector& SpawnLocation)
{
    if (!SpawnArea) return false;
    
        const FBoxSphereBounds BoxBounds = SpawnArea->CalcBounds(GetActorTransform());

        FVector Location = BoxBounds.Origin;

    Location.X += UKismetMathLibrary::RandomFloatInRange(-BoxBounds.BoxExtent.X, BoxBounds.BoxExtent.X);
    Location.Y += UKismetMathLibrary::RandomFloatInRange(-BoxBounds.BoxExtent.Y, BoxBounds.BoxExtent.Y);
    Location.Z += UKismetMathLibrary::RandomFloatInRange(-BoxBounds.BoxExtent.Z, BoxBounds.BoxExtent.Z);

    SpawnLocation = Location;

    return true;
}