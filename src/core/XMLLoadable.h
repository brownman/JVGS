#ifndef JVGS_CORE_XMLLOADABLE_H
#define JVGS_CORE_XMLLOADABLE_H

#include <string>
class TiXmlElement;

namespace jvgs
{
    namespace core
    {
        /** Generic interface for objects loadable through XML.
         */
        class XMLLoadable
        {
            public:
                /** Constructor.
                 */
                XMLLoadable();

                /** Destructor.
                 */
                virtual ~XMLLoadable();

            protected:
                /** Load data from an XML element. Call this function.
                 *  @param element XML element to load data from.
                 */
                void load(TiXmlElement *element);

                /** Load data from an XML file.
                 *  @param fileName XML file to load data from.
                 */
                void load(const std::string &fileName);

                /** Load the data. Implement this function.
                 *  @param element XML element to load data from.
                 */
                virtual void loadData(TiXmlElement *element) = 0;
        };
    }
}

#endif