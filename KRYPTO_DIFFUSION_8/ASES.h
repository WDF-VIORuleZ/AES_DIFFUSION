#pragma once

#include "helper.h"
#include "tables.h"

namespace AES
{
	using std::vector;

	void substitution_layer(int32_t A0A15[4], int32_t *dest[4])
	{
		vector<int8_t> B0_B3, B4_B7, B8_B11, B12_B15;

		vector<int8_t> A0_A3   = h::split_to_bytes(A0A15[0]);
		vector<int8_t> A4_A7   = h::split_to_bytes(A0A15[1]);
		vector<int8_t> A8_A11  = h::split_to_bytes(A0A15[2]);
		vector<int8_t> A12_A15 = h::split_to_bytes(A0A15[3]);

		// S-Box Values Stored In B-Vectors
		for (int i = 0; i < 4; i++)
		{
			B0_B3.push_back(t::calc_sbox(A0_A3[i]));
			B4_B7.push_back(t::calc_sbox(A4_A7[i]));
			B8_B11.push_back(t::calc_sbox(A8_A11[i]));
			B12_B15.push_back(t::calc_sbox(A12_A15[i]));
		}
		
	}

	void shift_row_layer(int8_t(*src)[4], int8_t(*dest)[4])
	{
		for (int i = 0; i < 4; i++)
		{
			dest[0][i] = src[0][i];
		}

		dest[1][0] = src[1][1];
		dest[1][1] = src[1][2];
		dest[1][2] = src[1][3];
		dest[1][3] = src[1][0];

		dest[2][0] = src[2][2];
		dest[2][1] = src[2][3];
		dest[2][2] = src[2][0];
		dest[2][3] = src[2][1];

		dest[3][0] = src[3][3];
		dest[3][1] = src[3][0];
		dest[3][2] = src[3][1];
		dest[3][3] = src[3][2];
	}

	// MixColumn(B) = C

	// src = [Bi1, Bi2, Bi3, Bi4]
	// rtn = [C0, C1, C2, C3], size = 4
	void mix_column(int8_t src[4], int8_t *dest[4])
	{
		int8_t fix_matrix[4][4]=
		{
			{0x02, 0x03, 0x01, 0x01},
			{0x01, 0x02, 0x03, 0x01},
			{0x01, 0x01, 0x02, 0x03},
			{0x03, 0x01, 0x02, 0x02}
		};

		for (int i = 0; i < 4; i++)
		{
			int8_t ret_val_i = 0;
			for (int j = 0; j < 4; j++)
				ret_val_i += fix_matrix[i][j] * (src[j]);
			*dest[i] = ret_val_i;
		}
	}

	void key_addition()
	{

	}
}