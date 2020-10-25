
#pragma once

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "FPSProjectile.generated.h"

UCLASS()
class HW2_API AFPSProjectile : public AActor
{
	GENERATED_BODY()

public:
	// ���ø� actor ���Ե�Ĭ��ֵ
	AFPSProjectile();

protected:
	// ��Ϸ��ʼʱ������ʱ����
	virtual void BeginPlay() override;

public:
	// ÿ֡����
	virtual void Tick(float DeltaSeconds) override;

	// �ڷ��䷽�������÷�������ٶȵĺ�����
	void FireInDirection(const FVector& ShootDirection);

	// ��������������ʱ���õĺ�����
UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// ������ײ�����
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	// �������˶������
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;
};