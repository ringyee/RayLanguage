#include "RIClass.h"
#include "../RIMethods/RIMethods.h"
#include "../RIProperties/RIProperties.h"

#define ifdel(object, property, class) if(object->property != nil) { \
                                       deleter(object->property, class) }

constructor(RayClass)) {
    object = allocator(RayClass);
    if(object != nil) {
        object->classId = registerClassOnce(toString(RayClass));
        object->methods       = makeRArray();
        object->properties    = makeRArray();
        object->masterClasses = makeRArray();
        object->statics       = makeRArray();
    }
    return object;
}

destructor(RayClass) {
    ifdel(object, methods,       RArray);
    ifdel(object, properties,    RArray);
    ifdel(object, masterClasses, RArray);
    ifdel(object, statics,       RArray);
    ifdel(object, name,          RCString);
}

printer(RayClass) {
    RPrintf("%s - object - %p { \n", toString(RayClass), object);
    RPrintf("} %p object\n", object);
}

#pragma mark Workers

method(RCString*, methodSingletonName, RayClass)) {
    // copy name
    RCString *result = $(object->name, m(copy, RCString)) );
    $(result, m(appendString, RCString)), "_MethodSingleton");
    return result;
}

method(RCString*, methodSingletonFor, RayClass), RClassTable *table) {
    size_t iterator;
    size_t masterClassIterator;
    RCString *result = RSC("");
    RCString *name = $(object, m(methodSingletonName, RayClass)));
    // declare struct
    $(result, m(appendString, RCString)), "typedef struct ");
    $(result, m(concatenate, RCString)), name );
    $(result, m(appendString, RCString)), " {\n");

    // add some methods-pointers from master-classes
    forAll(masterClassIterator, object->masterClasses->count){
        RayClass *masterClass = object->masterClasses->array[masterClassIterator];
        forAll(iterator, masterClass->methods->count) {

            // if method is not inner
            if(!(((RayMethod*)masterClass->methods->array[iterator])->type & MTInner)) {

                // serialize it
                RCString *methodPtr = $((RayMethod*)masterClass->methods->array[iterator], m(serializetoCPointer, RayMethod)), table);
                $(result, m(appendString, RCString)), "    ");
                $(result, m(concatenate, RCString)),methodPtr);
                $(result, m(appendString, RCString)), ";\n");
                deleter(methodPtr, RCString);
            }
        }
    }

    // add some methods-pointers
    forAll(iterator, object->methods->count) {
        RCString *methodPtr = $((RayMethod*)object->methods->array[iterator], m(serializetoCPointer, RayMethod)), table);
        $(result, m(appendString, RCString)), "    ");
        $(result, m(concatenate, RCString)),methodPtr);
        $(result, m(appendString, RCString)), ";\n");
        deleter(methodPtr, RCString);
    }

    // end declare struct
    $(result, m(appendString, RCString)), "} ");
    $(result, m(concatenate, RCString)), name );
    $(result, m(appendString, RCString)), ";");

    deleter(name, RCString);

    return result;
}

method(RCString*, classStructWithMasterClass, RayClass), RClassTable *table) {
    size_t iterator;
    size_t masterClassIterator;
    RCString *result = RSC("");
    RCString *singletonName = $(object, m(methodSingletonName, RayClass)));

    // declare struct
    $(result, m(appendString, RCString)), "typedef struct ");
    $(result, m(concatenate, RCString)), object->name );
    $(result, m(appendString, RCString)), " {\n");

    // add method singleton property
    $(result, m(appendString, RCString)), "    ");
    $(result, m(concatenate, RCString)), singletonName);
    $(result, m(appendString, RCString)), " *methodSingleton;\n");

    // add masterClass properties
    forAll(masterClassIterator, object->masterClasses->count) {
        // get masterClass
        RayClass *masterClass = object->masterClasses->array[masterClassIterator];
        forAll(iterator, masterClass->properties->count) {

            // if property is not inner
            if(((RayProperty*)masterClass->properties->array[iterator])->type != PTInner) {
                RCString *property = $((RayProperty*)masterClass->properties->array[iterator], m(serializeToCType, RayProperty)), table);

                // serialize it
                $(result, m(appendString, RCString)), "    ");
                $(result, m(concatenate, RCString)), property);
                $(result, m(appendString, RCString)), ";\n");
                deleter(property, RCString);
            }
        }
    }

    // add self properties
    forAll(iterator, object->properties->count) {
        RCString *property = $((RayProperty*)object->properties->array[iterator], m(serializeToCType, RayProperty)), table);
        $(result, m(appendString, RCString)), "    ");
        $(result, m(concatenate, RCString)), property);
        $(result, m(appendString, RCString)), ";\n");
        deleter(property, RCString);
    }

    // end declare struct
    $(result, m(appendString, RCString)), "} ");
    $(result, m(concatenate, RCString)), object->name );
    $(result, m(appendString, RCString)), ";");
    return result;
}