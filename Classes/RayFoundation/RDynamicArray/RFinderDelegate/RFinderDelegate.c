#include "RFinderDelegate.h"
#include "../RDynamicArray.h"

method(byte, checkObject, RFinderDelegate), pointer objectToCheck){
    if(objectToCheck == object->etaloneObject){
        return object_founded;
    } else {
        if(object->virtualMethodcheckObjectOfRFinderDelegate == NULL){
            RPrintf("Warning. RFD. Virtual method is not implemented\n");
        } else {
            object->virtualMethodcheckObjectOfRFinderDelegate(object, objectToCheck);
        }
    }
}