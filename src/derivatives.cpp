#include "derivatives.hpp"

Random::Random(int c): x(c) {}
Random::~Random() {}
int Random::get() const {return x;}
void Random::set(int c) {x = c;}
