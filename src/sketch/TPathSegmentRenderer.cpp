#include "TPathSegmentRenderer.h"
#include "PathRenderer.h"
#include "PathSegment.h"
#include "QPathSegmentRenderer.h"

#include <iostream>
#include <vector>
using namespace std;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../video/Renderer.h"
using namespace jvgs::video;

namespace jvgs
{
    namespace sketch
    {
        TPathSegmentRenderer::TPathSegmentRenderer(PathRenderer *pathRenderer):
                PathSegmentRenderer(pathRenderer)
        {
        }

        TPathSegmentRenderer::~TPathSegmentRenderer()
        {
        }

        void TPathSegmentRenderer::vectors(video::Renderer *renderer,
                PathSegment *segment, bool fill)
        {
            PathRenderer *pathRenderer = getPathRenderer();
            Vector2D control = pathRenderer->getLastControlPoint();
            control = pathRenderer->getCurrentPoint().reflect(control);

            if(segment->isRelativeCommand())
                control -= pathRenderer->getCurrentPoint();

            char command = segment->isRelativeCommand() ? 'q' : 'Q';
            vector<float> arguments;

            for(int i = 0; i + 1 < segment->getNumberOfArguments(); i += 2) {
                arguments.push_back(control.getX());
                arguments.push_back(control.getY());
                arguments.push_back(segment->getArgument(i));
                arguments.push_back(segment->getArgument(i + 1));
            }

            PathSegment *qPathSegment = new PathSegment(command, arguments);
            PathSegmentRenderer *qPathRenderer =
                    new QPathSegmentRenderer(pathRenderer);
            qPathRenderer->vectors(renderer, qPathSegment, fill);
            delete qPathSegment;
            delete qPathRenderer;
        }
    }
}