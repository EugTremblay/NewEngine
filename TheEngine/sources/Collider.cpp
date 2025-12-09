#include "Collider.h"

void Collider::OnCollisionEnter(Entity* other)
{
	delete other;
}
