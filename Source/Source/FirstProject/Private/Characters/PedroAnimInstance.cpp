// Fill out your copyright notice in the Description page of Project Settings.
// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PedroAnimInstance.h"
#include "Characters/PedroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UPedroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	PedroCharacter = Cast<APedroCharacter>(TryGetPawnOwner());
	if (PedroCharacter)
	{
		PedroCharacterMovement = PedroCharacter->GetCharacterMovement();
	}
}

void UPedroAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (PedroCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(PedroCharacterMovement->Velocity);
		IsFalling = PedroCharacterMovement->IsFalling();
	}
}
