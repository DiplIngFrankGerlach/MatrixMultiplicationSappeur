#include <stdafx.h>
#include "header_ZKNuetzlich.ai.h"
void* ZKNuetzlich::operator new(size_t objectSize,void* place){
   ZKNuetzlich* obj=(ZKNuetzlich*)place;   return obj; 
} 
void ZKNuetzlich::destroy_sappeur_internal(){delete this;}

