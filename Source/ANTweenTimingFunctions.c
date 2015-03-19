//
//  ANTweenTimingFunctions.c
//  ANCoreTween
//
//  Created by liuyan on 15-3-13.
//  Copyright (c) 2015年 Canydan. All rights reserved.
//

#include "ANTweenTimingFunctions.h"
#include <math.h>

/* Full Tween Timing Funcation */

float ANTweenTimingFunctionLinear(float time, float begin, float change, float duration)
{
    return change * time / duration + begin;
}

float ANTweenTimingFunctionBackIn(float time, float begin, float change, float duration)
{
    float s = 1.70158;
    time /= duration;
    return change * time * time * ((s + 1) * time - s) + begin;
}

float ANTweenTimingFunctionBackOut(float time, float begin, float change, float duration)
{
    float s = 1.70158;
    time = time / duration - 1;
    return change * (time * time * ((s + 1) * time + s) + 1) + begin;
}

float ANTweenTimingFunctionBackInOut(float time, float begin, float change, float duration)
{
    float s = 1.70158 * 1.525;

    time /= duration / 2;

    if (time < 1) {
        return change / 2 * (time * time * ((s + 1) * time - s)) + begin;
    } else {
        time -= 2;
        return change / 2 * (time * time * ((s + 1) * time + s) + 2) + begin;
    }
}

float ANTweenTimingFunctionBounceIn(float time, float begin, float change, float duration)
{
    return change - ANTweenTimingFunctionBounceOut(duration - time, 0, change, duration) + begin;
}

float ANTweenTimingFunctionBounceOut(float time, float begin, float change, float duration)
{
    time /= duration;
    if (time < (1 / 2.75)) {
        return change * (7.5625 * time * time) + begin;
    } else if (time < (2 / 2.75)) {
        time -= (1.5 / 2.75);
        return change * (7.5625 * time * time + .75) + begin;
    } else if (time < (2.5 / 2.75)) {
        time -= (2.25 / 2.75);
        return change * (7.5625 * time * time + .9375) + begin;
    } else {
        time -= (2.625 / 2.75);
        return change * (7.5625 * time * time + .984375) + begin;
    }
}

float ANTweenTimingFunctionBounceInOut(float time, float begin, float change, float duration)
{
    if (time < duration / 2) {
        return ANTweenTimingFunctionBounceIn(time * 2, 0, change, duration) * .5 + begin;
    } else {
        return ANTweenTimingFunctionBounceOut(time * 2 - duration, 0, change, duration) * .5 + change * .5 + begin;
    }
}

float ANTweenTimingFunctionCircIn(float time, float begin, float change, float duration)
{
    time /= duration;
    return -change * (sqrt(1 - time * time) - 1) + begin;
}

float ANTweenTimingFunctionCircOut(float time, float begin, float change, float duration)
{
    time = time / duration - 1;
    return change * sqrt(1 - time * time) + begin;
}

float ANTweenTimingFunctionCircInOut(float time, float begin, float change, float duration)
{
    time /= duration / 2;
    if (time < 1) {
        return -change / 2 * (sqrt(1 - time * time) - 1) + begin;
    } else {
        time -= 2;
        return change / 2 * (sqrt(1 - time * time) + 1) + begin;
    }
}

float ANTweenTimingFunctionCubicIn(float time, float begin, float change, float duration)
{
    time /= duration;
    return change * time * time * time + begin;
}

float ANTweenTimingFunctionCubicOut(float time, float begin, float change, float duration)
{
    time = time / duration - 1;
    return change * (time * time * time + 1) + begin;
}

float ANTweenTimingFunctionCubicInOut(float time, float begin, float change, float duration)
{
    time /= duration / 2;
    if (time < 1) {
        return change / 2 * time * time * time + begin;
    } else {
        time -= 2;
        return change / 2 * (time * time * time + 2) + begin;
    }
}

