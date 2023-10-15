// // PaintBall. All Rights Reserved.


#include "Player/PBPlayer.h"

#include "AI/PBAICleaner.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Controller.h"
#include "Components/SphereComponent.h"
#include "Components/PBPaintComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

APBPlayer::APBPlayer(const FObjectInitializer& ObjInit)
    : Super(ObjInit)
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
    CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

    ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
    ArrowComponent->SetupAttachment(CameraComponent);
    ArrowComponent->SetHiddenInGame(false);
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

    if (GetWorld() && OnCollisionSound)
    {
        UGameplayStatics::SpawnSoundAtLocation(GetWorld(), OnCollisionSound, GetActorLocation(), GetActorRotation(), SoundVolume);
    }

    OtherPaintComponent = OtherActor->GetComponentByClass<UPBPaintComponent>();
}

void APBPlayer::MoveForward(float Value)
{
    if (CameraComponent)
    {
        StaticMeshComponent->AddForce(CameraComponent->GetForwardVector() * Value * Speed, TEXT("None"), true);

        ArrowComponent->SetWorldRotation(
            FRotationMatrix::MakeFromX(
                StaticMeshComponent->GetPhysicsLinearVelocity().GetSafeNormal().RotateAngleAxis(90.0f, FVector::UpVector)).Rotator());
        
        ArrowComponent->SetArrowLength(FMath::Clamp(MinArrowSize,FMath::Abs(StaticMeshComponent->GetPhysicsLinearVelocity().X * ArrowSizeMod), MaxArrowSize));

    }
}

void APBPlayer::MoveRight(float Value)
{
    if (CameraComponent)
    {
        StaticMeshComponent->AddForce(CameraComponent->GetRightVector() * Value * Speed, TEXT("None"), true);

        ArrowComponent->SetWorldRotation(
            FRotationMatrix::MakeFromX(StaticMeshComponent->GetPhysicsLinearVelocity().GetSafeNormal()).Rotator());

        ArrowComponent->SetArrowLength(FMath::Clamp(MinArrowSize,FMath::Abs(StaticMeshComponent->GetPhysicsLinearVelocity().X * ArrowSizeMod), MaxArrowSize));

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