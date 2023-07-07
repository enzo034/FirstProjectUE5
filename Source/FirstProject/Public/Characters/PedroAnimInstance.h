#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PedroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API UPedroAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class APedroCharacter* PedroCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	class UCharacterMovementComponent* PedroCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
};
