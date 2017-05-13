#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
 
// node headers
#include <v8.h>
#include <node.h>
#include <unistd.h>
#include <string.h>

#include "reach.hh"

using namespace node;
using namespace v8;

Persistent<Function> * callback;
v8::Isolate* isolate;
 
// callback that runs the javascript in main thread
static void Callback(int number)
{
    TryCatch try_catch;
 
    // prepare arguments for the callback
    Local<Value> argv[1];
    argv[0] = Integer::New(isolate, number);
 
    // call the callback and handle possible exception
    callback->Get(isolate)->Call(v8::Object::New(isolate), 1, argv);
 
    if (try_catch.HasCaught()) {
        FatalException(try_catch);
    }
}

void Stop(const v8::FunctionCallbackInfo<v8::Value>& args) {

    StopReachabilityNotifier();
}

void Start(const v8::FunctionCallbackInfo<v8::Value>& args) {

    isolate = args.GetIsolate();

    Local<Function> cb = Local<Function>::Cast(args[0]);
    callback = new Persistent<Function>(isolate, cb);

    StartReachabilityNotifier(Callback);
} 

Handle<Value> Initialize(Handle<Object> target)
{
    target->Set(String::NewFromUtf8(Isolate::GetCurrent(), "start"),
        FunctionTemplate::New(Isolate::GetCurrent(), Start)->GetFunction());

    target->Set(String::NewFromUtf8(Isolate::GetCurrent(), "stop"),
        FunctionTemplate::New(Isolate::GetCurrent(), Stop)->GetFunction());

    return True(Isolate::GetCurrent());
}

NODE_MODULE(osxreachability, Initialize);
