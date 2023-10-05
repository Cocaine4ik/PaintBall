// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/PBBasePawn.h"
#include "PBPlayer.generated.h"

class USphereComponent;
class USpringArmComponent;
class UCameraComponent;
class USoundCue;

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

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    USoundCue* OnCollisionSound;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
    float SoundVolume = 0.3f;
    
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    virtual void OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void LookAround(float Value);
};