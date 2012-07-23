#include "../headers/headers.h"

grain::grain() {
    parent = NULL;
    /*
    attri[H] = 0; //H, D_L, B_V, B_K, T_K, V_G, T_V, L_K, L_M
    attri[D_L] = 0;
    attri[B_V] = 0;
    attri[B_K] = 0;
    attri[T_K] = 0;
    attri[V_G] = 0;
    attri[T_V] = 0;
    attri[L_K] = 0;
    attri[L_M] = 0;
    */

}

grain::grain(const grain& g) {
    (*this) = g;
}

grain& grain::operator = (const grain& g) {
    attri    = g.attri;
    parent   = g.parent;
    position = g.position;
    return *this;
}

void grain::init(int x, int y, paper* p) {
    position = V2D(x, y);
    parent = p;
}

grain& grain::operator () (ATTRI name, float value) {
    attri[name] = value;
    return *this;
}

float& grain::operator [] (ATTRI name) {
    return attri[name];
}

float& grain::operator [] (V2D::AXIS axis) {
    return position[axis];
}

#define GRAIN1(x, y, A) ((*parent)(position[V2D::X]+x, position[V2D::Y]+y)[A])
#define GRAIN2(x, y, F) ((*parent)(position[V2D::X]+x, position[V2D::Y]+y).F)
float grain::h_max() {
    return MAX4(GRAIN1(0, 0, H), GRAIN1(1, 0, H), GRAIN1(0, 1, H), GRAIN1(1, 1, H));
}
float grain::h_min() {
    return MIN4(GRAIN1(0, 0, H), GRAIN1(1, 0, H), GRAIN1(0, 1, H), GRAIN1(1, 1, H));
}
float grain::h_sum() {
    return GRAIN1(0, 0, H) + GRAIN1(1, 0, H) + GRAIN1(0, 1, H) + GRAIN1(1, 1, H);
}

float grain::hp() {
    return h_max() - attri[H];
}

float grain::hp_max() {
    return MAX4(GRAIN2(0, 0, hp()), GRAIN2(1, 0, hp()), GRAIN2(0, 1, hp()), GRAIN2(1, 1, hp()));
}
float grain::hp_min() {
    return MIN4(GRAIN2(0, 0, hp()), GRAIN2(1, 0, hp()), GRAIN2(0, 1, hp()), GRAIN2(1, 1, hp()));
}
float grain::hp_sum() {
    return GRAIN2(0, 0, hp()) + GRAIN2(1, 0, hp()) + GRAIN2(0, 1, hp()) + GRAIN2(1, 1, hp());
}

float grain::v_g() {
    return hp_sum() / 4;
}
float grain::d_k(float h) {
    float sum = h_sum();
    return sum < DIFF ? 0 :h / sum;
}

#undef GRAIN2
#undef GRAIN1
