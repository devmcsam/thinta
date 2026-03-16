//
// Created by mcsam on 3/16/26.
//
#include "integers/fixed.h"
#include "internal/small_ints.h"

#define DEFINE_OP_SET(type, suffix, other_type, access_bits)                                 \
    type type##_add_##suffix(const type a, const other_type b) {                             \
        return (type){.bits = a.bits + (access_bits)};                                       \
    }                                                                                        \
    type type##_sub_##suffix(const type a, const other_type b) {                             \
        return (type){.bits = a.bits - (access_bits)};                                       \
    }                                                                                        \
    type type##_mul_##suffix(const type a, const other_type b) {                             \
        return (type){.bits = a.bits * (access_bits)};                                       \
    }                                                                                        \
    type type##_div_##suffix(const type a, const other_type b) {                             \
        return (type){.bits = a.bits / (access_bits)};                                       \
    }                                                                                        \
    type type##_mod_##suffix(const type a, const other_type b) {                             \
        return (type){.bits = a.bits % (access_bits)};                                       \
    }                                                                                        \
    void type##_addeq_##suffix(type *const a, const other_type b) {                          \
        a->bits += (access_bits);                                                            \
    }                                                                                        \
    void type##_subeq_##suffix(type *const a, const other_type b) {                          \
        a->bits -= (access_bits);                                                            \
    }                                                                                        \
    void type##_muleq_##suffix(type *const a, const other_type b) {                          \
        a->bits *= (access_bits);                                                            \
    }                                                                                        \
    void type##_diveq_##suffix(type *const a, const other_type b) {                          \
        a->bits /= (access_bits);                                                            \
    }                                                                                        \
    void type##_modeq_##suffix(type *const a, const other_type b) {                          \
        a->bits %= (access_bits);                                                            \
    }

#define DEFINE_SINT_OPS(type)                \
    DEFINE_OP_SET(type, type, type, b.bits)  \
    DEFINE_OP_SET(type, u8, u8, b)           \
    DEFINE_OP_SET(type, i8, i8, b)           \
    DEFINE_OP_SET(type, u16, u16, b)         \
    DEFINE_OP_SET(type, i16, i16, b)         \
    DEFINE_OP_SET(type, u32, u32, b)         \
    DEFINE_OP_SET(type, i32, i32, b)         \
    DEFINE_OP_SET(type, u64, u64, b)         \
    DEFINE_OP_SET(type, i64, i64, b)         \
    DEFINE_OP_SET(type, u128, u128, b)       \
    DEFINE_OP_SET(type, i128, i128, b)

#define DEFINE_UINT_OPS(type)                \
    DEFINE_OP_SET(type, type, type, b.bits)  \
    DEFINE_OP_SET(type, u8, u8, b)           \
    DEFINE_OP_SET(type, u16, u16, b)         \
    DEFINE_OP_SET(type, u32, u32, b)         \
    DEFINE_OP_SET(type, u64, u64, b)         \
    DEFINE_OP_SET(type, u128, u128, b)

DEFINE_SINT_OPS(sint256)
DEFINE_UINT_OPS(uint256)
