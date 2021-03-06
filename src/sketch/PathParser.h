#ifndef JVGS_SKETCH_PATHPARSER_H
#define JVGS_SKETCH_PATHPARSER_H

#include "SketchElementParser.h"
#include <string>

namespace jvgs
{
    namespace sketch
    {
        class Path;

        class PathParser: public SketchElementParser
        {
            private:
            public:
                PathParser();
                virtual ~PathParser();

                virtual SketchElement *parse(SketchElement *parent,
                        TiXmlElement *element);
        };
    }
}

#endif
