#include <Python.h>

// [1,2,"three"]
PyObject *t;
t = PyTuple_New(3);
l = PyList_New(3);
PyTuple_SetItem( t, 0, PyInt_FromLong(1L));
PyTuple_SetItem( t, 1, PyInt_FromLong(2L));
PyTuple_SetItem( t, 2, PyString_FromString("three"));

// tuple, list 
PyObject *tuple, *list;
tuple = Py_BuildValue( "(iis)", 1, 2, "three" );
list = Py_BuildValue( "[iis]", 1, 2, "three" );


int 
set_all( PyObject *target, PyObject *item )
{
	int i, n;
	
	n = PyObject_Length( target );
	if ( n < 0 )
		return -1;

	for ( i=0; i<n; ++i )
	{
		PyObject *index = PyInt_FromLong(i);
	
		if (!index)
			return -1;

		if (PyObject SetItem( target, index, item ) < 0 ) {
			Py_DECREF( index )
			return -1;
		}
		Py_DECREF( index );
	}

	return 0;
}

long
sum_list( PyObject* list )
{
	int i, n;
	long total = 0;
	PyObject *item;

	n = PyList_Size( list );
	if ( n < 0 )
		return -1;

	for (i=0; i<n; ++i ) {
		item = PyList_GetItem( list ,i );
		if( !PyInt_Check( item )) continue; // skip non-integer
		total += PyInt_AsLong( item );
	}
	
	return total;
}

long
sum_sequence( PyObject* sequence )
{
	int i, n;
	long total = 0;

	PyObject *item;
	n = PySequence_Length( sequence );

	if ( n < 0 )
		return -1;

	for (i=0; i<n; ++i )
	{
		item = PySequence_GetItem( sequence, i );
		if ( item == NULL )
			return -1;		// Not a sequence, or other failure
		if ( PyInt_Check(item) )
			total += PyInt_AsLong( item );
		Py_DECREF( item );	// discard reference ownership 
	}

	return total;
}



static PyObject* spam_system(PyObject *self, PyObject *args);

static PyMethodDef SpamMethods[] = 
{
    {"system", spam_system, METH_VARARGS, "Execute a shell command"},
    {NULL, NULL, 0, NULL}
};

static PyObject*
spam_system(PyObject *self, PyObject *args)
{
	const char *command;
	int sts;

	if(!PyArg_ParseTuple(args, "s", &command))
		return NULL;
	sts = system(command);

	return Py_BuildValue("i", sts);
}

PyMODINIT_FUNC
initspam( void )
{
    (void)Py_InitModule("spam", SpamMethods);
}

