// Copyright (c) 2026 zlatirl. All Rights Reserved.

#include "PetShopCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"

APetShopCharacter::APetShopCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(0.f, 0.f, 64.f));
	FirstPersonCamera->bUsePawnControlRotation = true;

	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void APetShopCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (const APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Input =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Input->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}
}

void APetShopCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APetShopCharacter::Move);
		}
		if (LookAction)
		{
			Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &APetShopCharacter::Look);
		}
		if (JumpAction)
		{
			Input->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			Input->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		}
		if (SprintAction)
		{
			Input->BindAction(SprintAction, ETriggerEvent::Started, this, &APetShopCharacter::StartSprint);
			Input->BindAction(SprintAction, ETriggerEvent::Completed, this, &APetShopCharacter::StopSprint);
		}
	}
}

void APetShopCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	if (!Controller)
	{
		return;
	}

	AddMovementInput(GetActorForwardVector(), Axis.Y);
	AddMovementInput(GetActorRightVector(), Axis.X);
}

void APetShopCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(-Axis.Y);
}

void APetShopCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void APetShopCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}