float ANTweenTimingFunctionElasticIn(float time, float begin, float change, float duration)
{
    float p = duration * .3;
    float s, a;

    if (time == 0) {
        return begin;
    }

    time /= duration;
    if (time == 1) {
        return begin + change;
    }

    if (!a || a < fabsf(change)) {
        a = change;
        s = p / 4;
    } else {
        s = p / (2 * M_PI) * asin(change / a);
    }

    time -= 1;
    return -(a * pow(2, 10 * time) * sin((time * duration - s) * (2 * M_PI) / p)) + begin;
}

float ANTweenTimingFunctionElasticOut(float time, float begin, float change, float duration)
{
    float p = duration * .3;
    float s, a;
    if (time == 0) {
        return begin;
    }

    time /= duration;
    if (time == 1) {
        return begin + change;
    }

    if (!a || a < fabsf(change)) {
        a = change;
        s = p / 4;
    } else {
        s = p / (2 * M_PI) * asinf(change / a);
    }

    return (a * pow(2, -10 * time) * sin((time * duration - s) * (2 * M_PI) / p) + change + begin);
}

float ANTweenTimingFunctionElasticInOut(float time, float begin, float change, float duration)
{
    float p = duration * (.3 * 1.5);
    float s, a;

    if (time == 0) {
        return begin;
    }

    time /= duration / 2;

    if (time == 2) {
        return begin + change;
    }

    if (!a || a < fabsf(change)) {
        a = change;
        s = p / 4;
    } else {
        s = p / (2 * M_PI) * asin(change / a);
    }

    if (time < 1) {
        time -= 1;
        return -.5 * (a * pow(2, 10 * time) * sin((time * duration - s) * (2 * M_PI) / p)) + begin;
    } else {
        time -= 1;
        return a * pow(2, -10 * time) * sin((time * duration - s) * (2 * M_PI) / p) * .5 + change + begin;
    }
}

float ANTweenTimingFunctionExpoIn(float time, float begin, float change, float duration)
{
    return (time == 0) ? begin : change * pow(2, 10 * (time / duration - 1)) + begin;
}

float ANTweenTimingFunctionExpoOut(float time, float begin, float change, float duration)
{
    return (time == duration) ? begin + change : change * (-pow(2, -10 * time / duration) + 1) + begin;
}

float ANTweenTimingFunctionExpoInOut(float time, float begin, float change, float duration)
{
    if (time == 0) {
        return begin;
    }

    if (time == duration) {
        return begin + change;
    }

    time /= duration / 2;
    if (time < 1) {
        return change / 2 * pow(2, 10 * (time - 1)) + begin;
    }

    return change / 2 * (-pow(2, -10 * --time) + 2) + begin;
}

float ANTweenTimingFunctionQuadIn(float time, float begin, float change, float duration)
{
    time /= duration;
    return change * time * time + begin;
}

float ANTweenTimingFunctionQuadOut(float time, float begin, float change, float duration)
{
    time /= duration;
    return -change * time * (time - 2) + begin;
}

float ANTweenTimingFunctionQuadInOut(float time, float begin, float change, float duration)
{
    time /= duration / 2;
    if (time < 1) {
        return change / 2 * time * time + begin;
    }
    time--;
    return -change / 2 * (time * (time - 2) - 1) + begin;
}

float ANTweenTimingFunctionQuartIn(float time, float begin, float change, float duration)
{
    time /= duration;
    return change * time * time * time * time + begin;
}

float ANTweenTimingFunctionQuartOut(float time, float begin, float change, float duration)
{
    time = time / duration - 1;
    return -change * (time * time * time * time - 1) + begin;
}

float ANTweenTimingFunctionQuartInOut(float time, float begin, float change, float duration)
{
    time /= duration / 2;
    if (time < 1) {
        return change / 2 * time * time * time * time + begin;
    }
    time -= 2;
    return -change / 2 * (time * time * time * time - 2) + begin;
}

float ANTweenTimingFunctionQuintIn(float time, float begin, float change, float duration)
{
    time = time / duration - 1;
    return change * (time * time * time * time * time + 1) + begin;
}

