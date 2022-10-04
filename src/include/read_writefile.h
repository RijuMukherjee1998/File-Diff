#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void splitFileBytes(const char in_filepath[], char out_filepath[], const char extension[], unsigned int out_byte_count);
void combineFileBytes(const char outfile_path[]);
