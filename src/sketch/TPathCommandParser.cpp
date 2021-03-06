#include "TPathCommandParser.h"
#include "QPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/QuadraticCurve.h"
#include "../math/Vector2D.h"
using namespace jvgs::math;
using namespace std;

namespace jvgs
{
    namespace sketch
    {
        TPathCommandParser::TPathCommandParser()
        {
        }

        TPathCommandParser::~TPathCommandParser()
        {
        }

        void TPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            QPathCommandParser *qCommandParser = new QPathCommandParser();

            for(vector<float>::size_type i = 0; i < arguments.size(); i += 2) {

                Vector2D control = dataParser->getCurrentPoint().reflect(
                        dataParser->getLastControlPoint());

                if(dataParser->isRelativeCommand(command))
                    control -= dataParser->getCurrentPoint();

                vector<float> qArguments;

                qArguments.push_back(control.getX());
                qArguments.push_back(control.getY());
                for(int j = 0; j < 2; j++)
                    qArguments.push_back(arguments[i + j]);

                char qCommand = dataParser->isRelativeCommand(command) ?
                        'q' : 'Q';

                qCommandParser->parse(path, qCommand, dataParser, qArguments);
            }

            delete qCommandParser;
        }
    }
}
