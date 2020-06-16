#include "NoiseAlgorithm.h"

#include "CommonFunctions.h"
#include "INoiseCoordinate.h"

#include "NoiseEngine.h"

#include <QDebug>

NoiseAlgorithm::operator QString() const
{
    return mAlgorithmString;
}

NoiseAlgorithm::NoiseAlgorithm(const QString& algorithmString)
    : mAlgorithmString(algorithmString)
{
}

float NoiseAlgorithm::getValue(const INoiseCoordinate& noiseCoordinate) const
{
    static NoiseEngine engine;
    if (mCompiledFunction.isNull())
        mCompiledFunction = engine.evaluate("(function(x,y) { return " + mAlgorithmString + " } )");

    if (mCompiledFunction.isError()) {
        qWarning() << "Warning:" << mCompiledFunction.errorType();
        return 0;
    } else {
        QJSValueList args;
        args << noiseCoordinate.getValue(0) << noiseCoordinate.getValue(1);

        QJSValue outputValue = mCompiledFunction.call(args);
        return outputValue.toNumber();
    }
}