float ANTweenTimingFunctionQuintOut(float time, float begin, float change, float duration)
{
    time /= duration;
    return change * time * time * time * time * time + begin;
}

float ANTweenTimingFunctionQuintInOut(float time, float begin, float change, float duration)
{
    time /= duration / 2;
    if (time < 1) {
        return change / 2 * time * time * time * time * time + begin;
    }

    time -= 2;
    return change / 2 * (time * time * time * time * time + 2) + begin;
}

float ANTweenTimingFunctionSineIn(float time, float begin, float change, float duration)
{
    return -change * cos(time / duration * (M_PI / 2)) + change + begin;
}

float ANTweenTimingFunctionSineOut(float time, float begin, float change, float duration)
{
    return change * sin(time / duration * (M_PI / 2)) + begin;
}

float ANTweenTimingFunctionSineInOut(float time, float begin, float change, float duration)
{
    return -change / 2 * (cos(M_PI * time / duration) - 1) + begin;
}

/* Progress Tween Timing Function, make begin 0, change 1, duration 1. So these method return a progress between 0..1 */

float ANTweenProgressTimingFunctionLinear(float time, float duration)
{
    return ANTweenTimingFunctionLinear(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBackIn(float time, float duration)
{
    return ANTweenTimingFunctionBackIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBackOut(float time, float duration)
{
    return ANTweenTimingFunctionBackOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBackInOut(float time, float duration)
{
    return ANTweenTimingFunctionBackInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBounceIn(float time, float duration)
{
    return ANTweenTimingFunctionBounceIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBounceOut(float time, float duration)
{
    return ANTweenTimingFunctionBounceOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionBounceInOut(float time, float duration)
{
    return ANTweenTimingFunctionBounceInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCircIn(float time, float duration)
{
    return ANTweenTimingFunctionCircIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCircOut(float time, float duration)
{
    return ANTweenTimingFunctionCircOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCircInOut(float time, float duration)
{
    return ANTweenTimingFunctionCircInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCubicIn(float time, float duration)
{
    return ANTweenTimingFunctionCubicIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCubicOut(float time, float duration)
{
    return ANTweenTimingFunctionCubicOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionCubicInOut(float time, float duration)
{
    return ANTweenTimingFunctionCubicInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionElasticIn(float time, float duration)
{
    return ANTweenTimingFunctionElasticIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionElasticOut(float time, float duration)
{
    return ANTweenTimingFunctionElasticOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionElasticInOut(float time, float duration)
{
    return ANTweenTimingFunctionElasticInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionExpoIn(float time, float duration)
{
    return ANTweenTimingFunctionExpoIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionExpoOut(float time, float duration)
{
    return ANTweenTimingFunctionExpoOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionExpoInOut(float time, float duration)
{
    return ANTweenTimingFunctionExpoInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuadIn(float time, float duration)
{
    return ANTweenTimingFunctionQuadIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuadOut(float time, float duration)
{
    return ANTweenTimingFunctionQuadOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuadInOut(float time, float duration)
{
    return ANTweenTimingFunctionQuadInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuartIn(float time, float duration)
{
    return ANTweenTimingFunctionQuartIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuartOut(float time, float duration)
{
    return ANTweenTimingFunctionQuartOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuartInOut(float time, float duration)
{
    return ANTweenTimingFunctionQuartInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuintIn(float time, float duration)
{
    return ANTweenTimingFunctionQuintIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuintOut(float time, float duration)
{
    return ANTweenTimingFunctionQuintOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionQuintInOut(float time, float duration)
{
    return ANTweenTimingFunctionQuintInOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionSineIn(float time, float duration)
{
    return ANTweenTimingFunctionSineIn(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionSineOut(float time, float duration)
{
    return ANTweenTimingFunctionSineOut(time, 0, 1, duration);
}

float ANTweenProgressTimingFunctionSineInOut(float time, float duration)
{
    return ANTweenTimingFunctionSineInOut(time, 0, 1, duration);
}
