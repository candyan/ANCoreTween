//
//  ANTweenTimingFunctions.h
//  ANCoreTween
//
//  Created by liuyan on 15-3-13.
//  Copyright (c) 2015年 Canydan. All rights reserved.
//

#ifndef __ANTweenTimingFunctions__
#define __ANTweenTimingFunctions__

#include <stdio.h>

/* Full Tween Timing Funcation */

float ANTweenTimingFunctionLinear(float time, float begin, float change, float duration);

float ANTweenTimingFunctionBackIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionBackOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionBackInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionBounceIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionBounceOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionBounceInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionCircIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionCircOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionCircInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionCubicIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionCubicOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionCubicInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionElasticIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionElasticOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionElasticInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionExpoIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionExpoOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionExpoInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionQuadIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuadOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuadInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionQuartIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuartOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuartInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionQuintIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuintOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionQuintInOut(float time, float begin, float change, float duration);

float ANTweenTimingFunctionSineIn(float time, float begin, float change, float duration);
float ANTweenTimingFunctionSineOut(float time, float begin, float change, float duration);
float ANTweenTimingFunctionSineInOut(float time, float begin, float change, float duration);

/* Tween Progress Timing Function, make begin 0, change 1. So these method return a progress between 0..1 */

float ANTweenProgressTimingFunctionLinear(float time, float duration);

float ANTweenProgressTimingFunctionBackIn(float time, float duration);
float ANTweenProgressTimingFunctionBackOut(float time, float duration);
float ANTweenProgressTimingFunctionBackInOut(float time, float duration);

float ANTweenProgressTimingFunctionBounceIn(float time, float duration);
float ANTweenProgressTimingFunctionBounceOut(float time, float duration);
float ANTweenProgressTimingFunctionBounceInOut(float time, float duration);

float ANTweenProgressTimingFunctionCircIn(float time, float duration);
float ANTweenProgressTimingFunctionCircOut(float time, float duration);
float ANTweenProgressTimingFunctionCircInOut(float time, float duration);

float ANTweenProgressTimingFunctionCubicIn(float time, float duration);
float ANTweenProgressTimingFunctionCubicOut(float time, float duration);
float ANTweenProgressTimingFunctionCubicInOut(float time, float duration);

float ANTweenProgressTimingFunctionElasticIn(float time, float duration);
float ANTweenProgressTimingFunctionElasticOut(float time, float duration);
float ANTweenProgressTimingFunctionElasticInOut(float time, float duration);

float ANTweenProgressTimingFunctionExpoIn(float time, float duration);
float ANTweenProgressTimingFunctionExpoOut(float time, float duration);
float ANTweenProgressTimingFunctionExpoInOut(float time, float duration);

float ANTweenProgressTimingFunctionQuadIn(float time, float duration);
float ANTweenProgressTimingFunctionQuadOut(float time, float duration);
float ANTweenProgressTimingFunctionQuadInOut(float time, float duration);

float ANTweenProgressTimingFunctionQuartIn(float time, float duration);
float ANTweenProgressTimingFunctionQuartOut(float time, float duration);
float ANTweenProgressTimingFunctionQuartInOut(float time, float duration);

float ANTweenProgressTimingFunctionQuintIn(float time, float duration);
float ANTweenProgressTimingFunctionQuintOut(float time, float duration);
float ANTweenProgressTimingFunctionQuintInOut(float time, float duration);

float ANTweenProgressTimingFunctionSineIn(float time, float duration);
float ANTweenProgressTimingFunctionSineOut(float time, float duration);
float ANTweenProgressTimingFunctionSineInOut(float time, float duration);

#endif /* defined(__ANTweenTimingFunctions__) */
