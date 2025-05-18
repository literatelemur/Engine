#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

#include "Star.h"
#include "Graphics.h"
#include "main.h"

#include <GL/glut.h>

Star::Star(Graphics* graphics, double given_x, double given_y, double given_z, int given_lower_bound, int given_upper_bound){

    count = 0;
    depth = 5;

    origin_x = given_x;
    origin_y = given_y;
    origin_z = given_z;

    upper_bound = given_upper_bound;
    lower_bound = given_lower_bound;
    osc = 1;
    y_wait = 0;

    x = given_x;
    y = given_y;
    z = given_z;

    rect_points_3D_body = graphics->make_box({x, y, z}, 1, 1, depth);

}


void Star::render(Graphics* graphics){
    
    rect_points_3D_body = graphics->make_box({(double)x, (double)y, (double)z}, 1, 1, depth);
    std::vector<std::vector<int>> rect_points_2D_body = graphics->compute_2D_box(rect_points_3D_body);
    graphics->set_color(1, 1, 1);
    graphics->draw_hollow_box(rect_points_2D_body);

}


void Star::move(Graphics* graphics){

    if (osc){
        y_wait++;
        if (y_wait % 5 == 0) y++;
        if (y > upper_bound) osc = 0;
    }else if (!osc){
        y_wait--;
        if (y_wait % 5 == 0) y--;
        if (y < lower_bound) osc = 1;
    }

    // double x_diff_origin_3D = tan(anglex) * (z - origin_z);
    // double y_diff_origin_3D = tan(angley) * (z - origin_z);
    // //double z_diff_origin_3D = z - origin_z;

    // x = (int) (x_diff_origin_3D + origin_x);
    // y = (int) (y_diff_origin_3D + origin_y);

}