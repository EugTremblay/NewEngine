#include "Collision.h"
#include <math.h>
#include <Entity.h>



//mon cerveau ne marchait plus, merci bcp de l'aide tho mais sa amenais des erreurs dans mon code et je ne peut pas me le permettre. thanks encore pour le support tho:)





//bool Collision::CheckRects(float r1x, float r1y, float r1w, float r1h, float r2x,
//    float r2y, float r2w, float r2h)
//{
//    return (r1x <= (r2x + r2w) && (r1x + r1w) >= r2x &&
//        r1y <= (r2y + r2h) && (r1y + r1h) >= r2y);
//}
//
//
//
//void Collision::AddCollider( Component* comp)
//{
//    m_Collideables.push_back(comp);
//}
//
//void Collision::CheckCollision(Component* col1)
//{
//    Entity* entity = col1->GetParent();
//
//    if (m_Collideables.size() > 0)
//    {
//        float r1x, r1y, r1w, r1h;
//        float r2x, r2y, r2w, r2h;
//
//        r1x = entity->GetX();
//        r1y = entity->GetY();
//
//        r1w = entity->GetW();
//        r1h = entity->GetH();
//
//        for (Entity* e : m_Collideables)
//        {
//            r2x = e->GetX();
//            r2y = e->GetY();
//           
//            r2w = e->GetW();
//            r2h = e->GetH();
//
//            if (CheckRects(r1x, r1y, r1w, r1h, r2x, r2y, r2w, r2h))
//            {
//                reinterpret_cast<ICollideable*>(col1)->OnCollisionEnter(e);
//                return;
//            }
//        }
//    }
//}
//
//void Collision::Remove(Entity* entity)
//{
//
//    m_Collideables.erase(
//        std::remove(m_Collideables.begin(), m_Collideables.end(), entity),
//        m_Collideables.end());
//}
//
//void Collision::Update(float dt)
//{
//    for ( int i =0 ;  i < m_Collideables.size() ; i++)
//    {
//        CheckCollision(m_Collideables[i]);
//    }
//}
