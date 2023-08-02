//
// Created by wind on 2023/7/28.
//

#include "beautify_face_cool_effect.h"
#include "hue_effect.h"


BeautifyFaceCoolEffect::BeautifyFaceCoolEffect(){

   this->addEffect(new SmoothSkinHorizontalEffect());
   this->addEffect(new SmoothSkinVerticalEffect());
   this->addEffect(new HueEffect());
}

BeautifyFaceCoolEffect::~BeautifyFaceCoolEffect(){

}