//
// Created by mcsam on 3/16/26.
//
#pragma once
#ifndef THINTA_FIXED_H
#define THINTA_FIXED_H
#include "internal/small_ints.h"

#define DEFINE_INT_CONVERSIONS(struct_type) \
static struct_type struct_type##_from_u8(u8 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_i8(i8 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_u16(u16 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_i16(i16 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_u32(u32 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_i32(i32 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_u64(u64 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_i64(i64 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_u128(u128 val) { return (struct_type){.bits = val}; } \
static struct_type struct_type##_from_i128(i128 val) { return (struct_type){.bits = val}; }

#define DEFINE_FIXED_CONVERSION(to_type, from_type) \
static inline to_type to_type##_from_##from_type(from_type val) { return (to_type){.bits = val.bits}; }


typedef struct sint192 {
    _BitInt(192) bits;
} sint192;

DEFINE_INT_CONVERSIONS(sint192)

typedef struct uint192 {
    unsigned _BitInt(192) bits;
} uint192;

DEFINE_INT_CONVERSIONS(uint192)

typedef struct sint256 {
    _BitInt(256) bits;
} sint256;

DEFINE_INT_CONVERSIONS(sint256)
DEFINE_FIXED_CONVERSION(sint256, sint192)
DEFINE_FIXED_CONVERSION(sint256, uint192)

typedef struct uint256 {
    unsigned _BitInt(256) bits;
} uint256;

DEFINE_INT_CONVERSIONS(uint256)
DEFINE_FIXED_CONVERSION(uint256, uint192)

typedef struct sint320 {
    _BitInt(320) bits;
} sint320;

DEFINE_INT_CONVERSIONS(sint320)
DEFINE_FIXED_CONVERSION(sint320, sint192)
DEFINE_FIXED_CONVERSION(sint320, uint192)
DEFINE_FIXED_CONVERSION(sint320, sint256)
DEFINE_FIXED_CONVERSION(sint320, uint256)

typedef struct uint320 {
    unsigned _BitInt(320) bits;
} uint320;

DEFINE_INT_CONVERSIONS(uint320)
DEFINE_FIXED_CONVERSION(uint320, uint192)
DEFINE_FIXED_CONVERSION(uint320, uint256)

typedef struct sint384 {
    _BitInt(384) bits;
} sint384;

DEFINE_INT_CONVERSIONS(sint384)
DEFINE_FIXED_CONVERSION(sint384, sint192)
DEFINE_FIXED_CONVERSION(sint384, uint192)
DEFINE_FIXED_CONVERSION(sint384, sint256)
DEFINE_FIXED_CONVERSION(sint384, uint256)
DEFINE_FIXED_CONVERSION(sint384, sint320)
DEFINE_FIXED_CONVERSION(sint384, uint320)

typedef struct uint384 {
    unsigned _BitInt(384) bits;
} uint384;

DEFINE_INT_CONVERSIONS(uint384)
DEFINE_FIXED_CONVERSION(uint384, uint192)
DEFINE_FIXED_CONVERSION(uint384, uint256)
DEFINE_FIXED_CONVERSION(uint384, uint320)

#endif //THINTA_FIXED_H
