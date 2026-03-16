//
// Created by mcsam on 3/16/26.
//
#include "integers/fixed.h"
#include "internal/small_ints.h"

#define DEFINE_SINT_CONVERSIONS(struct_type)                                                 \
struct_type struct_type##_from_u8(const u8 val) { return (struct_type){.bits = val}; }   \
struct_type struct_type##_from_i8(const i8 val) { return (struct_type){.bits = val}; }   \
struct_type struct_type##_from_u16(const u16 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_i16(const i16 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u32(const u32 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_i32(const i32 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u64(const u64 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_i64(const i64 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u128(const u128 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_i128(const i128 val) { return (struct_type){.bits = val}; }

#define DEFINE_UINT_CONVERSIONS(struct_type)                                                 \
struct_type struct_type##_from_u8(const u8 val) { return (struct_type){.bits = val}; }   \
struct_type struct_type##_from_u16(const u16 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u32(const u32 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u64(const u64 val) { return (struct_type){.bits = val}; } \
struct_type struct_type##_from_u128(const u128 val) { return (struct_type){.bits = val}; }

DEFINE_SINT_CONVERSIONS(sint256)
DEFINE_UINT_CONVERSIONS(uint256)
