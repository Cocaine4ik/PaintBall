// // PaintBall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PBCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class PAINTBALL_API APBCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    APBCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* CameraComponent;
    
public:
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
};