// Copyright (c) 2026 zlatirl. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PetShopCharacter.generated.h"

class  UCameraComponent;
class  UInputMappingContext;
class  UInputAction;
struct FInputActionValue;

UCLASS()
class PETSHOPSIM_API APetShopCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APetShopCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	/** Input map context, assigned in the Blueprint subclass. */
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float WalkSpeed = 400.f;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float SprintSpeed = 750.f;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartSprint();
	void StopSprint();
};
