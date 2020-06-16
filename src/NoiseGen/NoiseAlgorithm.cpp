#include "NoiseAlgorithm.h"

#include "CommonFunctions.h"
#include "INoiseCoordinate.h"

#include <QDebug>
#include <QJSEngine>

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
    static QJSEngine engine;
    if (mCompiledFunction.isNull())
        mCompiledFunction = engine.evaluate("(function(x,y) { return " + mAlgorithmString + " } )");

    if (mCompiledFunction.isError()) {
        qWarning() << "Warning:" << mCompiledFunction.errorType();
        return 0;
    } else {
        QJSValueList args;
        args << noiseCoordinate.getValue(0) << noiseCoordinate.getValue(1);

        QJSValue outputValue = mCompiledFunction.call(args);
        return normalize(outputValue.toNumber());
    }
}
