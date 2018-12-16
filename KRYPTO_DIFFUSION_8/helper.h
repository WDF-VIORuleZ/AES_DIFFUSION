#pragma once

#include <vector>

#include "tables.h"
#include "ASES.h"

namespace h
{
	std::vector<int8_t> split_to_bytes(int32_t WORD);

	void copy_val_to_table(int8_t(*dest)[4], int32_t arr[4])
	{
		for (int i = 0; i < 4; i++)
		{
			std::vector<int8_t> vals = split_to_bytes(arr[i]);

			for (int j = 0; j < 4; j++)
			{
				dest[i][j] = vals[j];
			}
			/*
			dest[i][0] = vals[0];
			dest[i][1] = vals[1];
			dest[i][2] = vals[2];
			dest[i][3] = vals[3];
			*/
		}
	}

	std::vector<int8_t> split_to_bytes(int32_t WORD)
	{
		std::vector<int8_t> result;
		/*
		int8_t result[4] = { (WORD & 0xff000000UL) >> 24 , (WORD & 0x00ff0000UL) >> 16 , (WORD & 0xff00ff00UL) >> 8 , (WORD & 0x000000ff) };
		return &result[0];
		*/

		int8_t B0 = (WORD & 0xff000000UL) >> 24;
		int8_t B1 = (WORD & 0x00ff0000UL) >> 16;
		int8_t B2 = (WORD & 0xff00ff00UL) >> 8;
		int8_t B3 = (WORD & 0xff0000ffUL);

		result.push_back(B0);
		result.push_back(B1);
		result.push_back(B2);
		result.push_back(B3);

		return result;
	}

	void print_arr(int8_t arr[4][4])
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				fprintf_s(stdout, "%d", arr[i][j]);
			puts("");
		}
	}


}