//
// Created by mcsam on 3/16/26.
//
#pragma once
#ifndef THINTA_FIXED_H
#define THINTA_FIXED_H
#include "internal/small_ints.h"

#define DECLARE_SINT_CONVERSIONS(struct_type)                  \
    struct_type struct_type##_from_u8(const u8 val);           \
    struct_type struct_type##_from_i8(const i8 val);           \
    struct_type struct_type##_from_u16(const u16 val);         \
    struct_type struct_type##_from_i16(const i16 val);         \
    struct_type struct_type##_from_u32(const u32 val);         \
    struct_type struct_type##_from_i32(const i32 val);         \
    struct_type struct_type##_from_u64(const u64 val);         \
    struct_type struct_type##_from_i64(const i64 val);         \
    struct_type struct_type##_from_u128(const u128 val);       \
    struct_type struct_type##_from_i128(const i128 val);

#define DECLARE_UINT_CONVERSIONS(struct_type)                  \
    struct_type struct_type##_from_u8(const u8 val);           \
    struct_type struct_type##_from_u16(const u16 val);         \
    struct_type struct_type##_from_u32(const u32 val);         \
    struct_type struct_type##_from_u64(const u64 val);         \
    struct_type struct_type##_from_u128(const u128 val);

#define DECLARE_OP_SET(type, suffix, other_type)               \
    type type##_add_##suffix(const type a, const other_type b); \
    type type##_sub_##suffix(const type a, const other_type b); \
    type type##_mul_##suffix(const type a, const other_type b); \
    type type##_div_##suffix(const type a, const other_type b); \
    type type##_mod_##suffix(const type a, const other_type b); \
    void type##_addeq_##suffix(type *const a, const other_type b); \
    void type##_subeq_##suffix(type *const a, const other_type b); \
    void type##_muleq_##suffix(type *const a, const other_type b); \
    void type##_diveq_##suffix(type *const a, const other_type b); \
    void type##_modeq_##suffix(type *const a, const other_type b);

#define DECLARE_SINT_OPS(type)       \
    DECLARE_OP_SET(type, type, type) \
    DECLARE_OP_SET(type, u8, u8)     \
    DECLARE_OP_SET(type, i8, i8)     \
    DECLARE_OP_SET(type, u16, u16)   \
    DECLARE_OP_SET(type, i16, i16)   \
    DECLARE_OP_SET(type, u32, u32)   \
    DECLARE_OP_SET(type, i32, i32)   \
    DECLARE_OP_SET(type, u64, u64)   \
    DECLARE_OP_SET(type, i64, i64)   \
    DECLARE_OP_SET(type, u128, u128) \
    DECLARE_OP_SET(type, i128, i128)

#define DECLARE_UINT_OPS(type)       \
    DECLARE_OP_SET(type, type, type) \
    DECLARE_OP_SET(type, u8, u8)     \
    DECLARE_OP_SET(type, u16, u16)   \
    DECLARE_OP_SET(type, u32, u32)   \
    DECLARE_OP_SET(type, u64, u64)   \
    DECLARE_OP_SET(type, u128, u128)

typedef struct sint256 {
    _BitInt(256) bits;
} sint256;

DECLARE_SINT_CONVERSIONS(sint256)

DECLARE_SINT_OPS(sint256)

typedef struct uint256 {
    unsigned _BitInt(256) bits;
} uint256;

DECLARE_UINT_CONVERSIONS(uint256)

DECLARE_UINT_OPS(uint256)

#endif // THINTA_FIXED_H
