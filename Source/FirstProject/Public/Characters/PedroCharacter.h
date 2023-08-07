// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PedroCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class AItem;

UCLASS()
class FIRSTPROJECT_API APedroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APedroCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Jump() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* CharacterContext;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* CharacterMoveAction;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* CharacterLookAction;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* CharacterJumpAction;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* CharacterEKeyPressedAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void EKeyPressed(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleInstanceOnly);
	AItem* OverlappingItem;
public:
	inline void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
};
