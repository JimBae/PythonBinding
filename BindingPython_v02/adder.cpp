#include <Python.h>

// import addList
// addList.add( pyList )


// * The <Python.h> file consists of all the required types (to represent Python object types)
//    and function definitions (to operate on the python objects).
//
// * Next we write the function which we plan to call from python. 
//   Conventionally the function names are {module-name}_{function-name}, 
//   which in this case is addList_add. More about the function later.
// * Then fill in the info table - which contains all the relevant info of the functions we desire to have in the module.
//   Every row corresponds to a function, with the last one being a sentinel value (row of null elements).
// * Finally the module initialization block which is of the signature PyMODINIT_FUNC init{module-name}.



// {module-name}_{function-name}
static PyObject* addList_add( PyObject* self, PyObject* args )
{
	//This is the function that is called from your python code
	PyObject *listObj;
	
	//The input arguments come as a tuple, we parse the args to get the various variables
	//In this case it's only one list variable, which will now be referenced by listObj
	if( !PyArg_ParseTuple( args, "0", & listObj ) )
		return NULL;

	//length of the list
	long length = PyList_Size( listObj );
	
	// iterate over all the elements
	int i, sum = 0;
	for( int i=0; i<length; ++i )
	{
		//get an element out of the list - the element is also a python objects
		// PyList_GetItem(list, index)
		PyObject* temp = PyList_GetItem( listObj, i );
		//we know that object represents an integer - so convert it into C long
		long elem = PyInt_AsLong( temp );
		sum += elem;
	}

	//value returned back to python code - another python object
	//build value here converts the C long to a python integer
	// “i” indicates that the value we want to build is a python integer object
	return Py_BuildValue( "i", sum );
}

// This is the docstring that corresponds to our 'add' function
static char addList_docs[] = "add(): add all element of the list\n";

/* This table contains the relavent info mapping -
  <function-name in python module>, <actual-function>,
  <type-of-args the function expects>, <docstring associated with the function>
*/
static PyMethodDef addList_funcs[] = { 
	{ "add", (PyCFunction)addList_add, METH_VARARGS, addList_docs},
	{ NULL, NULL, 0, NULL }
};

/*
addList is the module name, and this is the initialization block of the module.
<desired module name>, <the-info-table>, <module's-docstring>
Signature : PyMODINIT_FUNC init{module-name}
*/
PyMODINIT_FUNC 
initaddList( void )
{
	Py_InitModule3( "addList", addList_funcs, "Add all list's elements");
}





