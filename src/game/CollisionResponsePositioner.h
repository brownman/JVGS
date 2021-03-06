#ifndef JVGS_GAME_COLLISIONRESPONSEPOSITIONER_H
#define JVGS_GAME_COLLISIONRESPONSEPOSITIONER_H

#include "../sketch/Sketch.h"
#include "../sketch/Group.h"
#include "../sketch/Path.h"
#include "../math/LineSegment.h"
#include "../math/BoundedObject.h"
#include "../math/Vector2D.h"
#include "../math/MathManager.h"
#include "../math/CollisionDetector.h"
#include "Positioner.h"
#include <vector>

class TiXmlElement;

namespace jvgs
{
    namespace game
    {
        class Entity;

        class CollisionResponsePositioner: public Positioner
        {
            private:
#               ifndef SWIG
                    const static float VERY_CLOSE;
                    const static int MAX_STEPS;
                    const static float SLIP_LIMIT;
#               else
                    static float VERY_CLOSE;
                    static int MAX_STEPS;
                    static float SLIP_LIMIT;
#               endif

                /** MathManager to perform calculations. */
                math::MathManager *mathManager;

                /** Max distance from collision if you want to jump. */
                float jumpDistanceLimit;

            protected:
                /* Override
                 */
                void loadData(TiXmlElement *element);

            public:
                /** Constructor.
                 *  @param entity Entity to respond to collisions.
                 */
                CollisionResponsePositioner(Entity *entity);

                /** Constructor.
                 *  @param entity Entity to respond to collisions.
                 *  @param element TiXmlElement containing the data.
                 */
                CollisionResponsePositioner(Entity *entity,
                        TiXmlElement *element);

                /** Destructor.
                 */
                virtual ~CollisionResponsePositioner();

                /* Override
                 */
                virtual void affect(float ms);

                /* Override
                 */
                virtual bool canJump();
        };
    }
}

#endif
