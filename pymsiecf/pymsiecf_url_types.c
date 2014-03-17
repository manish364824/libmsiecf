/*
 * Python object definition of the libmsiecf URL item types
 *
 * Copyright (C) 2009-2014, Joachim Metz <joachim.metz@gmail.com>
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
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pymsiecf_libmsiecf.h"
#include "pymsiecf_python.h"
#include "pymsiecf_unused.h"
#include "pymsiecf_url_types.h"

PyTypeObject pymsiecf_url_types_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pymsiecf.url_types",
	/* tp_basicsize */
	sizeof( pymsiecf_url_types_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pymsiecf_url_types_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
        /* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pymsiecf url types object (wraps LIBMSIECF_URL_ITEM_TYPES)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pymsiecf_url_types_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pymsiecf_url_types_init_type(
     PyTypeObject *type_object )
{
	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "UNDEFINED",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_UNDEFINED ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "CACHE",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_CACHE ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "COMPATIBILITY",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_COMPATIBILITY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "COOKIE",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_COOKIE ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "DOM_STORE",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_DOM_STORE ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "DOWNLOAD",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_DOWNLOAD ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "HISTORY",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_HISTORY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "HISTORY_DAILY",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_HISTORY_DAILY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "HISTORY_WEEKLY",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_HISTORY_WEEKLY ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "INPRIVATE_FILTERING",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_INPRIVATE_FILTERING ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "RSS_FEED",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_RSS_FEED ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "TLD",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_TLD ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "USER_DATA",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_USER_DATA ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
             type_object->tp_dict,
             "UNKNOWN",
             PyInt_FromLong(
              LIBMSIECF_URL_ITEM_TYPE_UNKNOWN ) ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new url types object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pymsiecf_url_types_new(
           void )
{
	pymsiecf_url_types_t *pymsiecf_url_types = NULL;
	static char *function                    = "pymsiecf_url_types_new";

	pymsiecf_url_types = PyObject_New(
	                      struct pymsiecf_url_types,
	                      &pymsiecf_url_types_type_object );

	if( pymsiecf_url_types == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize url types.",
		 function );

		goto on_error;
	}
	if( pymsiecf_url_types_init(
	     pymsiecf_url_types ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize url types.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pymsiecf_url_types );

on_error:
	if( pymsiecf_url_types != NULL )
	{
		Py_DecRef(
		 (PyObject *) pymsiecf_url_types );
	}
	return( NULL );
}

/* Intializes a url types object
 * Returns 0 if successful or -1 on error
 */
int pymsiecf_url_types_init(
     pymsiecf_url_types_t *pymsiecf_url_types )
{
	static char *function = "pymsiecf_url_types_init";

	if( pymsiecf_url_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid url types.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees a url types object
 */
void pymsiecf_url_types_free(
      pymsiecf_url_types_t *pymsiecf_url_types )
{
	static char *function = "pymsiecf_url_types_free";

	if( pymsiecf_url_types == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid url types.",
		 function );

		return;
	}
	if( pymsiecf_url_types->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid url types - missing ob_type.",
		 function );

		return;
	}
	if( pymsiecf_url_types->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid url types - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	pymsiecf_url_types->ob_type->tp_free(
	 (PyObject*) pymsiecf_url_types );
}
