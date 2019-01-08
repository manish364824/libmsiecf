/*
 * Hash functions
 *
 * Copyright (C) 2009-2019, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <byte_stream.h>
#include <types.h>

#include "libmsiecf_hash.h"
#include "libmsiecf_libcerror.h"

static uint8_t libmsiecf_hash_pad_table[ 256 ] = {
	0x01, 0x0e, 0x6e, 0x19, 0x61, 0xae, 0x84, 0x77,
	0x8a, 0xaa, 0x7d, 0x76, 0x1b, 0xe9, 0x8c, 0x33,
	0x57, 0xc5, 0xb1, 0x6b, 0xea, 0xa9, 0x38, 0x44,
	0x1e, 0x07, 0xad, 0x49, 0xbc, 0x28, 0x24, 0x41,
	0x31, 0xd5, 0x68, 0xbe, 0x39, 0xd3, 0x94, 0xdf,
	0x30, 0x73, 0x0f, 0x02, 0x43, 0xba, 0xd2, 0x1c,
	0x0c, 0xb5, 0x67, 0x46, 0x16, 0x3a, 0x4b, 0x4e,
	0xb7, 0xa7, 0xee, 0x9d, 0x7c, 0x93, 0xac, 0x90,
	0xb0, 0xa1, 0x8d, 0x56, 0x3c, 0x42, 0x80, 0x53,
	0x9c, 0xf1, 0x4f, 0x2e, 0xa8, 0xc6, 0x29, 0xfe,
	0xb2, 0x55, 0xfd, 0xed, 0xfa, 0x9a, 0x85, 0x58,
	0x23, 0xce, 0x5f, 0x74, 0xfc, 0xc0, 0x36, 0xdd,
	0x66, 0xda, 0xff, 0xf0, 0x52, 0x6a, 0x9e, 0xc9,
	0x3d, 0x03, 0x59, 0x09, 0x2a, 0x9b, 0x9f, 0x5d,
	0xa6, 0x50, 0x32, 0x22, 0xaf, 0xc3, 0x64, 0x63,
	0x1a, 0x96, 0x10, 0x91, 0x04, 0x21, 0x08, 0xbd,
	0x79, 0x40, 0x4d, 0x48, 0xd0, 0xf5, 0x82, 0x7a,
	0x8f, 0x37, 0x69, 0x86, 0x1d, 0xa4, 0xb9, 0xc2,
	0xc1, 0xef, 0x65, 0xf2, 0x05, 0xab, 0x7e, 0x0b,
	0x4a, 0x3b, 0x89, 0xe4, 0x6c, 0xbf, 0xe8, 0x8b,
	0x06, 0x18, 0x51, 0x14, 0x7f, 0x11, 0x5b, 0x5c,
	0xfb, 0x97, 0xe1, 0xcf, 0x15, 0x62, 0x71, 0x70,
	0x54, 0xe2, 0x12, 0xd6, 0xc7, 0xbb, 0x0d, 0x20,
	0x5e, 0xdc, 0xe0, 0xd4, 0xf7, 0xcc, 0xc4, 0x2b,
	0xf9, 0xec, 0x2d, 0xf4, 0x6f, 0xb6, 0x99, 0x88,
	0x81, 0x5a, 0xd9, 0xca, 0x13, 0xa5, 0xe7, 0x47,
	0xe6, 0x8e, 0x60, 0xe3, 0x3e, 0xb3, 0xf6, 0x72,
	0xa2, 0x35, 0xa0, 0xd7, 0xcd, 0xb4, 0x2f, 0x6d,
	0x2c, 0x26, 0x1f, 0x95, 0x87, 0x00, 0xd8, 0x34,
	0x3f, 0x17, 0x25, 0x45, 0x27, 0x75, 0x92, 0xb8,
	0xa3, 0xc8, 0xde, 0xeb, 0xf8, 0xf3, 0xdb, 0x0a,
	0x98, 0x83, 0x7b, 0xe5, 0xcb, 0x4c, 0x78, 0xd1
};

/* Calcates the hash based of a string
 * Returns 1 if successful or -1 on error
 */
int libmsiecf_hash_calculate(
     uint32_t *hash_value,
     const uint8_t *string,
     size_t string_length,
     libcerror_error_t **error )
{
	uint8_t hash_data[ 4 ];

	static char *function = "libmsiecf_hash_calculate";
	size_t string_index   = 0;

	if( hash_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid hash value.",
		 function );

		return( -1 );
	}
	if( string == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid string.",
		 function );

		return( -1 );
	}
	if( ( string_length < 4 )
	 || ( string_length > (size_t) SSIZE_MAX ) )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS,
		 "%s: invalid string length value out of bounds.",
		 function );

		return( -1 );
	}
	hash_data[ 0 ] = libmsiecf_hash_pad_table[ string[ 0 ] ];
	hash_data[ 1 ] = libmsiecf_hash_pad_table[ string[ 1 ] ];
	hash_data[ 2 ] = libmsiecf_hash_pad_table[ string[ 2 ] ];
	hash_data[ 3 ] = libmsiecf_hash_pad_table[ string[ 3 ] ];

	for( string_index = 1;
	     string_index < string_length;
	     string_index++ )
	{
		/* Ignore the end-of-string character
		 */
		if( string[ string_index ] == 0 )
		{
			break;
		}
		/* Ignore a trailing forward slash
		 */
		if( ( string[ string_index ] == (uint8_t) '/' )
		 && ( string[ string_index + 1 ] == 0 ) )
		{
			break;
		}
		hash_data[ 0 ] ^= string[ string_index ];
		hash_data[ 1 ] ^= string[ string_index ];
		hash_data[ 2 ] ^= string[ string_index ];
		hash_data[ 3 ] ^= string[ string_index ];

		hash_data[ 0 ] = libmsiecf_hash_pad_table[ hash_data[ 0 ] ];
		hash_data[ 1 ] = libmsiecf_hash_pad_table[ hash_data[ 1 ] ];
		hash_data[ 2 ] = libmsiecf_hash_pad_table[ hash_data[ 2 ] ];
		hash_data[ 3 ] = libmsiecf_hash_pad_table[ hash_data[ 3 ] ];
	}
	byte_stream_copy_to_uint32_little_endian(
	 hash_data,
	 *hash_value );

	*hash_value &= 0xffffffc0UL;

	return( 1 );
}

