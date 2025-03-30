#pragma once
#include "algebraic-structure.hpp"

static_assert(MonoidConcept<MinMonoid<int>>);
static_assert(MonoidConcept<MaxMonoid<int>>);
static_assert(MonoidConcept<MultiplicativeMonoid<int>>);
static_assert(!GroupConcept<MinMonoid<int>>);
static_assert(!GroupConcept<MaxMonoid<int>>);
static_assert(!GroupConcept<MultiplicativeMonoid<int>>);

static_assert(MonoidConcept<AdditiveGroup<int>>);
static_assert(GroupConcept<AdditiveGroup<int>>);
static_assert(MonoidConcept<XORGroup<int>>);
static_assert(GroupConcept<XORGroup<int>>);
