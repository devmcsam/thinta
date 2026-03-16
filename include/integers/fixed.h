//
// Created by mcsam on 3/16/26.
//
#pragma once
#ifndef THINTA_FIXED_H
#define THINTA_FIXED_H

typedef struct sint192 {
    _BitInt(192) bits;
} sint192;

typedef struct uint192 {
    unsigned _BitInt(192) bits;
} uint192;

typedef struct sint256 {
    _BitInt(256) bits;
} sint256;

typedef struct uint256 {
    unsigned _BitInt(256) bits;
} uint256;

typedef struct sint320 {
    _BitInt(320) bits;
} sint320;

typedef struct uint320 {
    unsigned _BitInt(320) bits;
} uint320;

typedef struct sint384 {
    _BitInt(384) bits;
} sint384;

typedef struct uint384 {
    unsigned _BitInt(384) bits;
} uint384;

#endif //THINTA_FIXED_H
