/** *  _____ * |  __ \ * | |__) | __ _  _   _ * |  _  / / _` || | | | * | | \ \| (_| || |_| | * |_|  \_\\__,_| \__, | *                 __/ | *                |___/ *  ______                        _         _    _ * |  ____|                      | |       | |  (_) * | |__  ___   _   _  _ __    __| |  __ _ | |_  _   ___   _ __ * |  __|/ _ \ | | | || '_ \  / _` | / _` || __|| | / _ \ | '_ \ * | |  | (_) || |_| || | | || (_| || (_| || |_ | || (_) || | | | * |_|   \___/  \__,_||_| |_| \__,_| \__,_| \__||_| \___/ |_| |_| * **/#include <RayFoundation.h>#include "Tests.h"void func(pointer arg) {    size_t iterator;    enablePool(RPool);    forAll(iterator, 3) {        RPrintf("worker tuid - %qu\n", getThreadId());        registerClassOnce("Some me");        registerClassOnce("Some me");    }}int main(int argc, const char *argv[]) {    size_t iterator;    enablePool(RPool);    RCTSingleton;    ComplexTest();    RPrintf("Main tuid - %qu\n", getThreadId());    //    RThreadPool *threadPool = constructorOfRThreadPool(nil);    threadPool->delegate = (RThreadFunction) func;//    forAll(iterator, 3) {        $(threadPool, m(addWithArg, RThreadPool)), nil);    }    $(threadPool, m(join, RThreadPool)));    deleter(threadPool, RThreadPool);    $(RCTSingleton, p(RClassTable)));    deleter(RCTSingleton, RClassTable);    $(RPool, p(RAutoPool)));    deleter(RPool, RAutoPool);    return 0;}