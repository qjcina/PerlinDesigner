#include "NoiseEngine.h"

#include "MathPD.h"

NoiseEngine::NoiseEngine()
{
    globalObject().setProperty("MathPD", newQObject(new MathPD()));
}
