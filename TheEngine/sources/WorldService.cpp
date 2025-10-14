#pragma once
#include "WorldService.h"

void WorldService::Remove(Entity* ent){
    for(auto it = m_EntityInWorld.begin(); it != m_EntityInWorld.end(); it ++){
        if(ent->GetName() == (*it)->GetName()){
            m_EntityInWorld.erase(it--);
        }
        
    }
}