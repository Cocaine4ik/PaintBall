// // PaintBall. All Rights Reserved.


#include "Player/PBPlayer.h"

#include "AI/PBAICleaner.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Controller.h"
#include "Components/SphereComponent.h"
#include "Components/PBPaintComponent.h"

APBPlayer::APBPlayer(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SphereComponent->SetupAttachment(StaticMeshComponent);
    SphereComponent->SetSphereRadius(55.0f);
    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &APBPlayer::OnCollision);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;
    
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->TargetArmLength = 400.0f;
    SpringArmComponent->SocketOffset = FVector(0, 0, 30.0f);
    SpringArmComponent->SetupAttachment(StaticMeshComponent);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArmComponent,  USpringArmComponent::SocketName);
}

void APBPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    PlayerInputComponent->BindAxis("MoveForward", this, &APBPlayer::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APBPlayer::MoveRight);
    PlayerInputComponent->BindAxis("LookAround", this, &APBPlayer::LookAround);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void APBPlayer::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
    APBBasePawn::OnCollision(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, Hit);

    OtherPaintComponent->SetColor(PaintComponent->GetCurrentColor());
    OtherPaintComponent = nullptr;
}

void APBPlayer::MoveForward(float Value)
{
    if (CameraComponent && Value != 0.0f)
    {
        StaticMeshComponent->AddForce(CameraComponent->GetForwardVector() * Value * Speed * StaticMeshComponent->GetMass());
    }
}

void APBPlayer::MoveRight(float Value)
{
    if (CameraComponent && Value != 0.0f)
    {
        StaticMeshComponent->AddForce(CameraComponent->GetRightVector() * Value * Speed * StaticMeshComponent->GetMass());
    }
}

void APBPlayer::LookAround(float Value)
{
    if (Controller != nullptr && Value != 0.0f)
    {
        // find out which way is right
        const FRotator Rotation = Controller->GetControlRotation();
        AddControllerYawInput(Value);
    }
}