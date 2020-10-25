
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
	// 设置该 actor 属性的默认值
	AFPSProjectile();

protected:
	// 游戏开始时或生成时调用
	virtual void BeginPlay() override;

public:
	// 每帧调用
	virtual void Tick(float DeltaSeconds) override;

	// 在发射方向上设置发射物初速度的函数。
	void FireInDirection(const FVector& ShootDirection);

	// 发射物命中物体时调用的函数。
UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// 球体碰撞组件。
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	// 发射物运动组件。
	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovementComponent;
};