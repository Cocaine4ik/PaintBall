// // PaintBall. All Rights Reserved.


#include "Player/PBCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
APBCharacter::APBCharacter()
{
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
    SpringArmComponent->SetupAttachment(RootComponent);
}

// Called to bind functionality to input
void APBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    PlayerInputComponent->BindAxis("MoveForward", this, &APBCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APBCharacter::MoveRight);
}

void APBCharacter::MoveForward(float Value)
{
}

void APBCharacter::MoveRight(float Value)
{
}