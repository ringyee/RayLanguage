/** *  _____ * |  __ \ * | |__) | __ _  _   _ * |  _  / / _` || | | | * | | \ \| (_| || |_| | * |_|  \_\\__,_| \__, | *                 __/ | *                |___/ *  ______                        _         _    _ * |  ____|                      | |       | |  (_) * | |__  ___   _   _  _ __    __| |  __ _ | |_  _   ___   _ __ * |  __|/ _ \ | | | || '_ \  / _` | / _` || __|| | / _ \ | '_ \ * | |  | (_) || |_| || | | || (_| || (_| || |_ | || (_) || | | | * |_|   \___/  \__,_||_| |_| \__,_| \__,_| \__||_| \___/ |_| |_| * **/#include <RayFoundation.h>#include "Tests.h"int main(int argc, const char *argv[]) {    enablePool(RPool);    RCTSingleton;    ComplexTest();    // place your code here    deleter(RCTSingleton, RClassTable);    $(RPool, p(RAutoPool)));    deleter(RPool, RAutoPool);    return 0;}//RThread *receiverThread = c(RThread)(nil, nil, receiverFunc, nil);//RThread *senderThread = c(RThread)(nil, nil, senderFunc, nil);////$(receiverThread, m(join, RThread)));//$(senderThread, m(join, RThread)));////deleter(receiverThread, RThread);//deleter(senderThread, RThread);//#define PORT 9000//#define TEST_COUNT 5////pointer receiverFunc(pointer arg) {//    enablePool(RPool);////    RReceiver *receiver = c(RReceiver)(nil, PORT);//    RSender *sender = c(RSender)(nil, PORT);////    RStringDictionary *dict = c(RStringDictionary)(nil);//    dict->masterRDictionaryObject->values->destructorDelegate = (void (*)(pointer)) stringDeleter;////    if(receiver != nil) {//        RByteArray *buffer = c(RByteArray)(nil, 1500);//        RCString *key, *value, *request, *string;//        rbool isSet;//        while($(receiver, m(receive, RReceiver)), buffer) != 255){//            if(receiver->packetCounter == TEST_COUNT) {//                break;//            }//            string = RS((char*)buffer->array);//            if(string->size > 6) {//                if( (isSet = $(string, m(startsOnStr, RCString)), "set "))//                        || $(string, m(startsOnStr, RCString)), "get ") ) {////                    request = $(string, m(substringInRange, RCString)), makeRRange(4, string->size - 4));////                    if(isSet) {//                        value = $(request, m(substringToSymbol, RCString)), ' ');//                        if(value->size + 2 <= request->size) {//                            key = $(request, m(substringInRange, RCString)), makeRRange(value->size + 1, request->size - 1 - value->size));//                            $(dict, m(setObjectForKey, RStringDictionary)), value, key);////                            $(sender, m(setReceiverAddress, RSender)), inet_ntoa(receiver->senderAddress.sin_addr));//                            RPrintf("%s set %s for key %s\n", inet_ntoa(receiver->senderAddress.sin_addr), value->baseString, key->baseString);//                            $(sender, m(send, RSender)), RS("OK"));//                        }////                    } else {//                        value = (RCString*)$(dict, m(getObjectForKey, RStringDictionary)), request);//                        if(value != nil) {//                            $(sender, m(setReceiverAddress, RSender)), inet_ntoa(receiver->senderAddress.sin_addr));//                            RPrintf("%s get %s for key %s\n", inet_ntoa(receiver->senderAddress.sin_addr), request->baseString, value->baseString);//                            $(sender, m(send, RSender)), value);//                        } else {//                            RPrintf("Error value for key %s\n", request->baseString);//                        }//                    }////                }//            }//            deallocator(string);//        }//        $(dict, p(RStringDictionary)));//        deleter(buffer, RByteArray);//        deleter(dict, RStringDictionary);//        deleter(receiver, RReceiver);//    }//    return nil;//}////pointer senderFunc(pointer arg) {//    enablePool(RPool);//    size_t iterator;//    RSender *sender = c(RSender)(nil, PORT);//    if(sender != nil) {//        $(sender, m(setReceiverAddress, RSender)), "127.0.0.1");//        RCString *req = RS("set value key");//        forAll(iterator, TEST_COUNT) {//            $(sender, m(send, RSender)), req);//            sleep(1);//        }//        deallocator(req);//        deleter(sender, RSender);//    }//    return nil;//}