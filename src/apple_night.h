#ifndef MEDIEVAL_TOWN_DEMO_APPLE_NIGHT_H
#define MEDIEVAL_TOWN_DEMO_APPLE_NIGHT_H


#include <ppgso/ppgso.h>

#include "scene.h"
#include "cauldron_night.h"

/*!
 * Simple asteroid object
 * This sphere object represents an instance of mesh geometry
 * It initializes and loads all resources only once
 * It will move down along the Y axis and self delete when reaching below -10
 */
class AppleNight : public Object {
private:
    // Static resources (Shared between instances)
    // every object needs mesh, shader to render and texture
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Texture> texture;
    std::unique_ptr<CauldronNight> cauldron;

public:
    /*!
     * Create new Apple
     */
    AppleNight();

    /*!
     * Update tower
     * @param scene Scene to interact with
     * @param dt Time delta for animation purposes
     * @return
     */
    bool update(Scene &scene, float dt) override;

    /*!
     * Render tower
     * @param scene Scene to render in
     */
    void render(Scene &scene) override;


    /*!
     * Rotational momentum
     */
    glm::vec3 rotMomentum;
};
#endif //MEDIEVAL_TOWN_DEMO_APPLE_NIGHT_H
