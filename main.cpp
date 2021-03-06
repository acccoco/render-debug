#include <iostream>

#include "config.h"

#include "render/material.h"
#include "render/ray.h"
#include "render/scene.h"
#include "render/rt_render.h"
#include "render/triangle.h"
#include "render/ray_path_serialize.h"


int main()
{
    // 导入模型
    auto floor = MeshTriangle::mesh_load(PATH_CORNELL_FLOOR)[0];
    floor->mat()->set_diffuse(color_cornel_white);
    auto left = MeshTriangle::mesh_load(PATH_CORNELL_LEFT)[0];
    left->mat()->set_diffuse(color_cornel_red);
    auto right = MeshTriangle::mesh_load(PATH_CORNELL_RIGHT)[0];
    right->mat()->set_diffuse(color_cornel_green);
    auto tall_box = MeshTriangle::mesh_load(PATH_CORNELL_TALLBOX)[0];
    tall_box->mat()->set_diffuse(color_cornel_white);
    auto shot_box = MeshTriangle::mesh_load(PATH_CORNELL_SHORTBOX)[0];
    shot_box->mat()->set_diffuse(color_cornel_white);
    auto light = MeshTriangle::mesh_load(PATH_CORNELL_LIGHT)[0];
    light->mat()->set_emission(color_cornel_light);

    // 构建场景
    auto scene = std::make_shared<Scene>(256, 256, 40.f, Eigen::Vector3f{0.f, 0.f, 1.f},
                                         Eigen::Vector3f{278.f, 273.f, -800.f});
    scene->obj_add(floor);
    scene->obj_add(left);
    scene->obj_add(right);
    scene->obj_add(light);
    scene->obj_add(tall_box);
    scene->obj_add(shot_box);
    scene->build();

    /* 进行渲染 */
    RTRender::init(scene, 4);
    auto start = std::chrono::system_clock::now();
    // RTRender::render_multi_thread(DB_PATH, 8, 400, 100, 500);
    // RTRender::render_single_thread(DB_PATH);
    RTRender::render_atomic(DB_PATH);
    auto stop = std::chrono::system_clock::now();
    RTRender::write_to_file(RTRender::framebuffer, RT_RES, scene->screen_width(), scene->screen_height());

    /* 统计耗时 */
    fmt::print("\nrender complete\ntime taken: {} hours, {} minutes, {} seconds\n",
               std::chrono::duration_cast<std::chrono::hours>(stop - start).count(),
               std::chrono::duration_cast<std::chrono::minutes>(stop - start).count() % 60,
               std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() % 60);
    return 0;
}
