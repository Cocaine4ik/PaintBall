// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/PBBasePawn.h"
#include "PBPlayer.generated.h"

class USphereComponent;
class USpringArmComponent;
class UCameraComponent;
class USoundCue;
class UArrowComponent;

UCLASS()
class PAINTBALL_API APBPlayer : public APBBasePawn
{
    GENERATED_BODY()
    
public:
    APBPlayer(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USphereComponent* SphereComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UArrowComponent* ArrowComponent;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* OnCollisionSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    float SoundVolume = 0.3f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow")
    float MinArrowSize = 30.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow")
    float MaxArrowSize = 50.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arrow", meta = (ClampMin = "0.2", ClampMax = "0.8"))
    float ArrowSizeMod = 0.5f;
    
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    virtual void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit) override;
    
private:
    
    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookAround(float Value);
};